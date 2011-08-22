#include "xbase\x_target.h"
#ifdef TARGET_WII

//////////////////////////////////////////////////////////////////////////
// Includes
//
#include "xbase\x_types.h"

using namespace xcore;

extern xcore::s32 AppMain(xcore::s32 argc, const char** argv);
void main(int argc, char** argv)
{
	AppMain(argc, (const char**)argv);
}

#endif
