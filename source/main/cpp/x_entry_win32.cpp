//==============================================================================
// INCLUDES
//==============================================================================
#include "xbase\x_target.h"
#ifdef TARGET_PC

#include "xbase\x_types.h"

using namespace xcore;

extern int AppMain(xcore::s32 argc, const char** argv);
void main(int argc, char** argv)
{
	AppMain(argc, (const char**)argv);
}

#endif