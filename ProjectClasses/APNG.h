/**
* @file APNG.h
* @brief Header file for APNG management.
*
* Provides classes and functions for reading and writing APNG image files.
*
* @section License
*
* Copyright (C) 2013 Robert B. Colton
* This file is part of wxENIGMA.
*
* wxENIGMA is free software: you can redistribute it and/or modify it under
* the terms of the GNU General Public License as published by the Free Software
* Foundation, version 3 of the License, or (at your option) any later version.
*
* wxENIGMA is distributed in the hope that it will be useful, but WITHOUT ANY
* WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
* PARTICULAR PURPOSE. See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with
* wxENIGMA. If not, see <http://www.gnu.org/licenses/>.
**/

#include <vector>
#include <fstream>
#include <wx/bitmap.h>
#include <wx/image.h>

static const char PNG_SIGNATURE[] = { (char) 0x89,'P','N','G',0x0D,0x0A,0x1A,0x0A };
static const char* IO_FMT = "png";


enum Dispose
{
  /**
  * No disposal is done on this frame before rendering the next;
  * the contents of the output buffer are left as-is.
  */
  NONE = 0,
  /**
  * The frame's region of the output buffer is to be cleared
  * to fully transparent black before rendering the next frame.
  */
  BACKGROUND,
  /**
  * The frame's region of the output buffer is to be reverted
  * to the previous contents before rendering the next frame.
  */
  PREVIOUS
};

enum Blend
{
  /**
  * All color components of the frame, including alpha, overwrite
  * the current contents of the frame's output buffer region.
  */
  SOURCE,
  /**
  * The frame should be composited onto the output buffer
  * based on its alpha, using a simple OVER operation
  * as described in the "Alpha Channel Processing" section
  * of the PNG specification [PNG-1.2].
  */
  OVER
};

class ApngIO
{
  public:

  //Convenience char[]/int methods
  private:
  static char bite(int i, int p)
  {
    return (char) (i >> p & 0xFF);
  }

  static char* i2b(int i)
  {
    return new char[] { bite(i,24),bite(i,16),bite(i,8),bite(i,0) };
  }

  /** Convenience method to fully read a buffer, since in.read(buf) can fall short. */
  static int readFully(ifstream& in, char* buffer)
  {
    readFully(in, buffer, 0, buffer.length);
  }

  static int readFully(ifstream& in, char* buffer, int off, int len)
  {
    int total = 0;
    while (true)
    {
      int n = in.read(buffer,off + total,len - total);
      if (n <= 0)
      {
        if (total == 0) total = n;
	break;
      }
      total += n;
      if (total == len) break;
    }
  }

  //Chunk classes
  class ChunkType
  {
    private:
    int val;
    char* data;

    public:
    ChunkType(char* chars)
    {
      val = charsToInt(data = chars);
    }

    char* getBytes()
    {
      return data;
    }

    static int charsToInt(char* b)
    {
      if (b.length != 4) throw new ArrayIndexOutOfBoundsException();
        return b[0] << 24 | b[1] << 16 | b[2] << 8 | b[3];
      }

    bool equals(ChunkType other)
    {
      return val == other.val;
    }
  };

  class PNG_Chunk
  {
    protected:
    int length = 0;
    ChunkType* chunkType;

    char* data;
    char* crc;

    public:
    PNG_Chunk(ChunkType* type)
    {
      chunkType = type;
    }

    void updateCRC()
    {
      CRC32 crc32 = new CRC32();
      crc32.update(chunkType->getBytes());
      crc32.update(data);
      int tcrc = (int) crc32.getValue();
      length = data->length;
      crc = i2b(tcrc);
    }

    virtual void repopulate();

    char* getBytes()
    { // Get the chars of this chunk for writing
      ByteArrayOutputStream baos = new ByteArrayOutputStream();
      try
      {
        baos.write(i2b(length));
        baos.write(chunkType->getBytes());
        baos.write(data);
        baos.write(crc);
      }
      catch (IOException e)
      {
        e.printStackTrace();
      }
      return baos.toByteArray();
    };

/*
    bool isType2(String t)
    {
      if (chunkType == NULL || t.length() != 4) return false;
        return chunkType[0] == t.charAt(0) && chunkType[1] == t.charAt(1)
          && chunkType[2] == t.charAt(2) && chunkType[3] == t.charAt(3);
    }
*/

    bool isType(ChunkType t)
    {
      return chunkType == NULL ? false : chunkType.equals(t);
    }

    bool read(ifstream& dis)
    {
      int b1 = dis.read();
      if (b1 == -1) return false;
      length = (b1 << 24) | (dis.read() << 16) | (dis.read() << 8) | dis.read();
      char* chunkTypeBytes = new char[4];
      readFully(dis,chunkTypeBytes);
      chunkType = new ChunkType(chunkTypeBytes);
      data = new char[length];
      readFully(dis,data);
      crc = new char[4];
      readFully(dis,crc);
      return true;
     }
  };

  class Generic_Chunk: public PNG_Chunk
  {
    public:
    Generic_Chunk() : PNG_Chunk(NULL)
    {
      super(NULL);
    }

    void repopulate()
    {
      System.err.println("Repopulate called on generic chunk.");
    }
  };

  class IHDR_Dummy: public PNG_Chunk
  {
    public:
    ChunkType* type = new ChunkType("IHDR");

    IHDR_Dummy(char* png) : PNG_Chunk(type)
    {
      super(type);
      char data[13];
      System.arraycopy(png,16,data,0,data.length);
      repopulate();
    }

    void repopulate()
    {
      updateCRC();
    }
  };

  class acTL: public PNG_Chunk
  {
    public:
    ChunkType* type = new ChunkType("acTL");

    int numFrames;
    int numPlays;

    acTL(int nf, int np) : PNG_Chunk(type)
    {
      super(type);
      numFrames = nf;
      numPlays = np;
      repopulate();
    }

    void repopulate()
    {
      char data[] = { bite(numFrames,24),bite(numFrames,16),bite(numFrames,8),
        bite(numFrames,0),bite(numPlays,24),bite(numPlays,16),bite(numPlays,8),bite(numPlays,0) };
      updateCRC();
    }
  };

  class fcTL: public PNG_Chunk
  {
    public:
    ChunkType* type = new ChunkType("fcTL");

    /** Sequence number of the animation chunk, 0-based */
    protected:
    int sequenceNumber;
    /** Width of the following frame */
    int width;
    /** Height of the following frame */
    int height;
    /** X position at which to render the following frame */
    int xOffset;
    /** Y position at which to render the following frame */
    int yOffset;
    /** Frame delay fraction numerator */
    short delayNum;
    /** Frame delay fraction denominator */
    short delayDen;
    /** Type of frame area disposal to be done after rendering this frame */
    Dispose disposeOp;
    /** Type of frame area rendering for this frame */
    Blend blendOp;

    public:
    fcTL(int sn, int w, int h, int xo, int yo, short dn, short dd, Dispose dop, Blend bop) : PNG_Chunk(type)
    {
      super(type);
      sequenceNumber = sn;
      width = w;
      height = h;
      xOffset = xo;
      yOffset = yo;
      delayNum = dn;
      delayDen = dd;
      disposeOp = dop;
      blendOp = bop;
      repopulate();
    }

    void repopulate()
    {
      char data[] = { bite(sequenceNumber,24),bite(sequenceNumber,16),bite(sequenceNumber,8),
        bite(sequenceNumber,0),bite(width,24),bite(width,16),bite(width,8),bite(width,0),
        bite(height,24),bite(height,16),bite(height,8),bite(height,0),bite(xOffset,24),
        bite(xOffset,16),bite(xOffset,8),bite(xOffset,0),bite(yOffset,24),bite(yOffset,16),
        bite(yOffset,8),bite(yOffset,0),bite(delayNum,8),bite(delayNum,0),bite(delayDen,8),
        bite(delayDen,0),disposeOp.getValue(),blendOp.getValue() };
      updateCRC();
    }
  };

  class IDAT: public PNG_Chunk
  {
    public:
    ChunkType* type = new ChunkType("IDAT");

    /** Creates a new IDAT chunk with the given frame data. */
    IDAT(char* dat)
    {
      super(type);
      data = dat;
      repopulate();
    }

    void repopulate()
    {
      updateCRC();
    }
  };

 class fdAT: public PNG_Chunk
  {
    public:
    ChunkType* type = new ChunkType("fdAT");

    protected:
    int sequenceNumber; // Sequence number, 0-based
    char* frameData[];

    /**
    * Creates an fdAT from a PNG_Chunk that is already in fdAT format.
    * Namely, it extracts the sequence number from the frame data.
    */
    public:
    fdAT(PNG_Chunk pc)  : PNG_Chunk(type)
    {
      super(pc.chunkType);
      length = pc.length;
      sequenceNumber = pc.data[0] << 24 | pc.data[1] << 16 | pc.data[2] << 8 | pc.data[3];
      char frameData[pc.data.length - 4]
      System.arraycopy(pc.data,4,frameData,0,frameData.length);
      crc = pc.crc;
    }

    /** Creates an fdAT from a PNG_Chunk that is in another format (converts it) */
    fdAT(PNG_Chunk src, int sn) : PNG_Chunk(type)
    {
      super(type);
      length = src.length;
      sequenceNumber = sn;
      frameData = src.data; //will just be arraycopy'd anyways
      repopulate();
    }

    void repopulate()
    {
      data = new char[frameData.length + 4];
      System.arraycopy(i2b(sequenceNumber),0,data,0,4);
      System.arraycopy(frameData,0,data,4,frameData.length);
      updateCRC();
    }

    IDAT toIDAT()
    {
      return new IDAT(frameData);
    }
  };

  class IEND: public PNG_Chunk
  {
    public:
    ChunkType* type = new ChunkType("IEND");
    IEND* instance = new IEND();

    /**
    * IEND is a singleton class and should not be instantiated.
    * Use IEND.instance instead.
    */
    private:
    IEND() : PNG_Chunk(type)
    {
      super(type);
      repopulate();
    }

    public:
    void repopulate()
    {
      data = new char[] {};
      updateCRC();
    }
  };

  //Functionality
  static int transferIDATs(ifstream& dis, ofstream& os, int sn, bool ignoreOthers)
  {
    Generic_Chunk* chunk = new Generic_Chunk();
    while (chunk.read(dis) && !chunk.isType(IEND.type))
    {
      if (chunk.isType(IDAT.type))
        os.write((sn == -1 ? chunk : new fdAT(chunk,sn)).getBytes());
      else if (!ignoreOthers) os.write(chunk->getBytes());
    }
  }

  public:
  static int imagesToApng(vector<wxBitmap*> imgs, ofstream& fullFile)
  {
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    ImageIO.write(imgs.get(0),IO_FMT,baos);
    char buf[] = baos.toByteArray();
    IHDR_Dummy* myhdr = new IHDR_Dummy(buf);
    acTL* myactl = new acTL(imgs.size(),0);
    fcTL* fctl = new fcTL(0,imgs.get(0).getWidth(),imgs.get(0).getHeight(),0,0,(short) 1,(short) 30,
    fcTL.Dispose.BACKGROUND,fcTL.Blend.OVER);

    fullFile.write(PNG_SIGNATURE);
    fullFile.write(myhdr->getBytes());
    fullFile.write(myactl->getBytes());
    fullFile.write(fctl->getBytes());

    //Transfer the IDAT chunks
    ByteArrayInputStream bais = new ByteArrayInputStream(buf);
    bais.skip(8);
    transferIDATs(bais,fullFile,-1,true);

    int indx = -1;
    for (vector<wxBitmap>::iterator bi = imgs.begin(); bi != imgs.end(); ++bi)
    {
      if (indx++ == -1) // Continues once to skip the first image;
      continue; // index will be 1 on first iteration

      baos.reset(); // Clear our buffer,
      ImageIO.write(bi,IO_FMT,baos); // Fetch new image.

      // Create the frame control. IDs will be 2, 4, 6, 8...
      fctl = new fcTL(indx++,bi->getWidth(),bi->getHeight(),0,0,(short) 1,(short) 30,
        fcTL.Dispose.BACKGROUND,fcTL.Blend.OVER);
      fullFile.write(fctl.getBytes()); // Write it into the file

      // Now make our frame data. IDs will be 3, 5, 7, 9...
      buf= baos.toByteArray();
      bais = new ByteArrayInputStream(buf);
      bais.skip(8);
      transferIDATs(bais,fullFile,indx,true);
    }
    fullFile.write(IEND.instance.getBytes());
  }

  static vector<wxBitmap> apngTowxBitmaps(ifstream& is)
  {
    PNG_Chunk genChunk = new Generic_Chunk();
    ByteArrayOutputStream png = new ByteArrayOutputStream();
    vector<wxBitmap> ret = new vector<wxBitmap>();
    char* imageHeader[] = NULL;
    try
    {
      png.write(PNG_SIGNATURE);
      char pngBase[] = new char[8];

      is.read(pngBase);
      if (!Arrays.equals(pngBase,PNG_SIGNATURE)) return -1;

      bool hasData = false;

      while (genChunk.read(is))
      {

        if (genChunk.isType(acTL.type))
        {
          //Look at all the fucks I give
        }
        else if (genChunk.isType(fcTL.type))
        {
          if (hasData)
          {
            png.write(IEND.instance.getBytes());
            ByteArrayInputStream bais = new ByteArrayInputStream(png.toByteArray());
            ret.add(ImageIO.read(bais));

            png.reset();
            png.write(pngBase);
            png.write(imageHeader);
            hasData = false;
          }
        }
        else if (genChunk.isType(IDAT.type))
        {
          png.write(genChunk.getBytes());
          hasData = true;
        }
        else if (genChunk.isType(fdAT.type))
        {
          char a[] = new fdAT(genChunk).toIDAT().getBytes();
          png.write(a);
          hasData = true;
        }
        else if (genChunk.isType(IEND.type))
        {
          png.write(genChunk.getBytes());
          ByteArrayInputStream bais = new ByteArrayInputStream(png.toByteArray());
          ret.add(ImageIO.read(bais));
          break;
        }
        else if (genChunk.isType(IHDR_Dummy.type)) {
          //save the image header as it is used for all subimages
          imageHeader = genChunk.getBytes();
          png.write(imageHeader);
        }
        else
        {
          png.write(genChunk.getBytes());
          //Uncomment this if we want to include these chunks with every png
          //Otherwise, keep commented to only include with current png
          //	pngBase = png.toByteArray();
        }
      }
    }
    catch (IOException e)
    {
      e.printStackTrace();
    }
    return ret;
  }
};
