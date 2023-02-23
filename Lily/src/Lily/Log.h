#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Lily
{
	class LILY_API Log
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

//Core Log Macros

#define LY_CORE_TRACE(...)::Lily::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LY_CORE_INFO(...)::Lily::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LY_CORE_WARN(...)::Lily::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LY_CORE_ERROR(...)::Lily::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LY_CORE_FATAL(...)::Lily::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client Log Macros

#define LY_CORE_TRACE(...)::Lily::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LY_CORE_INFO(...)::Lily::Log::GetClientLogger()->info(__VA_ARGS__)
#define LY_CORE_WARN(...)::Lily::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LY_CORE_ERROR(...)::Lily::Log::GetClientLogger()->error(__VA_ARGS__)
#define LY_CORE_FATAL(...)::Lily::Log::GetClientLogger()->critical(__VA_ARGS__)