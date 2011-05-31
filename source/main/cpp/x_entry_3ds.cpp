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
	AppMain(argc, (const char**)argv);
}

#endif
