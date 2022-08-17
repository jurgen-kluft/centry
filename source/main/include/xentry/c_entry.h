/**
 *  x_entry.h
 */
#ifndef __XENTRY_ENTRY_H__
#define __XENTRY_ENTRY_H__

#ifdef USE_PRAGMA_ONCE
#pragma once
#endif

/**
 * xCore namespace
 */
namespace xcore
{
#ifdef TARGET_PC
	struct WinParams
	{
		void*		hInstance;
		void*		hPrevInstance;
		char*		lpCmdLine;
		int			nCmdShow;
	};

	///< Returns True when the applications is a Win32 Windows application
	///< Returns False if the application is a Win32 Console application
	extern bool		GetWinParams(WinParams& outParams);
#endif
};

#endif	/// __XENTRY_ENTRY_H__
