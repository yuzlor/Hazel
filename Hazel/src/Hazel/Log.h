#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#include "Core.h"

namespace Hazel {

	class HAZEL_API Log
	{
	public:
		Log() {}
		~Log() {}

		static void Init();
		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
		static inline std::shared_ptr<spdlog::logger>& GetClienteLogger() { return m_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};

}

#define HZ_CORE_TRACE(...)		::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)		::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)		::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)		::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)		::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define HZ_TRACE(...)			::Hazel::Log::GetClienteLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)			::Hazel::Log::GetClienteLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)			::Hazel::Log::GetClienteLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)			::Hazel::Log::GetClienteLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)			::Hazel::Log::GetClienteLogger()->critical(__VA_ARGS__)