#include "xbase\x_target.h"
#ifdef TARGET_N3DS

#include <nn.h>
#include <nn\os.h>

//////////////////////////////////////////////////////////////////////////
// Includes
//
#include "xbase\x_types.h"

extern int AppMain(xcore::s32 argc, const char** argv);
void nnMain( void )
{
	nn::os::Initialize();
    nn::fs::Initialize();
	xcore::s32 argc = 1;
	const char* argv[] = { "main" };
	AppMain(argc, (const char**)argv);
}

#endif
