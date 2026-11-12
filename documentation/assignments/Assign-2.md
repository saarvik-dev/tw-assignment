# Assignment 2: Mathematical Typesetting in LaTeX

## Topics Covered
- Inline vs display mathematical modes
- The `amsmath` and `amssymb` packages
- Fractions, roots, and radicals
- Calculus notation: limits, derivatives, summations, and integrals
- Set theory, logic, and relational symbols
- Multi-line equation environments (`align`, `align*`, `multline*`)
- Matrix and determinant types (`matrix`, `pmatrix`, `bmatrix`, `vmatrix`)

## What I Learned
In this assignment, I learned how to typeset scientific and mathematical formulas using LaTeX. In normal text mode, symbols like subscripts, superscripts, and Greek letters cannot be rendered directly, so understanding the transition between text mode and math mode was essential.

I saw the distinction between inline math (`$...$`) for embedding formulas within a sentence and display math (`\[...\]` or `\begin{equation}`) for centered, standalone equations. When working with calculus, I learned how limits, summations, and integrals automatically place their bounds below and above the operator in display mode, but place them to the side in inline mode to avoid disrupting line spacing.

I also learned how to handle complex and multi-step derivations. The `align` environment from `amsmath` made it easy to line up equations at the equals sign using the `&` character. For very long equations that exceed the page margin, I learned to use `multline*` rather than forcing an awkward line break. Lastly, I learned to construct matrices using environments like `pmatrix` and `bmatrix`, using dots (`\dots`, `\vdots`, `\ddots`) to represent large dimensions.

## Important Commands and Concepts

### Math Mode Basics
- Inline math: `$x^2 + y^2 = r^2$`
- Display math without numbering: `\[ f(x) = x^2 \]`
- Numbered equation:
```latex
\begin{equation}
\label{eq:sample}
E = mc^2
\end{equation}
```

### Fractions and Roots
- Fraction: `\frac{numerator}{denominator}`
- Square root: `\sqrt{x + y}`
- nth root: `\sqrt[n]{x}`

### Calculus and Common Operators
- Derivative: `\frac{df}{dx}` or partial derivative `\frac{\partial u}{\partial t}`
- Limit: `\lim_{x \to 0} \frac{\sin x}{x} = 1`
- Summation: `\sum_{k=1}^{n} k = \frac{n(n+1)}{2}`
- Integrals: `\int_{a}^{b} f(x)\,dx` or indefinite `\int f(x)\,dx`

### Multi-line Equations with Align and Multline
The `align` environment aligns equations using `&` as the anchor and `\\` for new lines:
```latex
\begin{align*}
(a + b)^2 &= (a + b)(a + b) \\
          &= a^2 + ab + ba + b^2 \\
          &= a^2 + 2ab + b^2
\end{align*}
```

The `multline*` environment splits a single long equation across multiple lines:
```latex
\begin{multline*}
p(x) = a_0 + a_1 x + a_2 x^2 + a_3 x^3 + a_4 x^4 \\
       + a_5 x^5 + a_6 x^6 + a_7 x^7
\end{multline*}
```

### Matrix Environments
Matrices use `&` to separate columns and `\\` to separate rows:
- `matrix`: Plain matrix with no delimiters
- `pmatrix`: Delimited by parentheses `(...)`
- `bmatrix`: Delimited by square brackets `[...]`
- `vmatrix`: Delimited by single vertical bars `|...|` (determinants)

Example:
```latex
\begin{pmatrix}
a_{11} & a_{12} & \dots  & a_{1n} \\
a_{21} & a_{22} & \dots  & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1} & a_{m2} & \dots  & a_{mn}
\end{pmatrix}
```

