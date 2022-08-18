#include "cbase/x_types.h"
#include "cunittest/cunittest.h"

#include "centry/x_entry.h"
#include "centry/x_entry_calls.h"

ncore::s32 AppMain(ncore::s32 argc, const char** argv)
{

	return argc;
}

UNITTEST_SUITE_BEGIN(entry)
{
    UNITTEST_FIXTURE(main)
    {
        UNITTEST_FIXTURE_SETUP() 
		{
		}

        UNITTEST_FIXTURE_TEARDOWN()
		{
		}

#ifdef TARGET_PC
		UNITTEST_TEST(test_main)
		{
			int argc = 2;
			const char* argv[2]=
			{
				"test.exe",
				"-help"
			};
			int r = main2(argc, (char**)argv);
			CHECK_EQUAL(r, argc);

			ncore::x_WinParams wp;
			bool isWinApp = ncore::x_GetWinParams(wp);
			CHECK_FALSE(isWinApp);
		}

		UNITTEST_TEST(test_winmain)
		{
			int argc = 2;
			const char* argv[2]=
			{
				"test.exe",
				"-help"
			};

			char* cmdLine = "-help";
			int r = WinMain2((HINSTANCE)1, (HINSTANCE)2, cmdLine, 1);
			CHECK_EQUAL(argc, r);

			ncore::x_WinParams wp;
			bool isWinApp = ncore::x_GetWinParams(wp);
			CHECK_TRUE(isWinApp);
		}
#endif
	}
}
UNITTEST_SUITE_END
