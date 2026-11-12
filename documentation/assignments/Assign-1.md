# Assignment 1: Introduction to LaTeX and Basic Document Structure

## Topics Covered
- Basic document skeleton and preamble
- Document classes and paper configuration options
- Sectioning hierarchy and automatic Table of Contents generation
- Text sizing and font scale commands
- Numbered lists using the enumerate environment
- Inline and display mathematical formulas
- Bibliography management using BibTeX and the `natbib` package
- Multi-step compilation workflow (`pdflatex` and `bibtex`)

## What I Learned
In this first lab assignment, I learned how LaTeX differs fundamentally from WYSIWYG word processors like Microsoft Word. Instead of manually formatting text as I write, I define the document structure through commands and let the compiler handle typesetting, numbering, and spacing.

I learned how to set up an `article` document class with specific options like font size and paper geometry. I explored the document hierarchy (`\section`, `\subsection`, and `\subsubsection`) and observed that LaTeX automatically numbers these headings and generates a table of contents using `\tableofcontents`. A key takeaway was understanding why LaTeX needs to be compiled twice: the first pass records section numbers and page locations into an auxiliary file (`.aux`), and the second pass actually builds the table of contents.

I also practiced typing mathematical equations, comparing simple inline expressions like `$E = mc^2$` with complex display equations like the time-dependent Schrödinger wave equation. Finally, I learned how external bibliography files (`.bib`) work with BibTeX and `natbib`, which automatically formats in-text citations and creates a structured references section at the end of the document.

## Important Commands and Concepts

### Document Structure and Preamble
A LaTeX document requires a document class declaration, a preamble for packages and metadata, and the `document` environment:

```latex
\documentclass[12pt, a4paper]{article}
\usepackage{natbib}

\title{Introduction to LaTeX}
\author{Saarvik Singh Suryavanshi}
\date{\today}

\begin{document}
\maketitle
\tableofcontents
% Document body goes here
\end{document}
```

### Headings and Hierarchy
LaTeX provides standardized structural divisions:
- `\section{...}`: Level 1 heading
- `\subsection{...}`: Level 2 heading
- `\subsubsection{...}`: Level 3 heading
- `\tableofcontents`: Collects headings and their page numbers automatically.

### Font Sizes
Relative sizing commands scale text smoothly based on the base document size:
- `\Huge`, `\LARGE`, `\Large`, `\large`: Larger heading sizes
- `\normalsize`: Default body text
- `\small`, `\footnotesize`, `\scriptsize`, `\tiny`: Subscript and fine-print sizes

Example:
```latex
{\small This is small text} and {\Huge this is huge text.}
```

### Math Typesetting
- Inline math: Enclosed in single dollar signs (`$E = mc^2$`).
- Display math: Enclosed in `\[ ... \]` to render on its own centered line:

```latex
\[
i\hbar \frac{\partial}{\partial t}\Psi(\mathbf{r}, t) = \left[ -\frac{\hbar^2}{2m}\nabla^2 + V(\mathbf{r}, t) \right] \Psi(\mathbf{r}, t)
\]
```

### Bibliography with BibTeX and Natbib
References are stored in an external `.bib` file using key-value fields. In the `.tex` file:
```latex
According to \cite{griffiths2018introduction}, quantum mechanics...

\bibliographystyle{agu}
\bibliography{physics}
```

To fully resolve all cross-references and bibliography keys, the compilation sequence is:
```bash
pdflatex assignment1.tex
bibtex assignment1
pdflatex assignment1.tex
pdflatex assignment1.tex
```

