/**
 * @file Logger.h
 * @brief Declares a simple logging utility.
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

/**
 * @enum LogLevel
 * @brief Defines the available logging levels.
 */
enum class LogLevel {
    DEBUG,   /**< Detailed information useful during debugging. */
    INFO,    /**< General information about program execution. */
    WARNING, /**< Indicates a condition that may need attention. */
    ERROR    /**< Indicates an error during execution. */
};

/**
 * @class Logger
 * @brief Writes messages to the standard output stream.
 *
 * The Logger class provides a small interface for displaying
 * messages with a selected logging level.
 */
class Logger {
private:
    LogLevel minimumLevel;

public:
    /**
     * @brief Creates a Logger with the given minimum log level.
     * @param level The minimum level of messages to display.
     */
    explicit Logger(LogLevel level = LogLevel::INFO)
        : minimumLevel(level) {}

    /**
     * @brief Displays a log message if its level is permitted.
     * @param level The level of the message.
     * @param message The text to display.
     */
    void log(LogLevel level, const std::string& message) const {
        if (static_cast<int>(level) >= static_cast<int>(minimumLevel)) {
            std::cout << message << std::endl;
        }
    }
};

#endif
