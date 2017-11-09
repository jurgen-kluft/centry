#include "xbase/x_types.h"
#include "xunittest/xunittest.h"

#include "xentry/x_entry.h"
#include "xentry/x_entry_calls.h"

xcore::s32 AppMain(xcore::s32 argc, const char** argv)
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

			xcore::x_WinParams wp;
			bool isWinApp = xcore::x_GetWinParams(wp);
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

			xcore::x_WinParams wp;
			bool isWinApp = xcore::x_GetWinParams(wp);
			CHECK_TRUE(isWinApp);
		}
#endif
	}
}
UNITTEST_SUITE_END
