#include "ENIGMAlink.h"

int dummy_compileEGMf(EnigmaStruct *es, const char* exe_filename, int mode)
{
    // show error
    return -1;
}

const char* dummy_next_available_resource()
{
    // show error
    return NULL;
}

const char* dummy_first_available_resource()
{
    // show error
    return NULL;
}

bool dummy_resource_isFunction()
{
    // show error
    return false;
}

int dummy_resource_argCountMin()
{
    // show error
    return 0;
}

int dummy_resource_argCountMax()
{
    // show error
    return 0;
}

int dummy_resource_overloadCount()
{
    // show error
    return 0;
}

const char* dummy_resource_parameters(int i)
{
    // show error
    return "()";
}

int dummy_resource_isTypeName()
{
    // show error
    return false;
}

int dummy_resource_isGlobal()
{
    // show error
    return false;
}

bool dummy_resources_atEnd()
{
    // show error
    return true;
}

const char* dummy_libInit(EnigmaCallbacks* ecs)
{
    // show error
    return "";
}

void dummy_libFree()
{
    // show error
}

syntax_error dummy_syerr;
syntax_error *dummy_definitionsModified(const char* wscode, const char* targetYaml)
{
    // show error
    return &dummy_syerr;
}

syntax_error *dummy_syntaxCheck(int script_count, const char* *script_names, const char* code)
{
    // show error
    return &dummy_syerr;
}

int (*compileEGMf)(EnigmaStruct *es, const char* exe_filename, int mode) = dummy_compileEGMf;
const char* (*next_available_resource)() = dummy_next_available_resource;
const char* (*first_available_resource)() = dummy_first_available_resource;
bool (*resource_isFunction)() = dummy_resource_isFunction;
int (*resource_argCountMin)() = dummy_resource_argCountMin;
int (*resource_argCountMax)() = dummy_resource_argCountMax;
int (*resource_overloadCount)() = dummy_resource_overloadCount;
const char* (*resource_parameters)(int i) = dummy_resource_parameters;
int (*resource_isTypeName)() = dummy_resource_isTypeName;
int (*resource_isGlobal)() = dummy_resource_isGlobal;
bool (*resources_atEnd)() = dummy_resources_atEnd;
const char* (*libInit)(EnigmaCallbacks* ecs) = dummy_libInit;
void (*libFree)() = dummy_libFree;
syntax_error *(*definitionsModified)(const char* wscode, const char* targetYaml) = dummy_definitionsModified;
syntax_error *(*syntaxCheck)(int script_count, const char* *script_names, const char* code) = dummy_syntaxCheck;
