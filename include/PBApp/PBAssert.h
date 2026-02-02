#pragma once

#include <source_location>
#include <string>
#include <iostream>
#include <stacktrace>

inline void dumpStackTrace(unsigned int maxFrames = 64, decltype(std::stacktrace::current()) stack = std::stacktrace::current()) {
    for (int i = 1; i < (stack.size() > maxFrames ? maxFrames : stack.size()); ++i) {
        std::cerr << i - 1 << ") " << stack[i] << '\n';
    }
}

inline void pb_assert(bool condition, const char* expr, std::string errorMessage, std::source_location source, const char* manualFunctionName = nullptr) {
    if (condition) return;

    const char* functionName = (manualFunctionName) ? manualFunctionName : source.function_name();

    std::cerr << "PBApp assert [" << expr << "] failed in " << functionName << " (" << source.file_name() << ":" << source.line() << "): " << errorMessage << '\n';
    
    dumpStackTrace();

    std::abort();
}

#ifndef NDEBUG
    // Clang __PRETTY_FUNCTION__ looks better than std::source_location::function_name()
    #define PBAPP_ASSERT(expr, errorMessage) \
        pb_assert((expr), #expr, (errorMessage), std::source_location::current(), __PRETTY_FUNCTION__)
#else
    #define PBAPP_ASSERT(expr, errorMessage)
#endif
