# coffeesip
Shows coffee ascii animations in the terminal

# Prerequisites

- you need a C++ compiler
- here, we will use the Gnu G++


## 🐧 Linux

### Ubuntu / Debian / Linux Mint

```bash
sudo apt update
sudo apt install g++
```

### Fedora

```bash
sudo dnf install gcc-c++
```

### CentOS / RHEL

```bash
sudo dnf groupinstall "Development Tools"
sudo dnf install gcc-c++
```

### Arch Linux / Manjaro

```bash
sudo pacman -S gcc
```

### Windows

- look for https://visualstudio.microsoft.com/visual-cpp-build-tools/
- unfortunately, I don't compile under Windows, but the internet is big and ChatGPT is your friend :)


- Check for correct installation

```bash
g++ --version
```

# Build:

```bash
g++ -o coffeesip main.cpp
```

---

## Running:

```bash
./coffeesip
```
