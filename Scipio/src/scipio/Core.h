#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SCIPIO_API __declspec(dllexport)
	#else
		#define SCIPIO_API __declspec(dllimport)
	#endif
#else
	#error Scipio only supports Windows
#endif
