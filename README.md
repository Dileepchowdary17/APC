# Arbitrary Precision Calculator (APC) in C

A command-line Arbitrary Precision Calculator implemented in C using **doubly linked lists**. Each decimal digit is stored in an individual node, allowing arithmetic operations on large integers without relying on standard integer data types to store the complete operands.

## Features

- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`x` or `X`)
- Integer division (`/`)
- Positive and negative operands
- Input validation for operands and operators
- Leading-zero removal
- Division-by-zero check
- Dynamic memory allocation for linked-list nodes

## Project Structure

```text
APC/
├── main.c      # Command-line interface and operation dispatch
├── apc.c       # Argument validation and operand-list creation
├── apc.h       # Shared structure definitions, macros and prototypes
├── list.c      # Doubly linked-list utility functions
├── add.c       # Addition and addition sign handling
├── sub.c       # Subtraction and subtraction sign handling
├── mul.c       # Multiplication and multiplication sign handling
└── div.c       # Division and division sign handling
```

## How It Works

### Number Representation

Each operand is converted from a numeric string into a doubly linked list. Every node stores one decimal digit.

For example, the number `12345` is represented as:

```text
NULL <- 1 <-> 2 <-> 3 <-> 4 <-> 5 -> NULL
       HEAD                         TAIL
```

The head stores the most significant digit, while the tail stores the least significant digit. This allows the arithmetic functions to traverse from the tail towards the head when processing digits from right to left.

### Arithmetic Implementation

- **Addition:** Processes digits from right to left, calculates carry, and inserts result digits at the beginning of the result list.
- **Subtraction:** Uses borrowing to subtract digit by digit. The magnitude-level subtraction assumes the first operand is greater than or equal to the second; the handler compares magnitudes and chooses the appropriate order.
- **Multiplication:** Uses the long-multiplication approach. It generates partial products for each digit of the second operand, shifts them by appending zeros, and accumulates them using the addition function.
- **Division:** Uses repeated subtraction to determine each quotient digit while bringing down dividend digits. The implementation produces an integer quotient.

The `handle_*` functions manage operand signs separately from the magnitude-level arithmetic functions.

## Requirements

- GCC compiler
- Linux, macOS, or Windows with GCC through WSL/MinGW
- Terminal or command prompt

## Compilation

Open a terminal in the project directory and run:

```bash
gcc -Wall -Wextra -g main.c apc.c list.c add.c sub.c mul.c div.c -o APC.out
```

## Usage

```bash
./APC.out <operand1> <operator> <operand2>
```

Examples:

```bash
./APC.out 12345678901234567890 + 98765432109876543210
./APC.out 532 - 178
./APC.out 12345 x 678
./APC.out 1000 / 25
./APC.out -125 + 75
./APC.out -12 x 5
```

Supported operators:

| Operator | Operation |
|---|---|
| `+` | Addition |
| `-` | Subtraction |
| `x` or `X` | Multiplication |
| `/` | Integer division |

The program accepts an optional `+` or `-` sign before each operand.

## Linked-List Utility Functions

The project uses reusable functions defined in `list.c`:

| Function | Responsibility |
|---|---|
| `insert_first()` | Inserts a digit at the beginning |
| `insert_last()` | Inserts a digit at the end |
| `delete_list()` | Frees all nodes in a list |
| `print_list()` | Prints the digits in a list |
| `list_len()` | Counts the number of nodes |
| `remove_pre_zeros()` | Removes unnecessary leading zeros |
| `is_zero()` | Checks whether a list represents zero |
| `compare_list()` | Compares two non-negative magnitudes |

## Input Validation and Memory Management

- The command-line argument count is checked before processing.
- Operands are checked for valid decimal digits, with an optional leading sign.
- The operator is checked against the supported operations.
- Linked-list nodes are dynamically allocated using `malloc()`.
- Lists are released using `free()` through `delete_list()`.
- Division by zero is checked before division is performed.

## Limitations

- Division is integer division; any fractional part is discarded.
- The implementation uses decimal digits and linked lists rather than a binary or chunk-based representation.
- The project is a command-line application; it does not include a graphical interface.

## Learning Outcomes

This project provides practical experience with:

- Dynamic memory allocation in C
- Doubly linked lists
- Pointer manipulation and pointer-to-pointer parameters
- Carry and borrow propagation
- Implementing arithmetic algorithms
- Modular programming using header and source files
- Command-line argument validation
- Memory cleanup and debugging

## Build and Run

```bash
gcc -Wall -Wextra -g main.c apc.c list.c add.c sub.c mul.c div.c -o APC.out
./APC.out 12345678901234567890 + 98765432109876543210
```

---

**Project:** Arbitrary Precision Calculator (APC)  
**Language:** C  
**Core Data Structure:** Doubly Linked List
