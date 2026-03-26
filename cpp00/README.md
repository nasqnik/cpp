# CPP00 Module

## Overview

This module introduces core C++ basics through small exercises, including namespaces, classes, member functions, standard I/O streams, initialization lists, `static`, and `const`.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Exercises

This module contains 3 exercises: `ex00`, `ex01`, and `ex02`.

### ex00 - Megaphone

**Learning objective:** parse command-line arguments and use input/output streams.

**Run:**

```bash
make
./megaphone <arg>
```

**Behavior:**

- If no argument is provided, the program prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.
- Otherwise, it prints all provided arguments in uppercase.

**Usage example:**

```bash
./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```


