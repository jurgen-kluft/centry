#ifdef TARGET_MAC

#include "centry/c_entry.h"

#ifdef TARGET_TEST
#define EntryMain			main2
#else
#define EntryMain			main
#endif

//---------------------------------------------------------------------------

extern int AppMain(int argc, const char** argv);


//---------------------------------------------------------------------------

int EntryMain(int argc, char** argv)
{
	return AppMain(argc, (const char**)argv);
}


#endif
