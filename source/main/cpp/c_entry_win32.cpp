#ifdef TARGET_PC
#include <windows.h>
#include "centry/c_entry.h"

static bool	sIsWinApp = false;
static ncore::WinParams	sWinParams;

#ifdef TARGET_TEST
#define WinEntryMain		WinMain2
#define EntryMain			main2
#else
#define WinEntryMain		WinMain
#define EntryMain			main
#endif

//---------------------------------------------------------------------------

extern int AppMain(int argc, const char** argv);


//---------------------------------------------------------------------------

int EntryMain(int argc, char** argv)
{
	sIsWinApp = false;

	sWinParams.hInstance = nullptr;
	sWinParams.hPrevInstance = nullptr;
	sWinParams.lpCmdLine = nullptr;
	sWinParams.nCmdShow = 0;

	return AppMain(argc, (const char**)argv);
}


namespace centry
{

	//---------------------------------------------------------------------------

	struct WinCmdLine
	{
		char*			mCmdLine;
		int				mArgC;
		const char**	mArgV;
		char			mFilename[_MAX_PATH];

		void			Parse(LPSTR lpCmdLine);
		void			Destroy();
	};

	void WinCmdLine::Parse(LPSTR lpCmdLine)
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

		int const cmdLineLen = (int)(arg - lpCmdLine);
		mCmdLine = (char*)lpCmdLine;

		/// parse the arguments
		char** argv = (char**)malloc(argc * sizeof(char*));

		arg = mCmdLine;
		int index = 1;

		while (argv != nullptr && arg[0] != 0 && index < argc)
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

		if (mArgV != nullptr)
		{	// put the program name into argv[0]
			GetModuleFileName(nullptr, mFilename, _MAX_PATH);
			mArgV[0] = mFilename;
		}
	}

	void WinCmdLine::Destroy()
	{
		free(mCmdLine);
		free(mArgV);
	}
}

INT WINAPI WinEntryMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	sIsWinApp = true;

	sWinParams.hInstance = hInstance;
	sWinParams.hPrevInstance = hPrevInstance;
	sWinParams.lpCmdLine = lpCmdLine;
	sWinParams.nCmdShow = nCmdShow;

	centry::WinCmdLine arg;
	arg.Parse(lpCmdLine);
	int r = AppMain(arg.mArgC, arg.mArgV);
	arg.Destroy();
	return r;
}

namespace ncore
{
	bool		GetWinParams(WinParams& outParams)
	{
		outParams = sWinParams;
		return sIsWinApp;
	}
}

#endif
