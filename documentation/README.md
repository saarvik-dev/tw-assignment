# Technical Writing Lab: Course Documentation

This repository contains my assignments and practical work for the Technical Writing Lab course at MNIT Jaipur (Department of Computer Science and Engineering). The course covered tools and workflows essential for technical, scientific, and software documentation: LaTeX, Beamer, Doxygen, Google Docs, Git, and GitHub.

---

## 1. LaTeX

LaTeX is a typesetting system widely used in academia and technical fields. Unlike standard word processors, LaTeX separates content from visual presentation. The author writes structured text and commands in a `.tex` file, which is then compiled into a PDF.

### Document Structure and Classes
Every LaTeX file has two main parts: the **preamble** (everything before `\begin{document}`) and the **body** (the text between `\begin{document}` and `\end{document}`).

Common document classes:
- `article`: For short technical notes, lab assignments, and journal papers.
- `report`: For longer academic reports with chapters (such as Assignment 5).
- `book`: For multi-chapter books with front matter, main matter, and back matter.

Key packages are imported in the preamble using `\usepackage{...}`:
- `geometry`: Adjusts page margins (e.g., `[margin=1in]`).
- `amsmath`, `amssymb`: Advanced mathematical typesetting and symbols.
- `graphicx`: Inserting and scaling images.
- `xcolor`: Text, box, and background coloring.
- `fancyhdr`: Custom running headers and footers.
- `booktabs`, `multirow`: Professional table formatting.

### Document Formatting and Sectioning
Documents are structured using hierarchical section commands:
- `\section{...}`, `\subsection{...}`, `\subsubsection{...}`, and `\paragraph{...}`.
- LaTeX automatically numbers these sections and builds the Table of Contents via `\tableofcontents`. Because LaTeX writes section numbers and page offsets to an auxiliary file (`.aux`), compiling twice is required to update references accurately.
- Font sizes scale relative to the document base size: `\Huge`, `\LARGE`, `\Large`, `\normalsize`, `\small`, `\footnotesize`, `\tiny`.
- Spacing is controlled using `\vspace{...}` for vertical gaps, `\hspace{...}` for horizontal gaps, and `\linespread{...}` for line spacing.

### Mathematical Typesetting
LaTeX excels at mathematical notation. It provides two modes:
1. **Inline Math**: Embedded inside sentences using `$ ... $` (e.g., `$E = mc^2$`).
2. **Display Math**: Centered on its own line using `\[ ... \]` or numbered via `\begin{equation}`.

Key math commands practiced:
- Fractions: `\frac{numerator}{denominator}`
- Radicals: `\sqrt{x}` and `\sqrt[n]{x}`
- Operators: `\int_{a}^{b}`, `\sum_{i=1}^{n}`, `\lim_{x \to 0}`, `\partial`
- Multi-line equations: The `align` environment aligns steps at the `&` symbol. The `multline*` environment breaks long single expressions across multiple lines without alignment anchors.
- Piecewise functions: Constructed using the `cases` environment.
- Matrices: Enclosed in `matrix` (plain), `pmatrix` (parentheses), `bmatrix` (square brackets), or `vmatrix` (determinants).

```latex
\begin{align*}
f(x) &= (x + 2)^2 - 4 \\
     &= x^2 + 4x + 4 - 4 \\
     &= x^2 + 4x
\end{align*}
```

### Tables
Tables are defined using the `tabular` environment inside a floating `table` container.
- Columns are declared using alignment specifiers: `l` (left), `c` (center), `r` (right), and `p{width}` (fixed width with automatic paragraph wrapping).
- Cells are separated by `&`, and rows are terminated by `\\`.
- `\multicolumn{num}{align}{text}` merges cells horizontally.
- `\multirow{num}{width}{text}` (from `multirow` package) merges cells vertically.
- **Booktabs**: Clean scientific tables avoid vertical lines and use `\toprule`, `\midrule`, `\bottomrule`, and `\cmidrule`.
- **Table Colors**: Using `\usepackage[table]{xcolor}`, rows can be colored with `\rowcolor`, cells with `\cellcolor`, and alternating rows with `\rowcolors`.

### Figures and the Picture Environment
- Figures are placed in a floating `\begin{figure}[htbp]` environment with `\caption{...}` and `\label{...}` for cross-referencing.
- Images are embedded via `\includegraphics[options]{path}`. Common options include `width=0.8\textwidth`, `scale=0.5`, `angle=90` (rotation), and `trim=l b r t, clip` (cropping).
- Side-by-side figures are arranged using `minipage` blocks placed next to each other inside a single `figure`.
- **Picture Environment**: LaTeX includes a built-in vector drawing environment (`\begin{picture}(width,height)`). Objects are placed at coordinates using `\put(x,y){...}`, supporting lines (`\line`), arrows (`\vector`), circles (`\circle`), and text boxes.

### Lists
- `itemize`: Unordered bulleted lists (bullets can be customized per item with `\item[*]`).
- `enumerate`: Ordered numbered lists (automatically adjusts from numbers to letters when nested).
- `description`: Definition lists with bold key labels (`\item[Label] Text`).
- `trivlist`: Low-level list environment used when custom paragraph formatting is needed without default list margins.

### Colors
Using the `xcolor` package:
- Basic colors (`red`, `blue`, `black`, `gray`).
- Custom colors: `\definecolor{myColor}{RGB}{12, 60, 120}`.
- Mixing and tints: `\colorlet{lightBlue}{blue!30}`.
- Usage: `\textcolor{color}{text}` for text, `\colorbox{color}{text}` for filled backgrounds, and `\fcolorbox{border}{fill}{text}` for framed boxes.

### Bibliography, Citations, and Indexing
The lab covered two citation systems:
1. **BibTeX + Natbib**: Stores citations in an external `.bib` file. Uses `\bibliographystyle{...}`, `\cite{...}`, and `\bibliography{filename}`. Compiled with: `pdflatex` -> `bibtex` -> `pdflatex` -> `pdflatex`.
2. **BibLaTeX + Biber**: Modern citation package. Loaded with `\usepackage[backend=biber]{biblatex}`, resources added with `\addbibresource{references.bib}`, and printed with `\printbibliography`. Compiled using `biber`.
3. **Indexing (`makeidx`)**: Words are indexed in text with `\index{topic}`. `\makeindex` runs during compilation, and `\printindex` outputs the alphabetical index.

### Boxes, Spacing, and References
- Boxes: `\parbox` creates mini inline text blocks; `\savebox` and `\usebox` allow defining a box once in memory and re-using it; `\rule{w}{h}` draws divider lines; `\fbox` draws frames.
- References: Elements labeled with `\label{marker}` are cross-referenced anywhere in the text using `\ref{marker}` or `\pageref{marker}`, and equations are referenced with `\eqref{marker}`.

---

## 2. Beamer

Beamer is a LaTeX document class used to create presentation slides. It compiles directly into a PDF presentation, ensuring equations, code snippets, and citations retain LaTeX's typesetting quality.

- **Class Declaration**: `\documentclass{beamer}`.
- **Themes**: Themes like `\usetheme{Madrid}` or `\usetheme{Warsaw}` define layout, colors, and navigation bars.
- **Frames**: Each slide is wrapped in a `\begin{frame}{Title}{Subtitle} ... \end{frame}` block.
- **Blocks**: Used to group and highlight content:
  - `block`: Standard colored container for definitions or key concepts.
  - `alertblock`: Red-tinted block for warnings and critical notes.
  - `exampleblock`: Green-tinted block for examples and code walk-throughs.
- **Layouts**: The `columns` environment with nested `column` blocks divides slides into two or more side-by-side columns (e.g. text next to a diagram).
- **Navigation and Footers**: Beamer automatically creates running footers showing author, topic, institute, and fractional slide numbers (`Slide X of Y`).

---

## 3. Doxygen

Doxygen is an automated documentation generator used for C++, C, Java, and Python projects. It reads structured comments written directly in source files and produces browsable HTML documentation and printable LaTeX/PDF manuals.

### Comment Syntax
- Multi-line block comments: `/** ... */` or `/*! ... */`
- Single-line comments: `///` or `//!`

### Standard Tags
- `@file`: Designates a file-level documentation block (mandatory for indexing the file).
- `@brief`: A short summary of a file, class, or function.
- `@author`, `@version`, `@date`: File metadata.
- `@class`: Documents a class and its responsibilities.
- `@param[in/out]`: Explains function parameters and direction.
- `@return`: Documents the return value and meaning.
- `@throw` or `@exception`: Notes exceptions that a function may raise.
- `@note`, `@warning`: Advisory callouts for developers using the API.

### Configuration and Build Workflow
1. Generate default configuration file:
   ```bash
   doxygen -g Doxyfile
   ```
2. Key `Doxyfile` parameters:
   - `PROJECT_NAME`: Title of the project.
   - `INPUT`: Source directories or files to parse.
   - `RECURSIVE`: Set to `YES` to scan nested subdirectories.
   - `GENERATE_HTML`: Enables interactive web documentation in `html/`.
   - `GENERATE_LATEX`: Enables LaTeX documentation in `latex/`.
3. Running Doxygen:
   ```bash
   doxygen Doxyfile
   ```
4. Compiling the PDF manual:
   ```bash
   cd latex
   pdflatex refman.tex
   ```
   This generates `refman.pdf`, a formatted technical reference manual.

---

## 4. Google Docs

Google Docs was covered in the course as a cloud-based collaborative writing platform for drafting technical papers, lab manuals, and reports.

### Key Capabilities Covered
- **Document Formatting and Hierarchy**: Using predefined paragraph styles (Normal text, Title, Heading 1, Heading 2, Heading 3) to enforce typographic consistency and generate an automatic Table of Contents with clickable links.
- **Real-time Collaboration**:
  - Permissions: Setting access roles (Viewer, Commenter, Editor).
  - Comments: Adding inline comments, tagging collaborators (`@name`), and resolving discussion threads.
  - Suggesting Mode: Tracking proposed additions and deletions that an owner can accept or reject.
  - Version History: Reviewing past document snapshots, comparing changes across revisions, and restoring earlier versions.
- **Technical Elements**:
  - Inserting equations using the built-in equation toolbar.
  - Inserting figures, setting text wrapping (In line, Wrap text, Break text), and adding captions.
  - Footnotes and bibliography tools for citing external literature.
  - Export options (PDF, DOCX, EPUB, plain text).

---

## 5. Git

Git is a distributed version control system designed to track changes in source code over time.

### The Three Areas of Git
1. **Working Directory**: The actual files on your machine where changes are actively made.
2. **Staging Area (Index)**: The intermediate area holding changes selected to be included in the next commit.
3. **Repository**: The permanent database inside the `.git` folder storing committed snapshots.

### Core Commands and Workflow
- **Initial Setup**:
  ```bash
  git config --global user.name "Your Name"
  git config --global user.email "your_email@example.com"
  git init
  ```
- **Staging and Committing**:
  ```bash
  git status              # View modified and untracked files
  git add <file>          # Stage file
  git add .               # Stage all modified files
  git commit -m "Message" # Commit snapshot
  ```
- **Inspecting Changes and History**:
  ```bash
  git diff                # Compare working tree vs staging area
  git diff --staged       # Compare staging area vs last commit
  git log --oneline       # Clean one-line commit log
  git log --all --graph   # Visual ASCII tree of commit branches
  ```
- **Undoing Mistakes Safely**:
  ```bash
  git restore <file>          # Discard changes in working directory
  git restore --staged <file> # Unstage file without losing code edits
  git revert <commit-hash>    # Create an opposite commit that inverts a past commit
  git rm <file>               # Untrack and delete file
  ```
- **Branching and Merging**:
  ```bash
  git branch <name>       # Create new branch
  git checkout <name>     # Switch to branch (or git switch <name>)
  git checkout -b <name>  # Create and switch in one command
  git merge <branch>      # Merge branch into active branch
  git branch -d <name>    # Safely delete merged branch
  ```
- **Resolving Merge Conflicts**: When two branches modify the same line, Git pauses the merge and inserts markers (`<<<<<<< HEAD`, `=======`, `>>>>>>>`). The conflict is resolved by editing the file manually to keep the desired code, removing the markers, running `git add`, and finishing with `git commit`.
- **Stashing**:
  ```bash
  git stash        # Shelve uncommitted local edits
  git stash list   # View stored stashes
  git stash pop    # Re-apply stashed edits and remove from stash list
  ```

---

## 6. GitHub

GitHub is a web-based hosting service for Git repositories that enables remote backup, code review, and team collaboration.

### Connecting Local and Remote Repositories
- Adding a remote repository URL:
  ```bash
  git remote add origin https://github.com/<username>/<repo-name>.git
  git remote -v
  ```
- Pushing the local branch to GitHub for the first time:
  ```bash
  git push -u origin master
  ```

### Synchronizing Repositories
- `git clone <url>`: Downloads an entire remote repository and its full commit history to a local folder.
- `git fetch`: Downloads new commits, branches, and tags from the remote without modifying local working files.
- `git pull`: Downloads remote changes and merges them into the current local branch immediately (`git fetch` followed by `git merge`).
- `git push`: Sends local committed snapshots to the remote branch.

### Collaborative Workflows
- **Feature Branch Workflow**: Developers create isolated topic branches locally, push them to GitHub (`git push origin feature-branch`), and keep `master`/`main` clean.
- **Pull Requests (PRs)**: A GitHub mechanism to propose changes from a feature branch into `main`. Team members can review the diff line by line, leave comments, run automated tests, and approve or request changes before merging.
- **Forking**: Creating a personal copy of someone else's repository on GitHub, making changes in the fork, and submitting a Pull Request back to the original project.

---

## Assignment Index

Individual lab documentation files detailing the practical exercises, source code implementation, and specific learnings:

- [Assignment 1: LaTeX Document Structure & Setup](assignments/Assign-1.md)
- [Assignment 2: Mathematical Typesetting](assignments/Assign-2.md)
- [Assignment 3: Advanced Math & Complex Tables](assignments/Assign-3.md)
- [Assignment 4: Lists, Colors, Figures & Floats](assignments/Assign-4.md)
- [Assignment 5: Technical Reports & Beamer Presentations](assignments/Assign-5.md)
- [Assignment 6: Modern Fonts, Boxes, Indexing & BibLaTeX](assignments/Assign-6.md)
- [Assignment 7: C++ Code Documentation with Doxygen](assignments/Assign-7.md)
- [Assignment 8: Version Control Fundamentals with Git](assignments/Assign-8.md)
- [Assignment 9: Branching, Merging, Conflicts & Stashing](assignments/Assign-9.md)

