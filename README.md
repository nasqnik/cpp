# C++ Modules (42)

This repository is a collection of 42 C++ projects focused on learning C++ with the C++98 standard and the basics of object-oriented programming.

## Standards and Compilation

- Compiler: `c++`
- Required flags: `-Wall -Wextra -Werror`
- Standard compatibility: `-std=c++98`

## Requirements

To run the exercises, you need:

- A Linux or macOS environment
- A C++ compiler (`c++`, `clang++`, or `g++`)
- `make`

On Ubuntu/Debian, you can install the essentials with:

```bash
sudo apt update
sudo apt install build-essential clang make
```

## Modules

- `cpp00` ([README](./cpp00/README.md))
- `cpp01`
- `cpp02`
- `cpp03`
- `cpp04`
- `cpp05`
- `cpp06`
- `cpp07`
- `cpp08`
- `cpp09`

## Build and Run

Each exercise has its own `Makefile`. From an exercise folder, use:

```bash
make
make re
make clean
make fclean
```

Then run the generated executable for that exercise.

## Notes

- Module-level README files are added progressively.
- Detailed instructions are available in each module/exercise folder when present.

## Environment

- OS: Ubuntu 22.04
- Compiler toolchain: Clang