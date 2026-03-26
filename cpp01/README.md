# CPP01 Module

## Overview

This module introduces memory allocation in C++, references, pointers to members, and `switch` statements.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Exercises

This module contains 7 exercises: `ex00` - `ex06`.

### ex00 - BraiiiiiiinnnzzzZ

**Learning objective:** memory allocation and cleanup (`new`/`delete`), pointers.

**Run:**

```bash
make
./BraiiiiiiinnnzzzZ
```

**Behavior:**

The program creates two `Zombie` objects: one on the heap (`newZombie()`) and one on the stack (`randomChump()`). The heap-allocated zombie is explicitly deleted to avoid a memory leak.

**Usage example:**

```bash
./BraiiiiiiinnnzzzZ 
Foo: BraiiiiiiinnnzzzZ...
Foo zombie is destroyed
Oof: BraiiiiiiinnnzzzZ...
Oof zombie is destroyed
```

### ex01 - Moar brainz!

**Learning objective:** dynamic allocation of arrays and proper cleanup with `delete[]`.

**Run:**

```bash
make
./Moar_brainz!
```

**Behavior:**

Creates a zombie horde on the heap using `zombieHorde(n, name)`, announces each zombie, then frees the whole array with `delete[]`.

### ex02 - HI THIS IS BRAIN

**Learning objective:** understand the difference between a pointer and a reference.

**Run:**

```bash
make
./HI_THIS_IS_BRAIN
```

**Behavior:**

Prints memory addresses and values for:

- a `std::string` variable
- a pointer to that string
- a reference to that string

### ex03 - Unnecessary violence

**Learning objective:** references vs pointers in class design (`HumanA` and `HumanB`) and shared mutable state via `Weapon`.

**Run:**

```bash
make
./unnecessary_violence
```

**Behavior:**

Shows attack messages before and after weapon type changes to demonstrate how `HumanA` (reference) and `HumanB` (pointer/setter) hold weapons.

### ex04 - Sed is for losers

**Learning objective:** file I/O and string replacement without using `std::string::replace`.

**Run:**

```bash
make
./sed <filename> <s1> <s2>
```

**Behavior:**

Creates `<filename>.replace` and writes file contents with all occurrences of `s1` replaced by `s2`.

### ex05 - Harl 2.0

**Learning objective:** use pointers to member functions for level-based dispatch.

**Run:**

```bash
make
./harl
```

**Behavior:**

Calls `Harl::complain()` with `DEBUG`, `INFO`, `WARNING`, and `ERROR` and prints the mapped messages.

### ex06 - Harl filter

**Learning objective:** combine member-function dispatch with `switch`-based filtering behavior.

**Run:**

```bash
make
./harlFilter <level>
```

**Behavior:**

Prints messages from the selected level upward (`DEBUG` -> all, `INFO` -> INFO/WARNING/ERROR, etc.). For unknown levels, it prints:
`[ Probably complaining about insignificant problems ]`.
