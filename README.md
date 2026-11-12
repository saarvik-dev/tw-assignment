# Technical Writing Lab: Documentation Index

This repository contains the complete documentation for the Technical Writing Lab course at Malaviya National Institute of Technology (MNIT) Jaipur, Department of Computer Science and Engineering.

The documentation is organized into two sections:
1. **Topic-wise Documentation**: Comprehensive guides covering each major technology and concept taught during the course.
2. **Assignment-wise Documentation**: Practical reports detailing the specific exercises, source code implementation, and learnings from each lab assignment.

---

## 1. Topic-wise Documentation

Detailed guides based on course lectures (`PPTs/`), question papers (`Assignments QP/`), and practical implementations (`Assignments/`):

- [LaTeX](documentation/topics/LaTeX.md)  
  Document structure, document classes (`article`, `report`, `book`), section hierarchy, mathematical typesetting, tables, graphics, lists, colors, boxes, citations (BibTeX and BibLaTeX), and book indexing (`makeidx`).

- [Beamer](documentation/topics/Beamer.md)  
  Creating technical presentation slides in LaTeX using Beamer, presentation themes (`Madrid`), frames, slide structure, blocks (`block`, `alertblock`, `exampleblock`), multi-column layouts, custom footlines, and compilation.

- [Doxygen](documentation/topics/Doxygen.md)  
  Automated source code documentation for C++, comment formats (`/** ... */`, `///`), structural tags (`@file`, `@class`, `@param`, `@return`, `@warning`), `Doxyfile` configuration, and generating interactive HTML and printable LaTeX/PDF reference manuals.

- [Google Docs](documentation/topics/Google-Docs.md)  
  Cloud-based technical writing and real-time collaboration, paragraph styles and automatic Table of Contents, sharing permissions, suggestions (track changes), comment workflows, version history, math equations, and native citation management.

- [Git](documentation/topics/Git.md)  
  Core version control architecture (Working Directory, Staging Area, Local Repository), initializing repositories, staging and committing, inspecting diffs and commit history, undoing changes (`git restore`, `git revert`), branching, merging, conflict resolution, and temporary work shelving with `git stash`.

- [GitHub](documentation/topics/GitHub.md)  
  Remote repository hosting, differences between Git and GitHub, connecting local repositories, remote synchronization (`clone`, `push`, `pull`, `fetch`), the Feature Branch Workflow, Pull Requests (PRs), code reviews, and forking.

---

## 2. Assignment-wise Documentation

Practical lab writeups describing the specific source code, tools, and exercises implemented throughout the semester:

- [Assignment 1: LaTeX Document Structure & Setup](documentation/assignments/Assign-1.md)  
  Document skeleton, `article` class, section hierarchy, font sizing, inline/display math formulas ($E=mc^2$ and Schrödinger equation), and the multi-pass BibTeX / `natbib` compilation workflow.

- [Assignment 2: Mathematical Typesetting](documentation/assignments/Assign-2.md)  
  Mathematical expressions using `amsmath` and `amssymb`, inline vs display math, calculus notations, multi-line equations (`align`, `multline*`), and matrices (`pmatrix`, `bmatrix`, `vmatrix`).

- [Assignment 3: Advanced Math & Complex Tables](documentation/assignments/Assign-3.md)  
  Piecewise functions (`cases`), equation annotations (`\overbrace`, `\underbrace`), `\phantom` alignment, fixed-width table column wrapping (`p{width}`), cell merging (`\multicolumn`, `\multirow`), publication-grade tables (`booktabs`), and row/cell coloring.

- [Assignment 4: Lists, Colors, Figures & Floats](documentation/assignments/Assign-4.md)  
  List environments (`itemize`, `enumerate`, `description`), color management with `xcolor`, floating `figure` environments, image manipulation (`scale`, `angle`, `trim`, `clip`), and side-by-side subfigures using `minipage`.

- [Assignment 5: Technical Reports & Beamer Presentations](documentation/assignments/Assign-5.md)  
  Formal academic report writing (`report` class, title page, abstract, `sectsty` heading colors, `fancyhdr` headers/footers) and Beamer presentation slides using the `Madrid` theme, frames, blocks, and column layouts.

- [Assignment 6: Modern Fonts, Boxes, Indexing & BibLaTeX](documentation/assignments/Assign-6.md)  
  Modern font loading under XeLaTeX with `fontspec`, alphabetic section counters, low-level box mechanics (`\parbox`, `\savebox`, `\rule`), book indexing with `makeidx`, and citations using `biblatex` and `biber`.

- [Assignment 7: C++ Code Documentation with Doxygen](documentation/assignments/Assign-7.md)  
  Documenting a multi-file C++ project (`CalculationEngine.h`, `Logger.h`, `main.cpp`) with Doxygen comment tags, configuring `Doxyfile`, and generating HTML and PDF manuals.

- [Assignment 8: Version Control Fundamentals with Git](documentation/assignments/Assign-8.md)  
  Version control setup, Git's three-stage architecture, staging modifications, committing snapshots, viewing diffs and logs, undoing changes safely (`git restore`, `git revert`), and checking out past commits in detached HEAD state.

- [Assignment 9: Branching, Merging, Conflicts & Stashing](documentation/assignments/Assign-9.md)  
  Non-linear workflows with Git branches, parallel development, merging, detecting and resolving merge conflicts (`<<<<<<<`, `=======`, `>>>>>>>`), commit tree visualization (`git log --oneline --all --graph`), and shelving work with `git stash`.

---

## Repository Structure

```text
tw_assignment/
├── Assignments/
│   ├── Assign 1/
│   ├── Assign 2/
│   ├── Assign 3/
│   ├── Assign 4/
│   ├── Assign 5/
│   ├── Assign 6/
│   ├── Assign 7/
│   ├── Assign 8/
│   └── Assign 9/
├── Assignments QP/
├── documentation/
│   ├── assignments/
│   │   ├── Assign-1.md
│   │   ├── Assign-2.md
│   │   ├── Assign-3.md
│   │   ├── Assign-4.md
│   │   ├── Assign-5.md
│   │   ├── Assign-6.md
│   │   ├── Assign-7.md
│   │   ├── Assign-8.md
│   │   └── Assign-9.md
│   └── topics/
│       ├── LaTeX.md
│       ├── Beamer.md
│       ├── Doxygen.md
│       ├── Google-Docs.md
│       ├── Git.md
│       └── GitHub.md
├── PPTs/
└── README.md
```
