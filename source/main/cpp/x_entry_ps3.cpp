#include "xbase\x_target.h"
#ifdef TARGET_PS3

//////////////////////////////////////////////////////////////////////////
// Includes
//

#include "xbase\x_types.h"
#include "xbase\x_debug.h"
#include "xbase\x_console.h"

using namespace xcore;

extern int AppMain(xcore::s32 argc, const char** argv);
int main(int argc, char** argv)
{
	int retValue;
	retValue = AppMain(argc, (const char**)argv);
	return retValue;
}

#endif