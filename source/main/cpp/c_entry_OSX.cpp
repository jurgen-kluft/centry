//==============================================================================
// INCLUDES
//==============================================================================
#ifdef TARGET_MAC

#include "xentry/x_entry.h"

#ifdef TARGET_TEST
#define xMain			main2
#else
#define xMain			main
#endif

//---------------------------------------------------------------------------

extern int AppMain(int argc, const char** argv);


//---------------------------------------------------------------------------

int xMain(int argc, char** argv)
{
	return AppMain(argc, (const char**)argv);
}


#endif
