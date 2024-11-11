#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Scipio {
	class SCIPIO_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
	
}

//Core logging macros
#define SP_CORE_TRACE(...) ::Scipio::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_INFO(...) ::Scipio::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SP_CORE_WARN(...) ::Scipio::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...) ::Scipio::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_FATAL(...) ::Scipio::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client logging macros
#define SP_TRACE(...) ::Scipio::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SP_INFO(...) ::Scipio::Log::GetClientLogger()->info(__VA_ARGS__)
#define SP_WARN(...) ::Scipio::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_ERROR(...) ::Scipio::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_FATAL(...) ::Scipio::Log::GetClientLogger()->fatal(__VA_ARGS__)

