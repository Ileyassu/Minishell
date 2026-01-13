# 🐚 Minishell

A lightweight Unix shell implementation written in C, developed as part of the 42 curriculum.

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)

---

## 📋 Table of Contents

- [About](#-about)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Built-in Commands](#-built-in-commands)
- [Operators](#-operators)
- [Examples](#-examples)
- [Project Structure](#-project-structure)
- [How It Works](#-how-it-works)
- [Author](#-author)

---

## 📖 About

Minishell is a simple shell program that replicates core functionalities of Bash. It provides a command-line interface where users can execute commands, manage environment variables, handle redirections, and create pipelines.

This project demonstrates understanding of:
- Process creation and management (`fork`, `execve`, `wait`)
- File descriptors and I/O redirection
- Signal handling
- Lexical analysis and parsing
- Environment variable management

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| **Command Execution** | Run any executable from PATH or by absolute/relative path |
| **Built-in Commands** | 7 built-in commands implemented |
| **Pipes** | Chain multiple commands with `\|` |
| **Redirections** | Input (`<`), output (`>`), append (`>>`), heredoc (`<<`) |
| **Environment Variables** | Expand `$VAR` and `$?` (exit status) |
| **Quote Handling** | Single quotes (literal) and double quotes (with expansion) |
| **Signal Handling** | Proper handling of `Ctrl+C`, `Ctrl+D`, `Ctrl+\` |
| **Command History** | Navigate previous commands with arrow keys |

---

## 🔧 Installation

### Prerequisites

- **GCC** compiler
- **GNU Make**
- **readline** library

```bash
# Install readline on Debian/Ubuntu
sudo apt-get install libreadline-dev

# Install readline on macOS
brew install readline
```

### Build

```bash
# Clone the repository
git clone <repository-url>
cd Minishell

# Compile the project
make

# Run the shell
./minishell
```

### Makefile Commands

| Command | Description |
|---------|-------------|
| `make` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executable |
| `make re` | Recompile from scratch |

---

## 🚀 Usage

After launching Minishell, you'll see a prompt displaying your current directory. Enter commands just like you would in Bash:

```bash
$ ./minishell
~/Minishell$ ls -la
~/Minishell$ echo "Hello, World!"
~/Minishell$ exit
```

### Exiting the Shell

- Type `exit` to quit
- Press `Ctrl+D` to exit

---

## 📌 Built-in Commands

| Command | Description | Usage |
|---------|-------------|-------|
| `echo` | Display text | `echo [-n] [text...]` |
| `cd` | Change directory | `cd [path]` |
| `pwd` | Print working directory | `pwd` |
| `export` | Set environment variable | `export [NAME=value]` |
| `unset` | Remove environment variable | `unset [NAME...]` |
| `env` | Display environment | `env` |
| `exit` | Exit the shell | `exit [status]` |

### Command Details

#### echo
```bash
$ echo Hello World           # Prints: Hello World
$ echo -n "No newline"       # Prints without trailing newline
$ echo $HOME                 # Prints home directory path
```

#### cd
```bash
$ cd /tmp                    # Change to /tmp
$ cd                         # Change to home directory
$ cd -                       # Change to previous directory
$ cd ..                      # Go up one directory
```

#### export
```bash
$ export                     # Display all exported variables (sorted)
$ export VAR=value           # Set variable
$ export VAR+=more           # Append to existing variable
```

---

## 🔀 Operators

### Pipes (`|`)

Connect the output of one command to the input of another:

```bash
$ ls -la | grep ".c"
$ cat file.txt | wc -l
$ ps aux | grep bash | head -5
```

### Redirections

| Operator | Description | Example |
|----------|-------------|---------|
| `<` | Redirect input | `cat < file.txt` |
| `>` | Redirect output (overwrite) | `echo "text" > file.txt` |
| `>>` | Redirect output (append) | `echo "more" >> file.txt` |
| `<<` | Heredoc (read until delimiter) | `cat << EOF` |

#### Heredoc Example
```bash
$ cat << END
> This is line 1
> This is line 2
> END
This is line 1
This is line 2
```

---

## 💡 Examples

### Basic Commands
```bash
$ ls -la                     # List files
$ pwd                        # Print current directory
$ whoami                     # Show current user
```

### Using Variables
```bash
$ export NAME="Minishell"
$ echo "Welcome to $NAME"    # Prints: Welcome to Minishell
$ echo '$NAME'               # Prints: $NAME (literal)
$ unset NAME
```

### Exit Status
```bash
$ ls existing_file
$ echo $?                    # Prints: 0 (success)
$ ls nonexistent_file
$ echo $?                    # Prints: 2 (error)
```

### Complex Pipelines
```bash
$ cat /etc/passwd | grep root | cut -d: -f1
$ ls -la | awk '{print $9}' | sort | head -10
```

### Combined Redirections
```bash
$ cat < input.txt > output.txt
$ grep "error" < log.txt >> errors.txt
$ cat << EOF > file.txt
> Content goes here
> EOF
```

---

## 📁 Project Structure

```
Minishell/
├── main.c                 # Entry point, REPL loop
├── Makefile               # Build configuration
├── lexer/                 # Tokenization
│   ├── lexer.h            # Token definitions
│   ├── get_token.c        # Token extraction
│   ├── ft_expand_var.c    # Variable expansion
│   └── ...
├── parsing/               # AST construction
│   ├── parser.h           # Parser structures
│   ├── parser_start.c     # Parse entry point
│   ├── ft_pipe_line.c     # Pipeline parsing
│   └── ...
├── execution/             # Command execution
│   ├── execution.h        # Execution declarations
│   ├── execution.c        # Main execution logic
│   └── builtins/          # Built-in commands
│       ├── echo.c
│       ├── cd/
│       ├── pwd.c
│       ├── export/
│       ├── unset.c
│       ├── env.c
│       └── exit.c
├── redirection/           # I/O handling
│   ├── redirection.c
│   ├── heredoc.c
│   └── ...
├── env1/                  # Environment management
│   ├── env.h
│   ├── create_env.c
│   └── ...
├── utils/                 # Utility functions
└── libft/                 # Custom C library
```

---

## 🔬 How It Works

### Execution Flow

```
┌─────────────┐     ┌─────────────┐     ┌─────────────┐     ┌─────────────┐
│   Input     │────▶│   Lexer     │────▶│   Parser    │────▶│  Executor   │
│  (readline) │     │ (tokenize)  │     │ (build AST) │     │  (run cmd)  │
└─────────────┘     └─────────────┘     └─────────────┘     └─────────────┘
```

1. **Input**: The shell reads input using the readline library
2. **Lexer**: Converts input string into tokens (words, operators, etc.)
3. **Parser**: Builds an Abstract Syntax Tree (AST) from tokens
4. **Executor**: Traverses the AST and executes commands

### Key Concepts

- **Lexical Analysis**: Input is tokenized while respecting quotes and special characters
- **AST (Abstract Syntax Tree)**: Commands and pipes form a tree structure for execution
- **Fork-Exec**: External commands run in child processes via `fork()` + `execve()`
- **Pipes**: Created with `pipe()`, connecting stdout to stdin between processes

---

## 🎯 Signal Handling

| Signal | Interactive Mode | During Execution |
|--------|-----------------|------------------|
| `Ctrl+C` (SIGINT) | New prompt | Terminate command |
| `Ctrl+\` (SIGQUIT) | Ignored | Core dump |
| `Ctrl+D` | Exit shell | EOF |

---

## ⚠️ Limitations

- No support for `&&` and `||` operators
- No wildcards (`*`) expansion
- No command substitution (`$(...)`)
- No arithmetic expansion
- Single command line only (no scripts)

---

## 🧪 Testing

Test the shell with various inputs:

```bash
# Test builtins
echo "test" && pwd && env

# Test pipes
ls | cat | wc

# Test redirections
echo "hello" > /tmp/test.txt
cat < /tmp/test.txt

# Test quotes
echo "Hello $USER"
echo 'Hello $USER'

# Test exit status
false
echo $?
```

---

## 📚 Resources

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [The Open Group - Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

---

## 👤 Author

**ibenaiss** - 42 Student

---

## 📄 License

This project is part of the 42 school curriculum.

---

<p align="center">
  Made with ❤️ and lots of ☕
</p>
