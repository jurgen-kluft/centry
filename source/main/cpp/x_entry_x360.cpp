//==============================================================================
// INCLUDES
//==============================================================================
#include "xbase\x_target.h"
#ifdef TARGET_360

#define NOGDI
#define NOMB
#define NOKANJI

#include "xbase\x_types.h"
#include "xbase\x_debug.h"

using namespace xcore;

extern int AppMain(xcore::s32 argc, const char** argv);
int __cdecl  main(int argc, char** argv)
{
	int retValue = 0;
	retValue = AppMain(argc, (const char**)argv);
    return retValue;
}

#endif