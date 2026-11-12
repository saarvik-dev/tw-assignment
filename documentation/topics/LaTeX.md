# LaTeX: Technical and Scientific Typesetting

LaTeX is a document preparation system designed for high-quality technical and scientific typesetting. Unlike visual WYSIWYG word processors such as Microsoft Word or Google Docs, LaTeX operates on a markup model. The author writes plain text annotated with logical commands in a `.tex` file, which is then processed by a compiler (`pdflatex`, `xelatex`, or `lualatex`) to generate a formatted PDF.

---

## 1. Document Structure and Preamble

A LaTeX document is split into two distinct parts:
1. **Preamble**: Everything before `\begin{document}`. This is where document configurations, global layout parameters, and package imports reside.
2. **Body**: The region between `\begin{document}` and `\end{document}` containing the document text, sections, equations, and floats.

```latex
\documentclass[12pt, a4paper]{article}

% Preamble: package imports and metadata
\usepackage[margin=1in]{geometry}
\usepackage{amsmath, amssymb}
\usepackage{graphicx}

\title{Introduction to Technical Typesetting}
\author{Saarvik Singh Suryavanshi}
\date{\today}

\begin{document}
\maketitle
\tableofcontents

% Body content begins here

\end{document}
```

### Document Classes
The `\documentclass[options]{class}` command sets the base typographical layout of the document:
- `article`: Designed for short documents, technical notes, lab assignments, and journal articles. Sections are the highest heading level.
- `report`: Designed for longer academic reports and dissertations. Introduces `\chapter` as the top-level structural unit, defaults to a standalone title page, and starts chapters on fresh pages.
- `book`: Designed for full-length books with two-sided printing, front matter, main matter, and back matter.
- `beamer`: Used to produce presentation slides.

Common class options include font sizes (`10pt`, `11pt`, `12pt`), paper sizes (`a4paper`, `letterpaper`), and column layouts (`onecolumn`, `twocolumn`).

### Packages
Packages extend LaTeX's built-in capabilities and are included in the preamble using `\usepackage[options]{package}`. Core packages used throughout the lab include:
- `geometry`: Adjusts page margins and paper geometry.
- `amsmath`, `amssymb`: Advanced mathematical typesetting, symbols, and multi-line equation environments.
- `graphicx`: Embedding, scaling, rotating, and cropping graphics.
- `xcolor`: Color definitions, colored text, backgrounds, and colored table cells.
- `fancyhdr`: Custom running headers and footers.
- `sectsty`: Changing font sizes and colors of chapter and section headings.
- `fontspec`: Loading system TrueType and OpenType fonts under XeLaTeX.
- `booktabs`, `multirow`: Publication-grade tables and vertical cell merging.
- `natbib`, `biblatex`: Managing citations and bibliographies.
- `makeidx`: Index generation.

---

## 2. Document Organisation and Formatting

### Sectioning Hierarchy
Headings are declared logically, and LaTeX handles their numbering, spacing, and styling automatically:
- `\chapter{...}` (available in `report` and `book`)
- `\section{...}`
- `\subsection{...}`
- `\subsubsection{...}`
- `\paragraph{...}`

To omit automatic numbering from a heading, add an asterisk: `\section*{Unnumbered Section}`.

### Table of Contents
The `\tableofcontents` command reads the document structure and prints a formatted Table of Contents. 
- During compilation, LaTeX writes heading titles and page numbers into an auxiliary file (`.aux`).
- A **two-pass compilation** is required: the first run collects the headings and page offsets, and the second run renders the Table of Contents correctly.

### Typography and Fonts
Text styling commands allow fine control over font weight, shape, and family:
- Font shapes: `\textbf{bold}`, `\textit{italic}`, `\underline{underlined}`, `\textsc{small caps}`.
- Font families: `\textrm{roman / serif}`, `\textsf{sans-serif}`, `\texttt{typewriter / monospace}`.
- Relative font sizing:
  `\tiny` < `\scriptsize` < `\footnotesize` < `\small` < `\normalsize` < `\large` < `\Large` < `\LARGE` < `\huge` < `\Huge`

Example:
```latex
{\small This note is in smaller text.}
```

### System Fonts with XeLaTeX (`fontspec`)
When compiling with `xelatex`, the `fontspec` package allows loading standard system TrueType or OpenType fonts directly:
```latex
\usepackage{fontspec}
\setmainfont{DejaVu Serif}
\setsansfont{DejaVu Sans}
\setmonofont{Courier New}
```

### Spacing and Page Layout
- Line spacing: `\linespread{1.2}` in the preamble adjusts leading.
- Spacing: `\vspace{0.5cm}` inserts vertical whitespace; `\hspace{1cm}` inserts horizontal whitespace.
- Page breaks: `\newpage` forces content onto a new page; `\clearpage` flushes all remaining floating figures and tables before starting a new page.
- Counter modification: Counters can be redefined, such as changing section numbering to letters:
  ```latex
  \renewcommand{\thesection}{\Alph{section}}
  ```
- Running headers and footers (`fancyhdr`):
  ```latex
  \pagestyle{fancy}
  \fancyhf{}
  \fancyhead[L]{\slshape Lab Documentation}
  \fancyhead[R]{2025UCP1681}
  \fancyfoot[C]{\thepage}
  \renewcommand{\headrulewidth}{0.4pt}
  ```

---

## 3. Lists

LaTeX provides three standard list environments, plus a low-level trivial list:

### Unordered Lists (`itemize`)
```latex
\begin{itemize}
  \item First item
  \item Second item with custom marker
  \item[$\rightarrow$] Custom arrow bullet
\end{itemize}
```

### Ordered Lists (`enumerate`)
```latex
\begin{enumerate}
  \item Step 1: Read requirements
  \item Step 2: Implement code
  \begin{enumerate}
    \item Sub-step 2a: Write headers
    \item Sub-step 2b: Write implementation
  \end{enumerate}
\end{enumerate}
```
Nested `enumerate` environments automatically switch from Arabic numbers (`1.`) to alphabetic letters (`(a)`), Roman numerals, and Greek counters.

### Descriptive Lists (`description`)
```latex
\begin{description}
  \item[Compiler] Translates source code into machine-readable object files.
  \item[Linker] Combines object files into an executable binary.
\end{description}
```

### Trivial Lists (`trivlist`)
The `trivlist` environment provides a flexible container that shares list vertical margins without applying default indentation or bullets, useful for custom block environments.

---

## 4. Mathematical Typesetting

Mathematical notation is one of LaTeX's strongest features. Math must be written in one of two modes:

### Inline Math Mode
Used for expressions inside a sentence, enclosed with single dollar signs:
```latex
The kinetic energy is given by $K = \frac{1}{2}mv^2$.
```

### Display Math Mode
Used for centered, standalone equations. Can be unnumbered (`\[ ... \]`) or numbered (`\begin{equation} ... \end{equation}`):
```latex
\begin{equation}
\label{eq:schrodinger}
i\hbar \frac{\partial}{\partial t}\Psi(\mathbf{r}, t) = \left[ -\frac{\hbar^2}{2m}\nabla^2 + V(\mathbf{r}, t) \right] \Psi(\mathbf{r}, t)
\end{equation}
```

### Fractions, Roots, and Calculus
- Fractions: `\frac{numerator}{denominator}`
- Roots: `\sqrt{x}` or `\sqrt[n]{x}`
- Derivatives: Ordinary `\frac{df}{dx}`, partial `\frac{\partial f}{\partial x}`
- Integrals: `\int_{a}^{b} f(x)\,dx`, double integral `\iint`, contour integral `\oint`
- Summations and Limits: `\sum_{i=1}^{n} i^2`, `\lim_{x \to 0} \frac{\sin x}{x}`
- Logic and sets: `\forall`, `\exists`, `\in`, `\land`, `\lor`, `\implies`, `\iff`, `\subseteq`, `\cup`, `\cap`

### Multi-Line Equations
The `amsmath` package provides specialized multi-line environments:
- `align` and `align*`: Aligns equations at the `&` character. `align` numbers every row; `align*` suppresses numbering.
  ```latex
  \begin{align}
    A &= B + C \label{eq:step1} \\
      &= D + E + F \label{eq:step2}
  \end{align}
  ```
- `multline*`: Splits a single long equation across multiple rows without column alignment anchors. The first line is left-aligned, the middle lines are centered, and the last line is right-aligned.

### Advanced Math Constructs
- **Piecewise functions (`cases`)**:
  ```latex
  f(x) =
  \begin{cases}
    -x, & \text{if } x < 0 \\
     0, & \text{if } x = 0 \\
     x, & \text{if } x > 0
  \end{cases}
  ```
- **Equation annotations**:
  ```latex
  E_{\text{total}} = \overbrace{K}^{\text{Kinetic}} + \underbrace{U}_{\text{Potential}}
  ```
- **Matrices**:
  ```latex
  \begin{pmatrix}
    a_{11} & a_{12} & \dots  & a_{1n} \\
    a_{21} & a_{22} & \dots  & a_{2n} \\
    \vdots & \vdots & \ddots & \vdots \\
    a_{m1} & a_{m2} & \dots  & a_{mn}
  \end{pmatrix}
  ```
  Environments include `matrix` (no delimiters), `pmatrix` (parentheses), `bmatrix` (brackets), and `vmatrix` (vertical bars for determinants).

---

## 5. Tables

Tables in LaTeX are constructed using the `tabular` environment, typically nested within a floating `table` environment.

### Basic Tabular Syntax
```latex
\begin{table}[htbp]
\centering
\caption{System Performance Metrics}
\label{tab:metrics}
\begin{tabular}{|l|c|r|}
\hline
Module & Operations/sec & Error Rate \\
\hline
Parser & 12,400 & 0.01\% \\
Engine & 45,100 & 0.00\% \\
\hline
\end{tabular}
\end{table}
```
- Column specifiers: `l` (left), `c` (center), `r` (right).
- `p{width}`: Fixed-width column with automatic paragraph wrapping (e.g. `p{4cm}`).
- Column separator: `&`.
- Row terminator: `\\`.
- Horizontal line: `\hline`.

### Merging Cells
- Horizontal merging: `\multicolumn{cols}{alignment}{content}`
- Vertical merging (requires `\usepackage{multirow}`): `\multirow{rows}{width}{content}`

```latex
\begin{tabular}{|c|c|c|}
\hline
\multicolumn{2}{|c|}{Combined Header} & Single Header \\
\hline
\multirow{2}{*}{Group 1} & Data A & 100 \\
                         & Data B & 200 \\
\hline
\end{tabular}
```

### Scientific Tables with `booktabs`
Standard scientific publications avoid vertical bars and use clean horizontal rules:
```latex
\usepackage{booktabs}

\begin{tabular}{llr}
\toprule
Name & Role & Department \\
\midrule
Alice & Lead Developer & Systems \\
Bob & Architect & Infrastructure \\
\bottomrule
\end{tabular}
```
- `\toprule`: Thick top boundary rule.
- `\midrule`: Dividing rule between header and rows.
- `\bottomrule`: Thick bottom boundary rule.
- `\cmidrule(lr){2-3}`: Partial horizontal line spanning selected columns.

### Colored Tables (`colortbl` / `xcolor`)
Using `\usepackage[table]{xcolor}`:
- `\rowcolor{color}`: Fills an entire row with a color.
- `\cellcolor{color}`: Fills a specific cell.
- `\rowcolors{start_row}{odd_color}{even_color}`: Automatically alternates row background colors.

---

## 6. Figures and Images

Images are inserted using the `graphicx` package inside a floating `figure` environment.

```latex
\begin{figure}[htbp]
\centering
\includegraphics[width=0.7\textwidth]{figures/system_architecture.png}
\caption{System Architecture Overview}
\label{fig:arch}
\end{figure}
```

### Placement Specifiers
LaTeX places floats based on placement parameters:
- `h`: Approximately here
- `t`: At the top of the page
- `b`: At the bottom of the page
- `p`: On a dedicated float page
- `!`: Overrides internal placement aesthetics

### Image Options
Parameters passed to `\includegraphics[...]`:
- `width=0.8\textwidth` or `width=10cm`
- `height=5cm`
- `scale=0.5`: Scales dimensions by 50%
- `angle=90`: Rotates image counter-clockwise
- `trim=left bottom right top, clip`: Crops margins from the image

### Side-by-Side Figures with `minipage`
```latex
\begin{figure}[htbp]
\centering
\begin{minipage}{0.48\textwidth}
  \centering
  \includegraphics[width=\textwidth]{fig1.png}
  \caption{Primary Waveform}
  \label{fig:wave1}
\end{minipage}
\hfill
\begin{minipage}{0.48\textwidth}
  \centering
  \includegraphics[width=\textwidth]{fig2.png}
  \caption{Filtered Response}
  \label{fig:wave2}
\end{minipage}
\end{figure}
```

### The Picture Environment
LaTeX includes a native vector graphics system that does not rely on external graphic files:
```latex
\setlength{\unitlength}{1mm}
\begin{picture}(60, 40)
  \put(10, 10){\framebox(40, 20){Processing Block}}
  \put(5, 20){\vector(1, 0){5}}
  \put(50, 20){\vector(1, 0){5}}
\end{picture}
```
Elements are placed using `\put(x,y){object}` with commands like `\line`, `\vector`, `\circle`, and `\framebox`.

---

## 7. Boxes and Low-Level Layout

LaTeX views all printable content as boxes joined by flexible space (glue):
- `\parbox[position]{width}{text}`: Creates an inline box that wraps text like a mini-page.
- `\fbox{text}`: Surrounds text with a visible rectangular border.
- `\rule{width}{height}`: Draws a solid horizontal or vertical bar (e.g. `\rule{\textwidth}{0.5pt}`).
- `\savebox{\boxname}{content}` and `\usebox{\boxname}`: Stores complex content in memory and renders it multiple times without re-processing.

---

## 8. Bibliography, Citations, and Indexing

### BibTeX with Natbib
References are stored in an external `.bib` file:
```bibtex
@book{griffiths2018introduction,
  author    = {David J. Griffiths and Darrell F. Schroeter},
  title     = {Introduction to Quantum Mechanics},
  year      = {2018},
  publisher = {Cambridge University Press}
}
```

In the `.tex` file:
```latex
According to \cite{griffiths2018introduction}, wave functions...

\bibliographystyle{plain}
\bibliography{references}
```
Compilation workflow:
```bash
pdflatex document.tex
bibtex document
pdflatex document.tex
pdflatex document.tex
```

### BibLaTeX with Biber
A modern citation management system offering full Unicode support:
```latex
\usepackage[backend=biber, style=numeric]{biblatex}
\addbibresource{references.bib}

\begin{document}
As cited in \cite{griffiths2018introduction}...
\printbibliography
\end{document}
```
Compilation workflow:
```bash
pdflatex document.tex
biber document
pdflatex document.tex
pdflatex document.tex
```

### Index Creation with `makeidx`
1. Load package and initialize in preamble:
   ```latex
   \usepackage{makeidx}
   \makeindex
   ```
2. Tag terms throughout the text:
   ```latex
   The binary search algorithm \index{Binary Search} runs in $O(\log n)$ time.
   Sub-entries can also be indexed: \index{Trees!Binary Search}.
   ```
3. Print index at end of document:
   ```latex
   \printindex
   ```
4. Compile index file:
   ```bash
   pdflatex document.tex
   makeindex document.idx
   pdflatex document.tex
   ```

