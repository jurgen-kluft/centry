//==============================================================================
// INCLUDES
//==============================================================================
#include "xbase\x_target.h"
#ifdef TARGET_PC

#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define NOMB
#define NOKANJI
#include <windows.h>

#include "xbase\x_types.h"
#include "xbase\x_debug.h"

using namespace xcore;

extern int AppMain(xcore::s32 argc, const char** argv);
void main(int argc, char** argv)
{
	AppMain(argc, (const char**)argv);
}

#endif