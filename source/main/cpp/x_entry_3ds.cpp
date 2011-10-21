#include "xbase\x_target.h"
#ifdef TARGET_3DS

#include <nn.h>
#include <nn\os.h>

//////////////////////////////////////////////////////////////////////////
// Includes
//
#include "xbase\x_types.h"

extern int AppMain(xcore::s32 argc, const char** argv);

#ifdef 	TARGET_TEST
int main2(int argc, char** argv)
{
	return AppMain(argc, (const char**)argv);
}
#else
void nnMain( void )
{
	nn::os::Initialize();
    	nn::fs::Initialize();
	xcore::s32 argc = 1;
	const char* argv[] = { "main" };
	AppMain(argc, (const char**)argv);
}
#endif

#endif
