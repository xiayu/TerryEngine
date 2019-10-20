#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Terry {
	class TR_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		// static variable belong to the class,not the object
		/*
		static成员变量需要在类定义体外进行初始化与定义，因为static数据成员独立该类的任意对象存在，它是与类关联的对象，不与类对象关联
		*/
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macros
#define TR_CORE_TRACE(...)      Terry::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TR_CORE_INFO(...)       Terry::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TR_CORE_WARN(...)       Terry::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TR_CORE_ERROR(...)      Terry::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TR_CORE_FATAL(...)      Terry::Log::GetCoreLogger()->fatal(__VA_ARGS__)
// client log macros
#define TR_TRACE(...)			Terry::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TR_INFO(...)			Terry::Log::GetClientLogger()->info(__VA_ARGS__)
#define TR_WARN(...)			Terry::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TR_ERROR(...)			Terry::Log::GetClientLogger()->error(__VA_ARGS__)
#define TR_FATAL(...)			Terry::Log::GetClientLogger()->fatal(__VA_ARGS__)


