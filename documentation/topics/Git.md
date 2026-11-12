# Git: Version Control Fundamentals and Workflows

Git is a distributed version control system (VCS) that tracks changes made to files in a project over time. Unlike simply saving copies of folders with names like `project_v1` and `project_final`, Git records deliberate, cryptographically verifiable snapshots of the entire repository history. This allows developers to track modifications, revert mistakes, experiment safely on isolated branches, and collaborate without overwriting each other's work.

---

## 1. Core Architecture: The Three Git Areas

Understanding Git requires understanding how it tracks files across three primary areas:

```text
+---------------------+       git add       +---------------------+
|                     | ------------------> |                     |
|  Working Directory  |                     |  Staging Area       |
|  (Local edits)      | <------------------ |  (Index snapshot)   |
|                     |    git restore      |                     |
+---------------------+     --staged        +---------------------+
        |                                              |
        | git restore                                  | git commit
        v                                              v
(Discard uncommitted)                       +---------------------+
                                            |                     |
                                            |  Local Repository   |
                                            |  (.git database)    |
                                            |                     |
                                            +---------------------+
```

1. **Working Directory**: The actual files on disk that you edit in an editor or IDE. Files here can be untracked or modified.
2. **Staging Area (Index)**: An intermediate staging environment where you assemble the exact set of changes intended for the next commit snapshot.
3. **Local Repository (`.git`)**: The permanent local database storing the full compressed history of commits, tree objects, and branch references.

---

## 2. Setting Up and Initializing a Repository

Before creating commits, Git must be configured with an author identity:

```bash
# Set author information globally
git config --global user.name "Saarvik Singh Suryavanshi"
git config --global user.email "2025ucp1681@mnit.ac.in"

# Verify configured settings
git config --list
```

To transform an existing project folder into a tracked Git repository:
```bash
git init
```
This creates a hidden `.git/` subdirectory containing Git's object database and default `master` (or `main`) branch pointer.

---

## 3. Basic Staging and Committing Workflow

### Checking Status
The most frequently used command is `git status`, which displays the current branch and categorizes files into:
- **Untracked**: New files that Git does not yet monitor.
- **Modified**: Tracked files containing unstaged edits.
- **Staged**: Changes queued in the index ready to be committed.

```bash
git status
```

### Staging Changes
- Stage a single file: `git add CalculationEngine.h`
- Stage all modified and new files: `git add .`

### Committing Snapshots
A commit permanently records staged changes into repository history with a mandatory descriptive message:
```bash
git commit -m "Implement power calculation with negative exponent handling"
```

---

## 4. Inspecting Changes and History

### Inspecting Line Diffs
Before committing, reviewing exact line changes helps prevent accidental typos:
- `git diff`: Compares unstaged modifications in the working tree against the staging area.
- `git diff --staged`: Compares staged changes against the most recent commit snapshot (`HEAD`).

Lines added begin with `+` in green, while lines removed begin with `-` in red.

### Viewing Commit History
- `git log`: Displays full commit history including 40-character SHA-1 hashes, author, timestamp, and commit messages.
- `git log --oneline`: Formats each commit as a single line with an abbreviated 7-character hash and message.
- `git log -n 5`: Limits the output to the 5 most recent commits.
- `git log --oneline --all --graph`: Draws a visual ASCII branch tree showing divergent and merged commit paths.

---

## 5. Undoing Changes Safely

Different Git commands are used depending on which area the unwanted change resides in:

### Discarding Unstaged Changes (`git restore`)
If you made local edits in your working directory and want to throw them away to match the last commit:
```bash
git restore main.cpp
```
*Note: This overwrites local uncommitted changes irrevocably.*

### Unstaging Files (`git restore --staged`)
If you accidentally staged a file with `git add` but do not want it in the next commit:
```bash
git restore --staged main.cpp
```
This moves the file back to the unstaged working directory without losing any of your written code.

### Reverting Committed Changes (`git revert`)
If a commit was already committed and pushed, altering or deleting past history is dangerous for collaborators. Instead, `git revert` computes the inverse of a past commit and creates a new commit that undoes the changes:
```bash
git revert 4f8a12c
```
This safely keeps project history intact while reversing unwanted code.

### Removing Tracked Files (`git rm`)
To delete a file from disk and stage its deletion in Git simultaneously:
```bash
git rm old_module.cpp
```

### Time Travel with Detached HEAD
To inspect what the codebase looked like at an earlier commit:
```bash
git checkout 4f8a12c
```
This places the repository into a **detached HEAD** state, meaning `HEAD` points directly to a commit hash rather than a branch name. You can compile and test past code safely. To return to current work:
```bash
git checkout master
```

---

## 6. Branching, Merging, and Conflict Resolution

Branching is one of Git's most powerful features. A branch is not a duplicate copy of files; it is simply a lightweight, movable pointer pointing to a specific commit.

### Branch Operations
- List all local branches: `git branch`
- Create a new branch: `git branch feature-logging`
- Switch to a branch: `git checkout feature-logging` (or `git switch feature-logging`)
- Create and switch in one step: `git checkout -b feature-logging`
- Rename a branch: `git branch -m old-name new-name`
- Safely delete a merged branch: `git branch -d feature-logging`
- Force delete an unmerged branch: `git branch -D feature-logging`

### Merging Branches
To bring changes from a feature branch into `master`:
```bash
git checkout master
git merge feature-logging
```
If no conflicting changes occurred on `master` in the meantime, Git performs a **fast-forward** merge, simply moving the `master` pointer forward.

### Handling Merge Conflicts
When two branches modify the exact same lines of a file, Git cannot automatically guess which version is correct. It pauses the merge and annotates the conflicting file with conflict markers:

```text
<<<<<<< HEAD
std::cout << "Engine Version 1.0 (Master Hotfix)\n";
=======
std::cout << "Engine Version 1.1 (Logging Feature)\n";
>>>>>>> feature-logging
```

- Content between `<<<<<<< HEAD` and `=======` is the version on your active branch (`master`).
- Content between `=======` and `>>>>>>> feature-logging` is the version from the incoming branch.

**Resolution Steps**:
1. Open the file in an editor.
2. Manually select or combine the correct code and delete all markers (`<<<<<<<`, `=======`, `>>>>>>>`).
3. Stage the resolved file:
   ```bash
   git add main.cpp
   ```
4. Finalize the merge by making a commit:
   ```bash
   git commit -m "Merge feature-logging and resolve version conflict in main.cpp"
   ```

---

## 7. Temporary Work Shelving: `git stash`

When working on a feature branch, you may suddenly need to switch to `master` to test a bug, but your working directory has half-written, uncommitted edits. Git will block branch switching if those changes would be overwritten.

Rather than making an incomplete, messy commit, `git stash` saves all uncommitted modifications onto a temporary local stack and restores the working directory to a clean `HEAD` state:

```bash
# Shelve uncommitted modifications
git stash

# View list of saved stashes
git stash list

# Switch to master and do urgent work
git checkout master
# ... fix bug and commit ...

# Return to feature branch and re-apply stashed work
git checkout feature-logging
git stash pop
```
- `git stash pop`: Restores the most recently stashed changes and deletes them from the stash stack.
- `git stash apply`: Restores changes while preserving the stash on the stack.
- `git help stash`: Displays the complete reference manual for advanced stashing options.

---

## 8. Git Command Quick Reference

| Command | Action / Purpose | Example |
| :--- | :--- | :--- |
| `git init` | Initializes a new local Git repository | `git init` |
| `git config` | Sets global or repository-level user settings | `git config --global user.name "Name"` |
| `git status` | Displays working tree and staging area state | `git status` |
| `git add` | Stages files for the next commit snapshot | `git add .` |
| `git commit` | Records staged snapshot to repository history | `git commit -m "Add unit tests"` |
| `git diff` | Shows unstaged line-by-line differences | `git diff` |
| `git diff --staged` | Shows differences staged for the next commit | `git diff --staged` |
| `git log --oneline` | Displays compact one-line commit log | `git log --oneline -n 10` |
| `git restore` | Discards unstaged modifications in working tree | `git restore main.cpp` |
| `git restore --staged` | Unstages a file while keeping file edits | `git restore --staged main.cpp` |
| `git revert` | Safely inverts a past commit with a new commit | `git revert a1b2c3d` |
| `git rm` | Deletes file from disk and stages deletion | `git rm temp.log` |
| `git branch` | Lists, creates, or deletes branch pointers | `git branch new-feature` |
| `git checkout` / `switch` | Switches active working branch or commit | `git checkout master` |
| `git merge` | Combines another branch into active branch | `git merge feature-branch` |
| `git stash` | Temporarily shelves uncommitted changes | `git stash` |
| `git stash pop` | Restores shelved changes to working tree | `git stash pop` |

