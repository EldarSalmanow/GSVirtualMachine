#ifndef GSVIRTUALMACHINE_GS_PLATFORMTYPES_H
#define GSVIRTUALMACHINE_GS_PLATFORMTYPES_H

#include "GS_PlatformDefines.h"

/**
 *
 */
typedef char GSChar;

/**
 *
 */
typedef bool GSBool;

#if defined(OS_WINDOWS)
#  if defined(COMPILER_MINGW)

    typedef long long GSLongNumber;

     /**
      *
      */
     typedef int GSNumber;

     /**
      *
      */
     typedef short GSShortNumber;

     /**
      *
      */
     typedef unsigned int GSUNumber;
#  endif
#endif

#endif //GSVIRTUALMACHINE_GS_PLATFORMTYPES_H
