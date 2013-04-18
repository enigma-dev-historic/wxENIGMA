

struct ResourceRepresentation {
  virtual void Save() = 0; ///< Saves the file, updating it on disk if applicable
  virtual void Rename() = 0; ///< Renames the file, or changes its name in memory
  virtual char* GetData() = 0; ///< Returns the complete data for this resource, pre-serialized
  virtual ~ResourceRepresentation();
};

struct ResourceFromPath: ResourceRepresentation {
  wxString path;
  ResourceFromPath(wxString pth): path(pth) {}

  void Save() {
    // Write shit to file directly
  }
};

struct ResourceInArchive: ResourceRepresentation {
  wxString archive;
  wxString path;
  ResourceInArchive(wxString arch, wxString pth): archive(arch), path(pth) {}
  void Save() {
    // Write shit to archive using libzip
    // Note: that library *should* provide the functionality to man
    // this seems easy to understand go
  }
};

struct ResourceInMemory: ResourceRepresentation {
  void Save() {
    // this just updates shit in memory; nothing happens yet.
  }
};

