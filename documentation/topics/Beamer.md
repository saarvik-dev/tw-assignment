# Beamer: Creating Technical Presentations in LaTeX

Beamer is a LaTeX document class used to create structured, professional presentation slide decks. Unlike GUI presentation tools like Microsoft PowerPoint or LibreOffice Impress, Beamer uses LaTeX markup. This means all equations, mathematical notations, code listings, and citations look just as sharp and consistent as they do in technical papers and reports.

The output of a Beamer compilation is a standard PDF file where each slide corresponds to a page, ready to be presented in full-screen mode in any PDF viewer.

---

## 1. Basic Document Structure

A Beamer presentation follows the standard LaTeX structure with `\documentclass{beamer}` at the top. The slides themselves are defined inside `frame` environments.

```latex
\documentclass{beamer}

% Theme selection
\usetheme{Madrid}

% Presentation metadata
\title[Intro to LaTeX]{Introduction to LaTeX}
\subtitle{Technical Writing Lab}
\author[Saarvik Singh]{Saarvik Singh Suryavanshi}
\institute[MNIT Jaipur]{
    Department of Computer Science and Engineering \\
    MNIT Jaipur
}
\date{\today}

\begin{document}

% Title slide
\begin{frame}
    \titlepage
\end{frame}

% A regular content slide
\begin{frame}{Slide Title}{Optional Subtitle}
    Slide body content goes here.
\end{frame}

\end{document}
```

### Key Structural Commands
- `\title[Short Title]{Full Title}`: The optional bracketed argument defines a compact title shown in the running footline, while the braced argument appears on the main title slide.
- `\author[Short Name]{Full Name}`: Similar to the title, short names appear in the footer.
- `\institute[Short Institute]{Full Institute}`: Displays institutional affiliation.
- `\date{\today}`: Automatically inserts the presentation date.
- `\titlepage`: Generates the formatted title slide using the metadata fields.

---

## 2. Frames and Slides

In Beamer, the fundamental unit of content is the **frame**:
```latex
\begin{frame}{Main Title}{Subtitle}
    Content of the slide...
\end{frame}
```

- Each `frame` environment corresponds to one slide (or a series of overlay slides if animation steps are used).
- If content overflows a frame, Beamer does not automatically split it across pages unless the `[allowframebreaks]` option is added: `\begin{frame}[allowframebreaks]{Title}`.
- To make a slide completely blank without headers, footers, or themes (useful for large graphics or full-screen images), pass the `[plain]` option: `\begin{frame}[plain]`.

---

## 3. Themes and Appearance

Beamer decouples presentation content from visual themes. A theme specifies fonts, colors, bullet styles, header banners, and footer lines.

### Presentation Themes
Loaded in the preamble with `\usetheme{Name}`:
- `Madrid`: A clean, corporate theme with solid blue header/footer bars and high information density. Used in Assignment 5.
- `Warsaw`: A popular dark theme with shaded banners and navigation tabs across the top.
- `Boadilla`: A minimalist theme similar to Madrid but with softer colors and thin footer lines.
- `AnnArbor` / `CambridgeUS`: Variations of split top/bottom navigation layouts.

### Color Themes
Loaded with `\usecolortheme{Name}`:
- `default`, `dolphin`, `whale`: Shades of blue.
- `beaver`: Red and gray palette.
- `orchid`: Deep inner color contrasts.

---

## 4. Structuring Content: Blocks and Lists

Technical slides must be easy for an audience to scan. Beamer provides built-in container environments called **blocks** to group related concepts.

### Block Environments
1. **Standard Block (`block`)**: Colored with the primary theme color. Used for definitions, core principles, and theorems.
2. **Alert Block (`alertblock`)**: Highlighted in red/accent color. Used to draw immediate attention to warnings, pitfalls, or important notes.
3. **Example Block (`exampleblock`)**: Highlighted in green/secondary color. Used for code snippets, calculations, and worked examples.

```latex
\begin{frame}{Structured Content Overview}

  \begin{block}{Definition}
    LaTeX is a document preparation system based on TeX.
  \end{block}

  \begin{alertblock}{Common Pitfall}
    Always remember that LaTeX requires two compilation passes to update cross-references!
  \end{alertblock}

  \begin{exampleblock}{Sample Formula}
    The mass-energy equivalence is written as:
    \[
    E = mc^2
    \]
  \end{exampleblock}

\end{frame}
```

### Lists in Beamer
Lists behave like standard LaTeX lists, but bullet icons and item numbering are styled automatically by the selected theme:
```latex
\begin{frame}{Key Advantages}
  \begin{itemize}
    \item Excellent typography for technical writing
    \vspace{0.3cm}
    \item High-quality mathematical formula rendering
    \vspace{0.3cm}
    \item Automatic bibliography and index handling
  \end{itemize}
\end{frame}
```
Adding `\vspace{0.3cm}` between list items helps spread points vertically across the slide for better readability.

---

## 5. Multi-Column Layouts

To place text next to a diagram or display two parallel comparison points, Beamer provides the `columns` environment:

```latex
\begin{frame}{Two-Column Comparison}
  \begin{columns}
  
    \begin{column}{0.48\textwidth}
      \textbf{Source Code (.tex)}
      \begin{itemize}
        \item Plain-text markup
        \item Explicit structural commands
        \item Version control friendly
      \end{itemize}
    \end{column}

    \begin{column}{0.48\textwidth}
      \textbf{Output (PDF)}
      \begin{itemize}
        \item Vector-quality rendering
        \item Automatic line wrapping
        \item Consistent typographic spacing
      \end{itemize}
    \end{column}

  \end{columns}
\end{frame}
```
Each `column` takes a fixed fraction of `\textwidth` (such as `0.48\textwidth` so that two columns fit side by side with a small margin in between).

---

## 6. Images and Figures

Images are inserted using `\includegraphics` from the `graphicx` package:

```latex
\begin{frame}{System Architecture}
  \begin{center}
    \includegraphics[width=0.7\textwidth]{figures/architecture.png}
  \end{center}
\end{frame}
```
Unlike standard documents where images float freely across pages, figures inside a Beamer frame do not move to another slide. Using `\begin{center}` centers the image directly where placed.

---

## 7. Headers, Footers, and Slide Numbers

In a technical presentation, footers help the audience keep track of time and slide references. 

### Navigation Symbols
By default, Beamer displays small navigation icons at the bottom right. These can be disabled to avoid visual clutter:
```latex
\setbeamertemplate{navigation symbols}{}
```

### Custom Footline Template
In Assignment 5, a custom three-part running footer was implemented using `beamercolorbox`:

```latex
\setbeamertemplate{footline}{
  \leavevmode
  \hbox{
    % Left box: Author name
    \begin{beamercolorbox}[wd=0.34\paperwidth, ht=2.5ex, dp=1ex, left]{author in head/foot}
      \hspace{1em} Saarvik Singh Suryavanshi
    \end{beamercolorbox}
    
    % Center box: Presentation title
    \begin{beamercolorbox}[wd=0.46\paperwidth, ht=2.5ex, dp=1ex, center]{title in head/foot}
      Introduction to LaTeX
    \end{beamercolorbox}
    
    % Right box: Slide number fraction
    \begin{beamercolorbox}[wd=0.20\paperwidth, ht=2.5ex, dp=1ex, right]{date in head/foot}
      \insertframenumber/\inserttotalframenumber
      \hspace{1em}
    \end{beamercolorbox}
  }
}
```
- `\insertframenumber`: Current slide number.
- `\inserttotalframenumber`: Total number of slides in the deck.
- Splitting the width as `0.34 + 0.46 + 0.20 = 1.00\paperwidth` covers the exact horizontal width of the screen.

---

## 8. Compiling a Beamer Presentation

Beamer presentations are compiled using standard LaTeX command-line tools:

```bash
pdflatex beamer.tex
pdflatex beamer.tex
```
Running `pdflatex` twice resolves the total slide count (`\inserttotalframenumber`) and any section references. The output file `beamer.pdf` is directly opened in a PDF viewer and presented in full screen.
