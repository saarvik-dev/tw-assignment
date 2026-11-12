/**
 * @file main.cpp
 * @brief Entry point of the calculation engine application.
 *
 * @mainpage Calculation Engine
 *
 * This project demonstrates a small C++ application with a
 * Logger class and a CalculationEngine class.
 * The Logger displays messages, while CalculationEngine
 * performs a power calculation using a base and exponent.
 */
#include "Logger.h"
#include "CalculationEngine.h"
#include <iostream>

/**
 * @brief Runs the calculation engine example.
 * @return 0 when the program finishes successfully.
 */
int main() {
    Logger logger(LogLevel::INFO);
    CalculationEngine engine(logger);
    double base = 2.0;
    double exponent = 3.0;
    double result = engine.power(base, exponent);
    std::cout << base << " raised to " << exponent
              << " = " << result << std::endl;
    return 0;
}
