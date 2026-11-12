# Assignment 5: Technical Reports and Beamer Presentations

## Topics Covered
- The `report` document class and page geometry with `geometry`
- Standalone title pages and abstract environments
- Chapter, section, and subsection hierarchy
- Customizing heading typography and colors with the `sectsty` package
- Running headers, footers, and rule styling with `fancyhdr`
- Creating slide decks with the `beamer` document class
- Beamer themes (such as `Madrid`) and structural templates
- Presentation frames, titles, and subtitles
- Content structuring with `block`, `alertblock`, and `exampleblock`
- Multi-column slide design (`columns` environment)

## What I Learned
This assignment was split into two parts: writing a formal technical report and creating a professional presentation slide deck using Beamer.

In the report section, I learned how the `report` document class differs from the simpler `article` class. Reports introduce top-level `\chapter` headings that automatically start on a fresh page and reset section counters. I learned how to set exact 1-inch margins using `geometry`, create a custom cover page inside a `titlepage` environment, and include an abstract.

To make the report look polished, I used `sectsty` to globally colorize chapter and section headings without manually tagging each one. I also learned to configure headers and footers with `fancyhdr`. By using `\pagestyle{fancy}`, I placed the running chapter title on the header left, my roll number on the header right, and page numbers centered in the footer with a clean dividing line.

In the Beamer section, I learned how LaTeX builds presentation slides. Instead of manually aligning shapes and text boxes like in PowerPoint, Beamer compiles frames (`\begin{frame}`) using themes like `Madrid`. I learned to use Beamer blocks (`block`, `alertblock`, and `exampleblock`) to categorize definitions, warnings, and examples. I also learned to create clean two-column slides using the `columns` environment.

## Important Commands and Concepts

### Report Configuration and Geometry
```latex
\documentclass[12pt, a4paper]{report}
\usepackage[margin=1in]{geometry}
\usepackage{xcolor}
\usepackage{sectsty}
\usepackage{fancyhdr}

% Custom heading colors with sectsty
\definecolor{mnitNavy}{RGB}{10, 40, 90}
\chapterfont{\color{mnitNavy}\Huge\bfseries}
\sectionfont{\color{mnitNavy}\Large\bfseries}
```

### Custom Headers and Footers with `fancyhdr`
```latex
\pagestyle{fancy}
\fancyhf{} % Clear default header and footer fields
\fancyhead[L]{\slshape Technical Writing Lab Report}
\fancyhead[R]{2025UCP1681}
\fancyfoot[C]{\thepage}
\renewcommand{\headrulewidth}{0.4pt}
\renewcommand{\footrulewidth}{0.4pt}
```

### Beamer Presentation Skeleton
```latex
\documentclass{beamer}
\usetheme{Madrid}

\title[Short Title]{Full Presentation Title}
\subtitle{Technical Writing Lab}
\author{Saarvik Singh Suryavanshi}
\institute{MNIT Jaipur}
\date{\today}

\begin{document}

\begin{frame}
  \titlepage
\end{frame}

\begin{frame}{System Overview}{Key Components}
  A normal paragraph introducing the slide topic.
\end{frame}

\end{document}
```

### Beamer Blocks and Multi-Column Layout
```latex
\begin{frame}{Structured Content}
  \begin{block}{Definition}
    Core concept description goes here.
  \end{block}

  \begin{alertblock}{Important Warning}
    Pay attention to memory leaks and boundary conditions.
  \end{alertblock}

  \begin{columns}
    \begin{column}{0.48\textwidth}
      Left-hand column points.
    \end{column}
    \begin{column}{0.48\textwidth}
      Right-hand column details or code.
    \end{column}
  \end{columns}
\end{frame}
```

