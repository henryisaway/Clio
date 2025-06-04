#pragma once

#include <iostream>
#include <mutex>
#include <sstream>
#include <string>

namespace Clio {

    // --- Importance level ---
    /*
    Used only to organise the level of importance of a log message.
    Doesn't actually change anything in the implementation itself, only
    the output displays the message a different colour.
    */
    enum class Severity {
        INFO,
        WARN,
        ERROR,
        FATAL
    };

    // --- Logger class ---
    /*
    Singleton class that handles all logging functionality.
    */
    class Logger {
    private:
        std::mutex mtx;

        Logger() = default;

        inline const char* severityToString(Severity severity) const {
            switch(severity) {
            case Severity::INFO: return "INFO";
            case Severity::WARN: return "WARN";
            case Severity::ERROR: return "ERROR";
            case Severity::FATAL: return "FATAL";
            default: return "UNKNOWN";
            }
        }

    public:
        static Logger& get() {
            static Logger instance;
            return instance;
        }

        // Template needed to handle different string types
        template<typename... Args>
        inline void log(Severity severity, const char* file, const int line, const Args&... args) {
            std::lock_guard<std::mutex> lock(mtx);      // Basic thread-safety

            std::ostringstream oss;
            (oss << ... << args);

            std::cout << "[" << severityToString(severity) << "] "
                << "[" << file << ":" << line << "] "
                << oss.str() << "\n";
        }
    };
}

// --- Macro definitions ---
#define CLIO_INFO(...) Clio::Logger::get().log(Clio::Severity::INFO, __FILE__, __LINE__, __VA_ARGS__)
#define CLIO_WARN(...) Clio::Logger::get().log(Clio::Severity::WARN, __FILE__, __LINE__, __VA_ARGS__)
#define CLIO_ERROR(...) Clio::Logger::get().log(Clio::Severity::ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define CLIO_FATAL(...) Clio::Logger::get().log(Clio::Severity::FATAL, __FILE__, __LINE__, __VA_ARGS__)