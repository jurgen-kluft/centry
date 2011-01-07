#include "xbase\x_target.h"
#ifdef TARGET_PSP

//////////////////////////////////////////////////////////////////////////
// Includes
//
#include "xbase\x_types.h"
#include "xbase\x_debug.h"
#include "xbase\x_thread.h"
#include "xbase\x_base.h"
#include "xbase\x_console.h"
#include "xbase\x_system.h"

using namespace xcore;

extern int AppMain(xcore::s32 argc, const char** argv);
int main(int argc, char** argv)
{
	int retValue = 0;
	retValue = AppMain(argc, (const char**)argv);
	return retValue;
}

#endif