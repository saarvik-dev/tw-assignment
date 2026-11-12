# Assignment 3: Advanced Mathematical Environments and Complex Tables

## Topics Covered
- Piecewise functions and conditionals with the `cases` environment
- Equation annotation using `\overbrace` and `\underbrace`
- Spacing and phantom characters for alignment (`\phantom`)
- Table construction with the `tabular` environment
- Column formatting and fixed-width text wrapping (`p{width}`)
- Multi-column and multi-row cell merging (`\multicolumn`, `\multirow`)
- Publication-quality tables using the `booktabs` package
- Table row and cell coloring with `colortbl` / `xcolor`
- Nested tables and mathematical expressions inside table cells

## What I Learned
In this assignment, I moved beyond basic equations and tables to learn advanced formatting for complex technical papers.

In math typesetting, I learned how to represent piecewise functions (such as the absolute value function or step responses) using the `cases` environment. I also discovered how to annotate parts of an equation using `\overbrace` and `\underbrace` with superscripts and subscripts, which is useful when explaining physical derivations step by step. When aligning terms across different matrix blocks, I used `\phantom` to insert invisible spacing with exact dimensions.

For tables, I realized that simple `l`, `c`, and `r` columns do not wrap text; if a cell has a long sentence, it pushes the table outside the page margins. Setting fixed-width paragraph columns like `p{3cm}` solves this by automatically wrapping lines. I also learned to combine multiple cells horizontally with `\multicolumn` and vertically with `\multirow`.

A major design insight from this lab was the difference between traditional boxed tables and clean scientific tables. Using the `booktabs` package (`\toprule`, `\midrule`, `\bottomrule`) creates professional tables without vertical lines. Finally, I learned how to color alternating rows using `\rowcolors` and how to embed a smaller table inside a parent table cell.

## Important Commands and Concepts

### Piecewise Functions (`cases`)
The `cases` environment groups conditions under a single large left brace:
```latex
f(x) =
\begin{cases}
  -x, & \text{if } x < 0 \\
   0, & \text{if } x = 0 \\
   x, & \text{if } x > 0
\end{cases}
```

### Annotating Equations with Braces
```latex
E_{\text{total}} = 
\overbrace{\frac{1}{2}mv^2}^{\text{Kinetic Energy}} + 
\underbrace{mgh}_{\text{Potential Energy}}
```

### Fixed-Width Column Wrapping
To prevent text from running off the page, use `p{width}`:
```latex
\begin{tabular}{|c|p{4cm}|}
\hline
ID & Description \\
\hline
1 & This is a long sentence that automatically wraps within 4 centimeters. \\
\hline
\end{tabular}
```

### Cell Merging: Multicolumn and Multirow
Requires `\usepackage{multirow}`:
```latex
\begin{tabular}{|c|c|c|}
\hline
\multicolumn{2}{|c|}{Merged Header} & Col 3 \\
\hline
\multirow{2}{*}{Merged 2 Rows} & Value A & 10 \\
                               & Value B & 20 \\
\hline
\end{tabular}
```

### Professional Tables with `booktabs`
Scientific papers generally avoid vertical bars and use clear horizontal rules:
```latex
\usepackage{booktabs}

\begin{tabular}{llr}
\toprule
Item & Category & Price \\
\midrule
CPU & Hardware & \$250 \\
RAM & Hardware & \$80 \\
\bottomrule
\end{tabular}
```

### Colored Rows and Cells
Using `\usepackage[table]{xcolor}`:
- `\rowcolor{gray!20}`: Fills a single row with light gray.
- `\cellcolor{blue!15}`: Fills an individual cell.
- `\rowcolors{2}{gray!10}{white}`: Sets alternating row backgrounds starting from row 2.

