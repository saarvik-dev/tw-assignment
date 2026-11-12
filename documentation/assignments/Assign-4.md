# Assignment 4: Lists, Colors, Figures, and Floating Environments

## Topics Covered
- Unordered (`itemize`), ordered (`enumerate`), and descriptive (`description`) lists
- Custom list labels and nested list environments
- Color management with the `xcolor` package
- Defining custom colors (`\definecolor`) and color tints (`\colorlet`)
- Colored text, background boxes, and framed boxes
- Graphic manipulation with the `graphicx` package (`width`, `scale`, `angle`, `trim`, `clip`)
- The `figure` float environment and placement specifiers (`[h]`, `[t]`, `[b]`, `[p]`)
- Captions, cross-referencing, and side-by-side figures with `minipage`
- Float-only page tables (`table[p]`)

## What I Learned
In this assignment, I learned how to enrich LaTeX documents with lists, customized color palettes, and graphic illustrations.

I explored the three core list environments in LaTeX: `itemize` for bulleted points, `enumerate` for sequenced steps, and `description` for key-term definitions. I learned how LaTeX automatically adjusts numbering styles (numbers to letters to Roman numerals) when nesting lists, and how to pass custom bracketed arguments (`\item[...]`) to override bullets manually.

For visual styling, I worked with the `xcolor` package. I learned to define custom colors via RGB coordinates (`\definecolor`) and create lighter tints using percentage mixing (`\colorlet` and notation like `blue!30`). I used these colors for inline text (`\textcolor`), filled text blocks (`\colorbox`), and framed callouts (`\fcolorbox`).

A major part of this lab was handling figures. LaTeX treats figures as "floats," meaning it places them where they fit best according to typographic rules rather than forcing them to break across awkward page boundaries. I learned to use placement specifiers like `[htbp]` to guide the compiler. I also learned to scale, rotate, and crop images directly in the `.tex` file using `trim` and `clip` parameters in `\includegraphics`. Finally, I used the `minipage` environment to place two independent sub-figures side-by-side with separate captions inside one figure container.

## Important Commands and Concepts

### List Environments
```latex
% Descriptive list for terminology
\begin{description}
  \item[Compiler] Translates source code into machine code.
  \item[Linker] Combines object files into an executable.
\end{description}
```

### Color Definitions and Usage (`xcolor`)
```latex
\usepackage{xcolor}

% Custom RGB color definition
\definecolor{mnitBlue}{RGB}{0, 74, 153}
\colorlet{lightBlue}{mnitBlue!25}

% Text and box coloring
\textcolor{mnitBlue}{\textbf{Primary Heading}}
\colorbox{lightBlue}{Highlighted background text}
\fcolorbox{mnitBlue}{lightBlue}{Framed box with border and background}
```

### Inserting and Manipulating Figures (`graphicx`)
```latex
\usepackage{graphicx}

\begin{figure}[htbp]
\centering
\includegraphics[width=0.7\textwidth, angle=90]{images/diagram.png}
\caption{Rotated system architecture diagram}
\label{fig:arch}
\end{figure}
```

- `width=0.8\textwidth`: Scales image to 80% of page text width.
- `angle=90`: Rotates image 90 degrees counter-clockwise.
- `trim=left bottom right top, clip`: Crops margins from the image.

### Side-by-Side Figures with `minipage`
```latex
\begin{figure}[htbp]
\centering
\begin{minipage}{0.48\textwidth}
  \centering
  \includegraphics[width=\textwidth]{fig1.png}
  \caption{First observation}
  \label{fig:sub1}
\end{minipage}
\hfill
\begin{minipage}{0.48\textwidth}
  \centering
  \includegraphics[width=\textwidth]{fig2.png}
  \caption{Second observation}
  \label{fig:sub2}
\end{minipage}
\end{figure}
```
Figure references are placed in text using `Figure~\ref{fig:sub1}`.

