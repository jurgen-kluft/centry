#include "cbase/x_types.h"
#include "cbase/x_allocator.h"

#include "cunittest/cunittest.h"

using namespace ncore;

extern ncore::s32 AppMain(ncore::s32 argc, const char** argv);

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
			ncore::s32 result = AppMain(0, (const char**)argv);
			CHECK_EQUAL(0, result);
        }

	}
}
UNITTEST_SUITE_END