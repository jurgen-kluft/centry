#include "xbase/x_types.h"
#include "xbase/x_allocator.h"

#include "xunittest/xunittest.h"

using namespace xcore;

extern xcore::s32 AppMain(xcore::s32 argc, const char** argv);

UNITTEST_SUITE_BEGIN(appmain)
{
    UNITTEST_FIXTURE(main)
    {
        UNITTEST_FIXTURE_SETUP()
		{
		}

        UNITTEST_FIXTURE_TEARDOWN()
		{
		}

        UNITTEST_TEST(run)
        {
			const char* argv[] = { "" };
			xcore::s32 result = AppMain(0, (const char**)argv);
			CHECK_EQUAL(0, result);
        }

	}
}
UNITTEST_SUITE_END