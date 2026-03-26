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
./megaphone <args...>
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

### ex01 - My Awesome PhoneBook

**Learning objective:** class structure (public and private attributes), instances, and input/output string manipulation.

**Run:**

```bash
make
./phonebook
```

**Behavior:**

Program behaves like a PhoneBook. At program start-up, the phonebook is empty and the user is prompted to enter one of three commands: `ADD`, `SEARCH`, or `EXIT`.

- `ADD`: save a new contact.
- `SEARCH`: display contacts and view a specific contact by index.
- `EXIT`: quit the program (contacts are not persisted).

The phonebook can store up to 8 contacts. When a 9th contact is added, it overwrites the oldest one.
Commands are case-sensitive.

Input rules:

- Empty or whitespace-only fields are rejected.
- Phone number must contain digits only.

**Usage example:**

```bash
./phonebook
Pick the command ADD, SEARCH or EXIT, and enter it
ADD
FIRST NAME: Ana
LAST NAME: Nikitina
NICKNAME: nasqnik
PHONE NUMBER: 123456789
DARKEST SECRET: likes cats
Pick the command ADD, SEARCH or EXIT, and enter it
SEARCH
|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|
|         1|       Ana|  Nikitina|   nasqnik|
Enter an index (1-8) to view details or 0 to cancel: 1
FIRST NAME: Ana
LAST NAME: Nikitina
NICKNAME: nasqnik
PHONE NUMBER: 123456789
DARKEST SECRET: likes cats
Pick the command ADD, SEARCH or EXIT, and enter it
EXIT
```

### ex02 - The Job of Your Dreams

**Learning objective:** recreate Account class structure based on the provided Account.hpp file.

**Run:**

```bash
make
./account
```

**Behavior:**

The output of the program should match `19920104_091532.log` exactly, except for timestamps.

**Usage example:**

```bash
./account 
[YYYYMMDD_HHMMSS] index:0;amount:42;created
[YYYYMMDD_HHMMSS] index:1;amount:54;created
[YYYYMMDD_HHMMSS] index:2;amount:957;created
[YYYYMMDD_HHMMSS] index:3;amount:432;created
[...]
```

**Quick check:**

Compare your output with the reference log while ignoring timestamp differences.