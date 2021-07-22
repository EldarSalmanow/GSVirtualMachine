#ifndef GSVIRTUALMACHINE_GS_PLATFORMTYPES_H
#define GSVIRTUALMACHINE_GS_PLATFORMTYPES_H

#include <string>
#include <vector>

#include <CrossPlatform/GS_PlatformDefines.h>

/*
 * TODO write here
 */

#if defined(OS_WINDOWS)
    typedef void GSVoid;

    typedef bool GSBool;

    typedef char GSChar;

    typedef int GSInt;

    typedef short GSShort;

    typedef long GSLong;

    typedef float GSFloat;

    typedef double GSDouble;

    typedef signed GSSigned;

    typedef unsigned GSUnsigned;

    typedef unsigned long long GSULongLong;

    typedef unsigned char GSByte;

    typedef std::vector<GSByte> GSByteCode;

    typedef std::string GSString;
#endif

#endif //GSVIRTUALMACHINE_GS_PLATFORMTYPES_H
