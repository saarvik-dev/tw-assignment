# Assignment 7: Source Code Documentation using Doxygen

## Topics Covered
- Purpose and workflow of automated code documentation
- Multi-file C++ project structure (`CalculationEngine.h`, `Logger.h`, `main.cpp`)
- Doxygen comment formats (`/** ... */` and `///`)
- Structural documentation tags (`@file`, `@class`, `@brief`, `@author`, `@version`)
- Function and parameter annotations (`@param`, `@return`, `@throw`, `@note`, `@warning`)
- Creating and configuring the `Doxyfile`
- Generating and navigating interactive HTML documentation
- Generating PDF manuals using Doxygen's LaTeX output (`refman.tex`)

## What I Learned
In this assignment, I learned how software engineering teams maintain up-to-date API documentation without writing separate manuals from scratch. By writing structured comments directly inside source code, Doxygen can automatically parse the code and produce both an interactive HTML website and a printable PDF reference manual.

I applied this to a multi-file C++ project comprising a computation engine (`CalculationEngine.h`), a logging utility (`Logger.h`), and a driver application (`main.cpp`). I learned the difference between file-level blocks (which must include `@file` for Doxygen to index the file), class documentation (`@class`), and function documentation.

For functions, I practiced documenting input parameters with direction flags (`@param[in]`, `@param[out]`), explaining expected return values with `@return`, and marking edge cases with `@note` and `@warning`.

I also learned how to generate a template configuration file using `doxygen -g Doxyfile` and modify key options: setting project name and version, pointing `INPUT` to source directories, enabling recursive scanning, and configuring output formats. Finally, I built the documentation, navigated the generated HTML hierarchy, and saw how Doxygen produces a LaTeX project that compiles into a complete technical reference manual (`refman.pdf`).

## Important Commands and Concepts

### Doxygen Comment Syntax and Tags
```cpp
/**
 * @file CalculationEngine.h
 * @brief Performs arithmetic and statistical operations.
 * @author Saarvik Singh Suryavanshi
 * @version 1.0
 */

/**
 * @class CalculationEngine
 * @brief Engine responsible for performing numerical calculations.
 */
class CalculationEngine {
public:
    /**
     * @brief Computes the division of two floating-point numbers.
     * @param[in] numerator The dividend value.
     * @param[in] denominator The divisor value.
     * @return The quotient result of numerator / denominator.
     * @warning Throws std::invalid_argument if denominator is zero.
     * @note Performance is O(1).
     */
    double divide(double numerator, double denominator);
};
```

### Essential `Doxyfile` Configuration Settings
To create a fresh configuration template:
```bash
doxygen -g Doxyfile
```

Important settings inside `Doxyfile`:
- `PROJECT_NAME = "CalculationEngine"`: Sets project title.
- `PROJECT_NUMBER = "1.0.0"`: Sets release version.
- `OUTPUT_DIRECTORY = ./docs`: Root directory for generated files.
- `INPUT = .`: Scans current working directory.
- `RECURSIVE = YES`: Scans subfolders recursively.
- `GENERATE_HTML = YES`: Builds searchable web pages in `html/`.
- `GENERATE_LATEX = YES`: Produces TeX source in `latex/`.

### Building the Documentation
1. Run Doxygen:
```bash
doxygen Doxyfile
```

2. View HTML Documentation:
Open `docs/html/index.html` in any web browser.

3. Compile PDF Manual from LaTeX output:
```bash
cd docs/latex
pdflatex refman.tex
```
This produces `refman.pdf` containing the complete formatted API manual.

