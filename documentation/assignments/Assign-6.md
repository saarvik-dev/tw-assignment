# Assignment 6: Advanced Document Formatting, Fontspec, Boxes, Indexing, and BibLaTeX

## Topics Covered
- Modern font handling with XeLaTeX and the `fontspec` package
- Custom section numbering styles (alphabetic numbering)
- Line spreading, manual spacing (`\vspace`, `\hspace`), and hyphenation control
- Page background coloring (`\pagecolor`)
- Trivial list environment (`trivlist`)
- Equation tagging (`\tag`) and cross-referencing (`\eqref`)
- Low-level LaTeX box mechanics (`\parbox`, `\savebox`, `\usebox`, `\fbox`, `\rule`)
- Index generation using the `makeidx` package and tool
- Modern bibliography management with `biblatex` and the `biber` backend

## What I Learned
In this assignment, I explored low-level typography and document processing techniques that give fine-grained control over the final PDF output.

I learned to compile using XeLaTeX instead of standard `pdflatex`. This allowed me to load system TrueType and OpenType fonts using the `fontspec` package (`\setmainfont`, `\setsansfont`, and `\setmonofont`) rather than being restricted to classic Computer Modern fonts. I also learned how to customize document counters, such as using `\renewcommand{\thesection}{\Alph{section}}` to number sections with capital letters (A, B, C) instead of numbers.

I gained a deeper understanding of TeX's layout model, which treats elements as boxes and glue. I practiced using `\parbox` to create inline blocks of wrapped text, `\savebox` and `\usebox` to store a recurring graphic or snippet in memory and stamp it multiple times, and `\rule` to draw custom horizontal and vertical divider lines.

Finally, I implemented two essential publishing features:
1. **Book Indexing**: Tagging key concepts throughout the text using `\index{...}` and generating an alphabetical index with page numbers using the `makeidx` package and the `makeindex` command-line utility.
2. **Modern Citations**: Using `biblatex` with the `biber` backend. Compared to the older BibTeX workflow from Assignment 1, `biblatex` handles Unicode seamlessly, uses `\addbibresource`, and provides cleaner formatting options.

## Important Commands and Concepts

### Loading System Fonts with `fontspec` (XeLaTeX)
```latex
\usepackage{fontspec}
\setmainfont{DejaVu Serif}
\setsansfont{DejaVu Sans}
\setmonofont{Courier New}
```

### Counter and Section Customization
```latex
% Number sections as A, B, C...
\renewcommand{\thesection}{\Alph{section}}
\linespread{1.15} % Adjust line spacing to 1.15x
\hyphenation{algo-rithm compu-tation} % Custom hyphenation rules
```

### LaTeX Box Constructs and Rules
- `\parbox[c]{5cm}{Content inside a 5cm wide box}`
- `\savebox{\myBox}{\textbf{MNIT Jaipur}}` saves content in memory.
- `\usebox{\myBox}` prints the saved box anywhere in the document.
- `\rule{\textwidth}{1pt}`: Draws a horizontal line across the entire text width.
- `\fbox{Framed text}`: Draws an outline around text or an object.

### Generating an Index (`makeidx`)
In preamble:
```latex
\usepackage{makeidx}
\makeindex
```
In document text:
```latex
Binary search trees \index{Binary Search Tree} provide $O(\log n)$ lookup.
Sub-entries can be indexed as well: \index{Trees!Binary Search}.
```
At the end of document:
```latex
\printindex
```
Compilation step:
```bash
xelatex assignment6.tex
makeindex assignment6.idx
xelatex assignment6.tex
```

### Modern Bibliography with `biblatex` and `biber`
In preamble:
```latex
\usepackage[backend=biber, style=numeric]{biblatex}
\addbibresource{references.bib}
```
In document text:
```latex
As demonstrated in previous research \cite{knuth1984texbook}...
\printbibliography
```
Compilation workflow:
```bash
xelatex assignment6.tex
biber assignment6
xelatex assignment6.tex
xelatex assignment6.tex
```

