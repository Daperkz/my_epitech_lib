# `libdkz` — General-Purpose C Library

[![Build & Unit Tests](https://img.shields.io/badge/tests-485%2F485%20passing-brightgreen?style=for-the-badge&logo=github)](https://github.com)
[![Coverage](https://img.shields.io/badge/coverage-100%25-success?style=for-the-badge&logo=codecov)](https://github.com)
[![Language](https://img.shields.io/badge/c-C99%20%2F%20C11-blue?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![Documentation](https://img.shields.io/badge/docs-doxygen-blueviolet?style=for-the-badge&logo=doxygen)](./html/index.html)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

`libdkz` is a modular, high-performance C utility library developed during the **Epitech First-Year Curriculum (2025–2026)**. Originally evolving from the standard Epitech `libmy`, `libdkz` provides robust implementations of core data structures, custom I/O operations, string manipulation routines, mathematical functions, file handling, and a full-featured custom `my_printf` engine.

---

## Key Features

- **Custom `my_printf` Implementation**: Full support for standard format specifiers (`%d`, `%i`, `%s`, `%c`, `%x`, `%X`, `%o`, `%p`, `%u`, `%f`, `%e`, `%g`, `%a`, `%n`), width/precision parsing, flag modifiers (`#`, `+`, `-`, `' '`, `0`), and floating-point conversion internals.
- **Advanced Data Structures**: Generic, memory-safe data structures including Linked Lists, Doubly Linked Lists, Binary Trees, Queues, Stacks, and Hash Tables.
- **String & Memory Utilities**: Complete suite for string searching, comparison, base conversions (`atoi`, `itoa`, `ftoa`), formatting, trimming, and safe memory operations (`memcpy`, `memmove`, `memset`).
- **File I/O Engine**: Helper utilities for safe file opening, size determination, and content extraction.
- **Math & Numerical Routines**: Custom implementations for exponential, power, square root, prime checking/finding, rounding, and sign analysis.
- **100% Test Coverage**: Rigorously unit-tested using the **Criterion** testing framework with zero memory leaks and complete function validation (485/485 passing tests).

---

## Directory Architecture

```text
libdkz/
├── dkz/                        # Library Source Code & Public Headers
│   ├── include/
│   │   ├─ dkz/                # Public Library Headers
│   │   │   ├── config.h
│   │   │   ├── file.h
│   │   │   ├── graph/          # Data Structures (Lists, Trees, Stacks, Queues)
│   │   │   │   ├── binary_tree.h
│   │   │   │   ├── double_linked_list.h
│   │   │   │   ├── linked_list.h
│   │   │   │   ├── node.h
│   │   │   │   ├── queue.h
│   │   │   │   └── stack.h
│   │   │   ├── graph.h
│   │   │   ├── hashtable.h
│   │   │   ├── io.h
│   │   │   ├── macro.h
│   │   │   ├── math.h
│   │   │   ├── printf.h
│   │   │   ├── string.h
│   │   │   └── utils.h
│   │   └── dkz.h                   # Master Public Header
│   ├── private/                # Internal Headers & printf Parser Architecture
│   │   ├── my_printf/
│   │   └── private_dkz.h
│   ├── src/                    # C Implementations
│   │   ├── config/
│   │   ├── file/
│   │   ├── graph/
│   │   ├── hashtable/
│   │   ├── io/
│   │   ├── math/
│   │   ├── printf/
│   │   ├── string/
│   │   └── utils/
│   └── Makefile
│
├── test/                       # Unit Tests (Criterion Framework)
│   ├── criterion.supp          # Valgrind / Criterion suppression rules
│   ├── include/                # Test Harness & Wrapper Headers
│   ├── src/                    # Unit Tests & Mock Wrappers (malloc, read, write)
│   └── Makefile
│
├── Doxyfile                    # Doxygen API Documentation Configuration
├── Makefile                    # Root Makefile
└── README.md
```

---

## Library Modules

| Module | Public Header | Key Capabilities |
| :--- | :--- | :--- |
| **`printf`** | `"dkz/printf.h"` | Custom `my_printf` with standard specifiers (`%a`, `%e`, `%f`, `%g`, `%x`, etc.) and full flag/width/precision modifiers. |
| **`graph`** | `"dkz/graph.h"` | Single & doubly linked lists, binary search trees, stacks, queues, and generic node operations. |
| **`hashtable`** | `"dkz/hashtable.h"` | Key-value store with bucket chaining, dynamic hash functions, insertion, lookup, and deletion. |
| **`string`** | `"dkz/string.h"` | String manipulation, search, array conversions (`str_to_strarr`), base conversions (`atof`, `ftoa`, `itoab`), and memory helpers. |
| **`file`** | `"dkz/file.h"` | Robust file IO utilities (`get_file_content`, `get_file_size`, `open_file`, `read_file`). |
| **`math`** | `"dkz/math.h"` | Prime number generation, power calculations, floating-point rounding, square roots, and factorials. |
| **`io`** | `"dkz/io.h"` | Low-level output primitives (`my_putchar`, `my_put_nbr`, `my_showmem`, `my_show_word_array`). |
| **`utils`** | `"dkz/utils.h"` | Sorting algorithms (`my_sort_int_array`), parameter concatenation, and memory swapping. |

---

## Build System & Compilation

The project features a top-level Makefile that delegates build commands to target directories.

### Build Commands

```bash
# Compile the static library libdkz.a
make

# Compile with debug flags (-g3, -O0, sanitizers)
make debug

# Clean object files
make clean

# Full clean (removes library binaries, test builds, and documentation)
make fclean

# Full rebuild
make re
```

---

## Unit Testing & Coverage

Testing is implemented using the **Criterion** unit testing framework. The test suite includes system-call wrappers (`malloc`, `read`, `write`, `stat`) to simulate memory allocation failures and I/O error edge cases.

### Test Metrics

```text
[====] Synthesis: Tested: 485 | Passing: 485 | Failing: 0 | Crashing: 0
[100% Line & Branch Coverage]
```

### Running Tests

```bash
# Build test executables
make tests

# Run all unit tests
make tests_run

# Run unit tests in debug mode
make tests_debug

# Execute tests under Valgrind to check for memory leaks
make tests_memory_run

# Generate HTML code coverage report (gcovr / lcov)
make coverage

# Generate memory-leak coverage report
make memory_coverage
```

---

## API Documentation

Documentation is auto-generated from source code comments using **Doxygen**.


### Generating Documentation

To build the HTML documentation locally:


```bash
make docs
```

The output will be placed in the `html/` directory. Open `html/index.html` in your web browser to navigate the API reference.

---

## Usage Example

To use `libdkz` in your C project, include `"dkz/dkz.h"` or specific module headers and link against `libdkz.a`.

```c
#include "dkz.h"
#include "dkz/printf.h"
#include "dkz/hashtable.h"

int main(void)
{
    hashtable_t *ht;

    // Custom formatted printing
    my_printf("Hello %s! Value: %d, Hex: %#x\n", "World", 42, 255);

    // Hash table usage
    ht = hashtable_create(&hash_djb2, 16);
    if (ht != NULL) {
        hashtable_insert(ht, "user_id", "1001");
        my_printf("Retrieved: %s\n", (char *)hashtable_get(ht, "user_id"));
        hashtable_destroy(ht);
    }
    return 0;
}
```

### Compiling Your Program

```bash
gcc -Wall -Wextra -I./dkz/include main.c -L./dkz -ldkz -o my_app
```

---

## Academic Context

Developed by **Epitech** student as part of the **First-Year Curriculum (2025–2026)**.
It replaces and extends the classic `libmy` project with strict standards, automated unit testing, and modular architecture.

---

## License

Distributed under the MIT License. See [`LICENSE`](./LICENSE) for more information.
