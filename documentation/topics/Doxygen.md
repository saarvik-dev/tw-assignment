# Doxygen: Automated Code Documentation

Doxygen is an open-source documentation generator for programming languages such as C++, C, Java, and Python. In software development, writing separate technical manuals in Word or LaTeX often leads to out-of-date documentation as the codebase evolves. Doxygen solves this by extracting documentation directly from specially formatted comments placed alongside class definitions, member functions, and variables in the source files.

From these comments, Doxygen automatically builds an interactive, cross-referenced HTML website as well as a printable LaTeX/PDF reference manual.

---

## 1. Documentation Comment Styles

Doxygen recognizes several comment conventions in C and C++:

### Multi-Line Javadoc / C-Style Blocks
The most common format starts with an extra asterisk (`/**`):
```cpp
/**
 * @brief Brief description of the class or function.
 *
 * Detailed explanation providing context, design notes,
 * and edge cases.
 */
```

### Single-Line Triple Slash (`///`)
Useful for concise descriptions above short functions or variables:
```cpp
/// @brief Returns the absolute value of an integer.
int absolute(int x);
```

### Trailing Member Comments (`/**< ... */` or `///<`)
Placed on the same line after a variable, enum value, or struct field:
```cpp
enum class LogLevel {
    DEBUG,   /**< Detailed information useful during debugging. */
    INFO,    /**< General information about program execution. */
    WARNING, /**< Indicates a condition that may need attention. */
    ERROR    /**< Indicates an error during execution. */
};
```

---

## 2. Structural Documentation Tags

Doxygen uses tags prefixed with either an at-sign (`@tag`) or a backslash (`\tag`).

### File-Level Documentation
For Doxygen to document global functions, enums, or include a file in the generated file index, the file must contain an `@file` tag at the top:

```cpp
/**
 * @file CalculationEngine.h
 * @brief Declares a class for basic mathematical calculations.
 * @author Saarvik Singh Suryavanshi
 * @version 1.0
 */
```
If `@file` is omitted, Doxygen ignores all file-level and non-member declarations in that file.

### Class and Enum Documentation
```cpp
/**
 * @class CalculationEngine
 * @brief Performs basic mathematical operations.
 *
 * @details The CalculationEngine class uses a Logger object to
 * report calculation results. It currently provides a power
 * calculation using a base and an exponent.
 */
class CalculationEngine { ... };
```
- `@class Name`: Explicitly links the comment to the class (often inferred automatically if placed directly above `class Name`).
- `@details`: Separates the initial brief summary from the extended technical description.
- `@enum Name`: Documents an enumerated type.

### Function and Method Documentation
Functions are documented with tags explaining inputs, outputs, and failure conditions:

```cpp
/**
 * @brief Calculates the power of a number.
 * @param base The number to be raised to a power.
 * @param exponent The exponent applied to the base.
 * @return The result of base raised to exponent.
 * @todo Add handling for cases where the result may overflow.
 */
double power(double base, double exponent) const;
```

---

## 3. Important Doxygen Tags Reference

| Tag | Purpose | Example |
| :--- | :--- | :--- |
| `@file` | Identifies the source or header file | `@file Logger.h` |
| `@brief` | Single-sentence summary | `@brief Formats output messages` |
| `@details` | In-depth paragraph explanation | `@details Thread-safe implementation...` |
| `@class` | Documents a class | `@class Logger` |
| `@param` | Documents a parameter (can include `[in]`, `[out]`, `[in,out]`) | `@param[in] log A reference to Logger` |
| `@return` | Documents the returned value | `@return True if operation succeeded` |
| `@throw` / `@exception` | Lists exceptions thrown by the function | `@throw std::invalid_argument If divisor is zero` |
| `@warning` | Highlights a dangerous usage scenario | `@warning Not safe for concurrent threads` |
| `@note` | Highlights important operational remarks | `@note Time complexity is O(1)` |
| `@see` | Cross-references related functions or classes | `@see Logger::log()` |
| `@todo` | Notes upcoming work or planned improvements | `@todo Implement cache mechanism` |

---

## 4. Practical Implementation Example

Here is how Doxygen comments were implemented in our C++ `CalculationEngine` project (Assignment 7):

```cpp
/**
 * @file Logger.h
 * @brief Declares a simple logging utility.
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

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
    void log(LogLevel level, const std::string& message) const;
};
```

---

## 5. Configuration Using `Doxyfile`

Doxygen's behavior is managed through a plain-text configuration file named `Doxyfile`.

### Generating a Template
To create a fresh template populated with default settings:
```bash
doxygen -g Doxyfile
```

### Key Parameters Used in Assignment 7
Inside `Doxyfile`, the following key settings were configured:

```ini
# Project Metadata
PROJECT_NAME           = "Calculation Engine"
PROJECT_NUMBER         = "1.0"
PROJECT_BRIEF          = "A small multi-file C++ project"

# Directory and Input Files
OUTPUT_DIRECTORY       = doc
INPUT                  = Logger.h CalculationEngine.h main.cpp
FILE_PATTERNS          = *.h *.cpp
RECURSIVE              = NO

# Extraction Scope
EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = YES
EXTRACT_STATIC         = YES

# Output Formats
GENERATE_HTML          = YES
HTML_OUTPUT            = html
GENERATE_TREEVIEW      = YES

GENERATE_LATEX         = YES
LATEX_OUTPUT           = latex
USE_PDFLATEX           = YES

# Cross-Referencing
SOURCE_BROWSER         = YES
INLINE_SOURCES          = YES
```

- `EXTRACT_ALL = YES`: Ensures that even classes and functions without explicit Doxygen comments appear in the generated index.
- `EXTRACT_PRIVATE = YES`: Documents private helper members, which is helpful for internal developer documentation.
- `GENERATE_TREEVIEW = YES`: Adds an interactive collapsible directory tree navigation panel on the left side of the HTML view.
- `SOURCE_BROWSER = YES`: Allows users to click on function names to jump directly to the syntax-highlighted source code lines.

---

## 6. Generating and Navigating Documentation

### Generating HTML and LaTeX
To build the documentation, run:
```bash
doxygen Doxyfile
```
Doxygen parses the specified `INPUT` files, checks for syntax errors or missing parameter documentation, and writes output into the `doc/` directory:

```text
doc/
├── html/
│   ├── index.html
│   ├── annotated.html     (Class List)
│   ├── files.html         (File Index)
│   ├── classCalculationEngine.html
│   └── classLogger.html
│
└── latex/
    ├── Makefile
    ├── refman.tex
    └── doxygen.sty
```

### Browsing HTML Output
Open `doc/html/index.html` in any web browser:
- **Classes**: Shows an annotated list of all classes, their public member functions, parameter types, and descriptions.
- **Files**: Shows all documented header and source files with hyperlinks to source code.
- **Search Bar**: Allows searching for any method, class, or parameter name dynamically.

### Compiling LaTeX to PDF
Doxygen produces a complete LaTeX documentation bundle in `doc/latex/`. To compile it into a single printable PDF manual:

On Linux / macOS:
```bash
cd doc/latex
make
```

On Windows:
```bash
cd doc/latex
pdflatex refman.tex
pdflatex refman.tex
```
This produces `refman.pdf`, which contains a formal, book-quality technical API manual complete with a title page, table of contents, class hierarchies, and index.

