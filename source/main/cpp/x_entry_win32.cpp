//==============================================================================
// INCLUDES
//==============================================================================
#include "xbase\x_target.h"
#ifdef TARGET_PC
#include <windows.h>

#include "xbase\x_types.h"
#include "xbase\x_string_std.h"

#include "xentry\x_entry.h"

using namespace xcore;

static bool	sIsWinApp = false;
static x_WinParams	sWinParams;

#ifdef TARGET_TEST
#define xWinMain		WinMain2
#define xMain			main2
#else
#define xWinMain		WinMain
#define xMain			main
#endif

//---------------------------------------------------------------------------

extern xcore::s32 AppMain(xcore::s32 argc, const char** argv);


//---------------------------------------------------------------------------

int xMain(int argc, char** argv)
{
	sIsWinApp = false;

	sWinParams.hInstance = NULL;
	sWinParams.hPrevInstance = NULL;
	sWinParams.lpCmdLine = NULL;
	sWinParams.nCmdShow = 0;

	return AppMain(argc, (const char**)argv);
}


namespace xentry
{

	//---------------------------------------------------------------------------

	struct x_WinCmdLine
	{
		char*			mCmdLine;
		int				mArgC;
		const char**	mArgV;
		char			mFilename[_MAX_PATH];

		void			Parse(LPSTR lpCmdLine);
		void			Destroy();
	};

	void x_WinCmdLine::Parse(LPSTR lpCmdLine)
	{
		// count the arguments
		int argc = 1;
		char* arg = lpCmdLine;

		while (arg[0] != 0)
		{
			while (arg[0] != 0 && arg[0] == ' ')
				arg++;

			if (arg[0] != 0)
			{
				argc++;
				while (arg[0] != 0 && arg[0] != ' ')
					arg++;
			}
		}    

		int const cmdLineLen = arg - lpCmdLine;
		mCmdLine = (char*)malloc(cmdLineLen);
		x_strcpy(mCmdLine, cmdLineLen, lpCmdLine);

		// parse the arguments
		char** argv = (char**)malloc(argc * sizeof(char*));

		arg = mCmdLine;
		int index = 1;

		while (arg[0] != 0)
		{
			while (arg[0] != 0 && arg[0] == ' ')
				arg++;

			if (arg[0] != 0)
			{
				argv[index] = arg;
				index++;

				while (arg[0] != 0 && arg[0] != ' ')
					arg++;

				if (arg[0] != 0)
				{
					arg[0] = 0;    
					arg++;
				}
			}
		}

		mArgC = argc;
		mArgV = (const char**)argv;

		// put the program name into argv[0]
		GetModuleFileName(NULL, mFilename, _MAX_PATH);
		argv[0] = mFilename;
	}

	void x_WinCmdLine::Destroy()
	{
		free(mCmdLine);
		free(mArgV);
	}
}

INT WINAPI xWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	sIsWinApp = true;

	sWinParams.hInstance = hInstance;
	sWinParams.hPrevInstance = hPrevInstance;
	sWinParams.lpCmdLine = lpCmdLine;
	sWinParams.nCmdShow = nCmdShow;

	xentry::x_WinCmdLine arg;
	arg.Parse(lpCmdLine);
	int r = AppMain(arg.mArgC, arg.mArgV);
	arg.Destroy();
	return r;
}

namespace xcore
{
	bool		x_GetWinParams(x_WinParams& outParams)
	{
		outParams = sWinParams;
		return sIsWinApp;
	}
}

#endif