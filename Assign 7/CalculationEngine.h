/**
 * @file CalculationEngine.h
 * @brief Declares a class for basic mathematical calculations.
 */
#ifndef CALCULATION_ENGINE_H
#define CALCULATION_ENGINE_H

#include "Logger.h"

/**
 * @class CalculationEngine
 * @brief Performs basic mathematical operations.
 *
 * @details The CalculationEngine class uses a Logger object to
 * report calculation results. It currently provides a power
 * calculation using a base and an exponent.
 */
class CalculationEngine {
private:
    Logger& logger;

public:
    /**
     * @brief Creates a calculation engine.
     * @param log A reference to the Logger used by the engine.
     */
    explicit CalculationEngine(Logger& log)
        : logger(log) {}

    /**
     * @brief Calculates the power of a number.
     * @param base The number to be raised to a power.
     * @param exponent The exponent applied to the base.
     * @return The result of base raised to exponent.
     * @todo Add handling for cases where the result may overflow.
     */
    double power(double base, double exponent) const {
        double result = 1.0;
        if (exponent < 0) {
            for (int i = 0; i < -exponent; ++i) result *= base;
            result = 1.0 / result;
        } else {
            for (int i = 0; i < exponent; ++i) result *= base;
        }
        logger.log(LogLevel::INFO, "Power calculation completed.");
        return result;
    }
};

#endif
