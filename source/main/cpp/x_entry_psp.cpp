#include "..\x_target.h"
#ifdef TARGET_PSP

//////////////////////////////////////////////////////////////////////////
// Includes
//
#include <moduleexport.h>

#include "../x_types.h"
#include "../x_debug.h"
#include "../x_thread.h"
#include "../x_base.h"
#include "../x_console.h"
#include "../x_system.h"

using namespace xcore;

SCE_MODULE_INFO(MJPSP, 1, 0, 0);

extern int AppMain(xcore::s32 argc, const char** argv);
int main(int argc, char** argv)
{
	int retValue = 0;

	xcore::xsystem::ESystemFlags systemflags = xcore::xsystem::MODE_DEFAULT;
#ifndef TARGET_FINAL
	const xcore::u32 cmdCount = 2;
	const char* cmdline[cmdCount] = {"-dev", "-mem64"};

#else
	const xcore::u32 cmdCount = 1;
	const char* cmdline = "-final";
#endif
	systemflags = xcore::xsystem::ParseSystemFlags(systemflags, cmdCount, (const char**)&cmdline);

	xcore::xsystem::Initialise(argc>0 ? argv[0] : "Application", systemflags);

	xcore::xbase::Initialise();
	{
		xlog::init();
		retValue = AppMain(argc, (const char**)argv);
		xlog::shutdown();
	}
	xcore::xbase::Shutdown(); 
	xcore::xsystem::Shutdown(); 

	return retValue;
}

#endif