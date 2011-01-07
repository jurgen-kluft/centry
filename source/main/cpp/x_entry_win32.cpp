//==============================================================================
// INCLUDES
//==============================================================================
#include "../x_target.h"
#ifdef TARGET_PC

#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define NOMB
#define NOKANJI
#include <windows.h>

#include "../x_types.h"
#include "../x_debug.h"
#include "../x_thread.h"
#include "../x_base.h"
#include "../x_console.h"
#include "../x_log.h"
#include "../x_system.h"

using namespace xcore;

extern int AppMain(xcore::s32 argc, const char** argv);
void main(int argc, char** argv)
{
	xcore::xsystem::ESystemFlags systemflags = xcore::xsystem::MODE_DEFAULT;
#ifndef TARGET_FINAL
	const char* cmdline = "-dev";
#else
	const char* cmdline = "-final";
#endif
	systemflags = xcore::xsystem::ParseSystemFlags(systemflags, 1, (const char**)&cmdline);
	xcore::xsystem::Initialise(argc>0 ? argv[0] : "Application", systemflags);
	
	xcore::xbase::Initialise();
	{
		xlog::init();

		X_MEM_TRACK_STATE_BEGIN("Before AppMain");
			AppMain(argc, (const char**)argv);
		X_MEM_TRACK_STATE_END();

		xlog::shutdown();
	}
	xcore::xbase::Shutdown(); 
	xcore::xsystem::Shutdown();
}



#endif