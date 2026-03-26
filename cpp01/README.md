# CPP01 Module

## Overview

This module introduces memory allocation in C++, references, pointers to members, and `switch` statements.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Contents

This module contains 7 exercises: `ex00` - `ex06`.

- [ex00 - BraiiiiiiinnnzzzZ](#ex00)
- [ex01 - Moar brainz!](#ex01)
- [ex02 - HI THIS IS BRAIN](#ex02)
- [ex03 - Unnecessary violence](#ex03)
- [ex04 - Sed is for losers](#ex04)
- [ex05 - Harl 2.0](#ex05)
- [ex06 - Harl filter](#ex06)

<a id="ex00"></a>
### ex00 - BraiiiiiiinnnzzzZ

**Learning objective:** memory allocation and cleanup (`new`/`delete`), pointers.

**Run:**

```bash
make
./BraiiiiiiinnnzzzZ
```

**Behavior:**

The program creates two `Zombie` objects: one on the heap (`newZombie()`) and one on the stack (`randomChump()`). The heap-allocated zombie is explicitly deleted to avoid a memory leak.

**Output example:**

```bash
./BraiiiiiiinnnzzzZ 
Foo: BraiiiiiiinnnzzzZ...
Foo zombie is destroyed
Oof: BraiiiiiiinnnzzzZ...
Oof zombie is destroyed
```

<a id="ex01"></a>
### ex01 - Moar brainz!

**Learning objective:** dynamic allocation of arrays and proper cleanup with `delete[]`.

**Run:**

```bash
make
./Moar_brainz!
```

**Behavior:**

Creates a zombie horde on the heap using `zombieHorde(n, name)`, announces each zombie, then frees the whole array with `delete[]`.

**Output example:**

```bash
./BraiiiiiiinnnzzzZ 
Zizi: BraiiiiiiinnnzzzZ...
Zizi: BraiiiiiiinnnzzzZ...
Zizi zombie is destroyed
Zizi zombie is destroyed
```

<a id="ex02"></a>
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

**Output example:**

```bash
./BraiiiiiiinnnzzzZ 
Memory addresses
str       | 0xffffde381278
stringPTR | 0xffffde381278
stringREF | 0xffffde381278

Values
str       | HI THIS IS BRAIN
stringPTR | HI THIS IS BRAIN
stringREF | HI THIS IS BRAIN
```

<a id="ex03"></a>
### ex03 - Unnecessary violence

**Learning objective:** references vs pointers in class design (`HumanA` and `HumanB`) and shared mutable state via `Weapon`.

**Run:**

```bash
make
./unnecessary_violence
```

**Behavior:**

Shows attack messages before and after weapon type changes to demonstrate how `HumanA` (reference) and `HumanB` (pointer/setter) hold weapons.


<a id="ex04"></a>
### ex04 - Sed is for losers

**Learning objective:** file I/O and string replacement without using `std::string::replace`.

**Run:**

```bash
make
./sed <filename> <s1> <s2>
```

**Behavior:**

Creates `<filename>.replace` and writes file contents with all occurrences of `s1` replaced by `s2`.

**Output example:**

```bash
echo "hello world" > test.txt
echo "world world" >> test.txt
./sed test.txt world 42
cat test.txt.replace
hello 42
42 42
```

<a id="ex05"></a>
### ex05 - Harl 2.0

**Learning objective:** use pointers to member functions for level-based dispatch.

**Run:**

```bash
make
./harl
```

**Behavior:**

Calls `Harl::complain()` with `DEBUG`, `INFO`, `WARNING`, and `ERROR` and prints the mapped messages.

<a id="ex06"></a>
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
