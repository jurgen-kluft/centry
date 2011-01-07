#include "..\x_target.h"
#ifdef TARGET_WII

//////////////////////////////////////////////////////////////////////////
// Includes
//
#include "../x_types.h"
#include "../x_debug.h"
#include "../x_thread.h"
#include "../x_base.h"
#include "../x_system.h"
#include "../x_console.h"

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

	while (true)
	{
		xcore::xsystem::Initialise(argc>0 ? argv[0] : "Application", systemflags);

		xcore::xbase::Initialise();
		{
			xlog::init();
			AppMain(argc, (const char**)argv);
			xlog::shutdown();
		}
		xcore::xbase::Shutdown(); 
		xcore::xsystem::Shutdown();

		if (xcore::xsystem::HasBeenReset() == false)
			break;
	}
}

#endif