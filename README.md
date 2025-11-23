<div align="center">

# 📁 ft_ls

### A Complete Recreation of the Unix `ls` Command

![Build](https://img.shields.io/badge/build-passing-brightgreen?style=for-the-badge) 
![Status](https://img.shields.io/badge/status-operational-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/license-MIT-blue?style=for-the-badge)

<img src="https://iili.io/fFZjPUb.png" alt="ft_ls screenshot" width="800"/>

*Implementation of the Unix `ls` utility in C, following strict coding standards*

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Platform Support](#-platform-support)

</div>

---

## 📖 About

**ft_ls** is a faithful recreation of the Unix `ls` command, developed as part of the 42 School curriculum. This project demonstrates deep understanding of:

- 🔍 File system navigation and directory traversal
- 📊 POSIX file metadata manipulation
- 🎨 Terminal color output and formatting
- ⚡ Efficient sorting algorithms
- 🔄 Recursive directory processing

Developed with strict adherence to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf).

---

## ✨ Features

### Core Functionality

| Flag | Description |
|------|-------------|
| **`-l`** | 📋 Long format display with detailed file information |
| **`-a`** | 👁️ Show hidden files and directories (starting with `.`) |
| **`-R`** | 🔄 Recursive directory traversal |
| **`-r`** | ⬆️ Reverse sort order |
| **`-t`** | 🕐 Sort by modification time (newest first) |
| **`-G`** | 🎨 Colorized output for better readability |
| **`-p`** | 📁 Append `/` to directory names |
| **`-1`** | 📝 Force one entry per line output |

### Additional Features

- ✅ Handles symbolic links with proper display
- ✅ Supports major/minor device numbers for special files
- ✅ Accurate file permissions and ownership display
- ✅ Memory-efficient linked list implementation
- ✅ Robust error handling
- ✅ Custom libft library for all basic operations

---

## ⚙️ Installation

### Prerequisites

- GCC compiler
- Make
- Linux or macOS environment

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/Brobicho/ft_ls.git
cd ft_ls

# Build the project
make

# The executable 'ft_ls' will be created in the current directory
```

### Build Commands

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

---

## 💻 Usage

### Basic Usage

```bash
# List current directory
./ft_ls

# List specific directory
./ft_ls /path/to/directory

# List multiple directories
./ft_ls dir1 dir2 dir3
```

### Advanced Examples

```bash
# Long format with hidden files
./ft_ls -la

# Recursive listing with colors
./ft_ls -RG

# Sort by time, newest first
./ft_ls -lt

# Reverse alphabetical order with colors
./ft_ls -rG

# All options combined
./ft_ls -laRrtG /home
```

---

## 🖥️ Platform Support

| Platform | Status | Branch |
|----------|--------|--------|
| **macOS** | ✅ Fully Supported | `main` |
| **Ubuntu/Linux** | ✅ Fully Supported | `ubuntu` |

> **Note**: The `ubuntu` branch includes specific optimizations and compatibility fixes for Linux systems.

### Switching to Ubuntu Branch

```bash
git checkout ubuntu
make re
```

---

## 👨‍💻 Author

**Brobicho**
- GitHub: [@Brobicho](https://github.com/Brobicho)
- Project: 42 School - ft_ls
- School: Le 101

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
