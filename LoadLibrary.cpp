#include "LoadLibrary.h"
#include "ENIGMAlink.h"

#include <cstring>
#include <cstdio>
using namespace std;

#include <wx/msgdlg.h>

ENIGMA_IDEFrame* enigmaFrame;
static void outputText(const char* text) { enigmaFrame->OutputLine(text); }

#if CURRENT_PLATFORM_ID == OS_WINDOWS
void* LoadPluginLib(ENIGMA_IDEFrame* frame)
{

}
#else
void* LoadPluginLib(ENIGMA_IDEFrame* frame)
{

    #if CURRENT_PLATFORM_ID == OS_MAC
    string extension = ".dylib";
    #else
    string extension = ".so";
    #endif

    void *handle = dlopen(("enigma/libcompileEGMf" + extension).c_str(), RTLD_NOW | RTLD_GLOBAL);

    libInit = (const char* (*)(EnigmaCallbacks*)) LoadPluginFnc(handle, "libInit");
    compileEGMf = (int (*)(EnigmaStruct *es, const char* exe_filename, int mode)) LoadPluginFnc(handle, "compileEGMf");
    EnigmaCallbacks ecb;
    ecb.dia_add = outputText;
    libInit(&ecb);
    //EnigmaStruct est;
    //compileEGMf(&est, "test", 0);
    enigmaFrame = frame;
    enigmaFrame->OutputLine("test");

    //ENIGMA_IDEFrame::OutputLine("test");

    return handle;
}

GenericFunction LoadPluginFnc(void *library, string funcname)
{
    return (GenericFunction)dlsym(library, funcname.c_str());
}
#endif
