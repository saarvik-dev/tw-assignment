# Assignment 9: Git Branching, Merging, Conflict Resolution, and Stashing

## Topics Covered
- Branching concepts and lightweight pointer mechanics
- Creating, switching, and renaming branches (`git branch`, `git checkout`, `git branch -m`)
- Parallel development workflows (feature branches and urgent bug fixes)
- Visualizing divergent commit histories (`git log --oneline --all --graph`)
- Branch merging (`git merge`)
- Identifying and resolving merge conflicts
- Conflict demarcation markers (`<<<<<<<`, `=======`, `>>>>>>>`)
- Safe branch deletion (`git branch -d`)
- Shelving uncommitted changes with `git stash` (`git stash`, `git stash list`, `git stash pop`)

## What I Learned
In this assignment, I learned how Git supports non-linear, collaborative development through branching and merging. Before this, all my commits were in a single straight line on `master`.

I learned that a Git branch is simply a lightweight, movable pointer to a commit. Creating a feature branch allowed me to work on new code in isolation without disturbing the stable code on `master`. I practiced switching between branches to simulate real development: committing progress on a feature branch, switching back to `master` to apply an urgent bug fix, and committing that fix independently.

Visualizing this with `git log --oneline --all --graph` helped me see how branches diverge. When I merged the feature branch back into `master`, I intentionally triggered and resolved a merge conflict. I learned that merge conflicts happen when two branches modify the exact same lines. Rather than guessing, Git halts the merge and inserts markers (`<<<<<<< HEAD`, `=======`, `>>>>>>>`). I learned to open the file, decide which lines to keep, remove the markers, stage the resolved file, and finalize the merge commit.

Finally, I practiced using `git stash`. Stashing is useful when you have half-finished edits in your working directory and need to switch branches immediately. Instead of making a rushed commit, `git stash` tucks the changes away safely and cleans the working directory, and `git stash pop` restores them when you return.

## Important Commands and Concepts

### Branch Management
```bash
# List all local branches
git branch

# Create a new branch
git branch feature-auth

# Switch to the new branch
git checkout feature-auth

# Shortcut to create and switch in one step
git checkout -b feature-auth

# Rename a branch
git branch -m old-name new-name

# Delete a branch safely after merging
git branch -d feature-auth
```

### Visualizing Branch History
```bash
# View complete visual commit tree across all branches
git log --oneline --all --graph
```

### Merging and Handling Conflicts
To merge `feature-auth` into `master`:
```bash
git checkout master
git merge feature-auth
```

If both branches touched the same lines, Git marks the conflict:
```text
<<<<<<< HEAD
std::cout << "Version 1.1 - Hotfix Applied\n";
=======
std::cout << "Version 1.1 - Feature Enabled\n";
>>>>>>> feature-auth
```

To resolve:
1. Open the file and manually edit it to the desired final state.
2. Remove all conflict markers (`<<<<<<<`, `=======`, `>>>>>>>`).
3. Stage the resolved file:
```bash
git add main.cpp
```
4. Complete the merge commit:
```bash
git commit -m "Merge feature-auth and resolve conflict in main.cpp"
```

### Temporary Work Shelving with Stash
```bash
# Shelve uncommitted working tree and staged changes
git stash

# View all stashed entries
git stash list

# Re-apply the most recently stashed changes and remove them from the stash stack
git stash pop

# Inspect stash options and documentation
git help stash
```

