# Assignment 8: Version Control Fundamentals with Git

## Topics Covered
- Version control concepts and the Git architecture
- The three Git states: Working Directory, Staging Area, and Repository
- Global user configuration (`git config`)
- Initializing a local repository (`git init`)
- Tracking files and staging modifications (`git status`, `git add`)
- Committing snapshots (`git commit`)
- Inspecting uncommitted line changes (`git diff`, `git diff --staged`)
- Viewing commit history (`git log`, `git log --oneline`)
- Undoing changes safely (`git restore`, `git restore --staged`, `git revert`)
- Deleting tracked files (`git rm`)
- Historical checkouts and detached HEAD state (`git checkout <hash>`, `git checkout master`)

## What I Learned
In this assignment, I learned the core concepts of version control using Git from the command line. Before this lab, I thought of version control as just making backup copies of files. Working through these exercises showed me that Git records discrete, verifiable snapshots of the entire project history.

I understood Git's three-stage mental model:
1. **Working Directory**: The actual files on disk that I edit.
2. **Staging Area (Index)**: The preparation area where I choose which changes to include in the next snapshot.
3. **Repository**: The permanent `.git` history storing all committed snapshots.

I practiced checking repository status frequently with `git status` and inspecting exact line additions and deletions with `git diff`. I also learned how to correct mistakes safely: using `git restore` to discard uncommitted experiments in the working directory, using `git restore --staged` to remove a file from the staging area without losing my code, and using `git revert` to reverse a past commit by creating an opposite commit without rewriting or corrupting project history.

Finally, I experimented with time-traveling through project history by checking out an older commit hash (`git checkout <hash>`), which entered a detached HEAD state where I could inspect older code, before safely returning to the current branch tip with `git checkout master`.

## Important Commands and Concepts

### Setup and Configuration
```bash
# Configure identity for commit attribution
git config --global user.name "Saarvik Singh Suryavanshi"
git config --global user.email "2025ucp1681@mnit.ac.in"

# Verify current settings
git config --list
```

### Initializing and Committing
```bash
# Initialize a new Git repository in the current folder
git init

# Check status of untracked and modified files
git status

# Stage specific file or all modified files
git add main.cpp
git add .

# Create a permanent commit snapshot
git commit -m "Implement calculation engine module"
```

### Inspecting Changes
- `git diff`: Compares modifications in the working directory against the staging area.
- `git diff --staged`: Compares staged changes against the most recent commit.
- `git log --oneline`: Displays commit history as a clean, compact one-line summary.

### Undoing and Reverting Changes
```bash
# Discard uncommitted changes in a specific file
git restore main.cpp

# Unstage a file while keeping its changes in the working directory
git restore --staged main.cpp

# Safely invert a specific commit by creating a new reversing commit
git revert 4f8a12c

# Remove a file from both disk and Git tracking
git rm old_file.cpp
```

### Historical Checkouts
```bash
# Inspect repository state at an older commit (detached HEAD)
git checkout 4f8a12c

# Return back to the tip of master branch
git checkout master
```

