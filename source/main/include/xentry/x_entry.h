/**
 *  x_entry.h
 */
#ifndef __XENTRY_ENTRY_H__
#define __XENTRY_ENTRY_H__
#include "xbase\x_target.h"
#ifdef USE_PRAGMA_ONCE 
#pragma once 
#endif

#include "xbase\x_types.h"

/**
 * xCore namespace
 */
namespace xcore
{
#ifdef TARGET_PC
	struct x_WinParams
	{
		void*		hInstance;
		void*		hPrevInstance;
		char*		lpCmdLine;
		int			nCmdShow;
	};

	///< Returns True when the applications is a Win32 Windows application
	///< Returns False if the application is a Win32 Console application
	extern bool		x_GetWinParams(x_WinParams& outParams);
#endif
};

#endif	/// __XENTRY_ENTRY_H__