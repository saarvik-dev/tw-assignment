# Google Docs: Cloud-Based Collaborative Documentation

Google Docs is a cloud-based word processor included in Google Workspace. In our Technical Writing Lab curriculum, Google Docs was studied as a collaborative platform for drafting technical proposals, team reports, and project specifications. 

While tools like LaTeX and Doxygen focus on code-based compilation and local version control, Google Docs provides real-time multi-user editing, visual commenting, and cloud synchronization directly inside a web browser.

---

## 1. Document Creation and Structuring

A technical document in Google Docs can be started from a blank page or initialized from predefined templates (such as Project Proposals, Meeting Notes, or Technical Reports).

### Paragraph Styles and Document Hierarchy
Consistent typography in Google Docs is managed using built-in paragraph styles:
- **Title** and **Subtitle**: For document cover information.
- **Heading 1**, **Heading 2**, and **Heading 3**: For major chapters, sections, and sub-sections.
- **Normal Text**: For standard body paragraphs.

Using formal heading styles rather than manually changing font size and bolding provides two major advantages:
1. **Automatic Table of Contents**: Navigating to `Insert -> Table of contents` generates an outline with clickable page numbers or jump-links that automatically syncs whenever headings change.
2. **Document Outline Panel**: Displays a clickable sidebar navigation tree on the left side of the screen, making long documents easy to navigate.

---

## 2. Text Formatting and Page Setup

### Text Styling
- Font selections (e.g. Arial, Times New Roman, Roboto, or monospace fonts like Courier New / Consolas for code snippets).
- Alignment controls (Left, Center, Right, Justified).
- Line spacing (Single, 1.15, 1.5, Double) and custom paragraph spacing (Add space before/after paragraph).

### Headers, Footers, and Page Numbering
Under `Insert -> Headers & footers` and `Insert -> Page numbers`:
- **Different First Page**: Allows hiding headers/footers on the title page.
- **Page Numbers**: Configured as `Page X of Y`, top-right, or bottom-center.
- Running headers often hold the project title or document classification.

---

## 3. Tables, Lists, and Media Elements

### Tables
Tables are added via `Insert -> Table` by selecting the desired grid dimension (rows $\times$ columns):
- Used for presenting experimental results, project schedules, and comparing design alternatives.
- Cells can be merged, background colors can be applied to header rows, and column widths can be adjusted manually.

### Lists and Checklists
- **Bulleted Lists**: Standard unordered points with customizable marker icons.
- **Numbered Lists**: Ordered sequential instructions.
- **Checklists**: Interactive checkboxes useful for tracking team action items and review checklists during document preparation.

### Images, Drawings, and Diagrams
- **Images**: Added via `Insert -> Image` from local upload, Google Drive, URL, or search. Text wrapping modes include *In line*, *Wrap text*, and *Break text*.
- **Google Drawings**: Added via `Insert -> Drawing -> New`. Provides a built-in vector canvas to draw flowchart shapes, process boxes, callout arrows, and simple system diagrams without leaving the document.
- **Third-Party Diagrams**: Integrations with tools like Lucidchart and Diagrams.net (Draw.io) allow importing professional architecture diagrams.

### Mathematical Equations
Google Docs includes a graphical equation editor accessed via `Insert -> Equation`:
- Displays an equation toolbar with mathematical symbols, Greek letters, relations, and operations.
- Accepts basic LaTeX shortcut syntax (for example, typing `\frac` followed by a space automatically creates a fraction box).

---

## 4. Real-Time Collaboration and Sharing

Collaboration is one of Google Docs' primary strengths for team engineering projects.

### Sharing Permissions
Clicking the **Share** button allows granting access via email address or a shareable link with three distinct permission levels:
1. **Viewer**: Read-only access. Cannot edit or comment.
2. **Commenter**: Can view the document and leave comments or suggestions, but cannot directly alter the text.
3. **Editor**: Full read and write access to modify content directly.

Permissions can be revoked at any time, or given automatic expiration dates.

### Live Co-Authoring
Multiple team members can open and edit the same document simultaneously:
- Each collaborator is assigned a unique colored cursor showing their name and current editing position in real time.
- Changes are saved continuously to Google Drive without requiring manual save shortcuts (`Ctrl + S`).

---

## 5. Comments, Suggestions, and Review Workflow

Google Docs provides review tools that mirror code review workflows:

### Comments
- Select text and press `Ctrl + Alt + M` (or click `Insert -> Comment`).
- Collaborators can reply to comments to create an active discussion thread.
- Collaborators can be assigned explicit tasks by tagging them: `@colleague_email`, which sends an email notification.
- Once addressed, clicking **Resolve** closes the thread and archives it.

### Suggesting Mode (Track Changes)
In the top right toolbar, switching from **Editing** to **Suggesting** mode turns edits into tracked proposals:
- Added text appears in a highlight color with a marginal note.
- Deleted text is shown with a strikethrough rather than disappearing.
- The document owner or lead reviewer can accept (checkmark) or reject (cross) each change individually.

---

## 6. Version History and Recovery

Because Google Docs saves changes automatically, accidental deletions or unwanted edits can be recovered through **Version History** (`File -> Version history -> See version history`):
- Displays a chronological list of revisions timestamped by date, time, and user.
- Allows comparing the current document against any previous snapshot.
- Any past version can be restored with a single click (**Restore this version**).
- **Named Milestones**: Important project stages (e.g. "Draft 1 Submission", "Instructor Review", "Final Approved Version") can be named explicitly so they can be referenced easily later.

---

## 7. Citations and Bibliography

For technical writing, Google Docs provides a native citation manager under `Tools -> Citations`:
- Supports standard academic citation styles: **APA**, **MLA**, and **Chicago**.
- Users can add reference sources (books, websites, journal articles) by entering author names, titles, and publication years.
- In-text citations (e.g., `(Griffiths, 2018)`) can be inserted next to text with one click.
- An automatic **Bibliography** or **Works Cited** section can be generated at the end of the document.
- Integrations with dedicated reference managers like Zotero or Mendeley are also supported via Workspace add-ons.

---

## 8. Exporting and Publishing

Once a document is finalized, it can be exported in several industry-standard formats under `File -> Download`:
- **PDF Document (`.pdf`)**: Preserves exact layout for submissions and printing.
- **Microsoft Word (`.docx`)**: For offline editing and sharing with external organizations.
- **OpenDocument Format (`.odt`)**: For open-source office suites.
- **Plain Text (`.txt`)** and **Web Page (`.html`)**: For digital distribution.
- **Publish to the Web**: Generates a public lightweight web URL that stays updated whenever the document is edited.

---

## 9. Comparison: Doxygen vs. Google Docs

As covered in the lecture slides (`PPTs/Doxygen.pdf`), both tools serve different but complementary roles in technical documentation:

| Feature | Doxygen | Google Docs |
| :--- | :--- | :--- |
| **Primary Purpose** | Automated API and code reference manuals | Collaborative reports, proposals, and design docs |
| **Source Material** | Comments extracted directly from source code | Manually written structured text |
| **Collaboration** | Indirect (Git commits, pull requests, code reviews) | Direct, simultaneous real-time multi-user editing |
| **Rich Media** | Class graphs, caller diagrams, Markdown | Tables, Google Drawings, embedded images, checklists |
| **Output Formats** | Searchable HTML, compiled LaTeX/PDF manuals | PDF, DOCX, web pages, ODT |
| **Best Used For** | Keeping developer code documentation in sync | Brainstorming, team design docs, meeting notes |

In an engineering workflow, teams often use both: Google Docs is used to collaborate on initial requirements and architecture design, while Doxygen is used to document the resulting codebase.

