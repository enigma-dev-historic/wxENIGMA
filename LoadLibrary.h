#ifndef LOADLIBRARY_H_INCLUDED
#define LOADLIBRARY_H_INCLUDED

#include <dlfcn.h>
#include <string>
using namespace std;

#include "ENIGMA_IDEMain.h"
#include "enigma/CompilerSource/OS_Switchboard.h"

typedef void(*GenericFunction)();
void* LoadPluginLib(ENIGMA_IDEFrame* frame);
void* FreePluginLib();
GenericFunction LoadPluginFnc(void *library, string funcname);

#endif // LOADLIBRARY_H_INCLUDED
