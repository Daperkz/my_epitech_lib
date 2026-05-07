[placeholder]
libdkz

A robust C utility library designed for the EPITECH curriculum, providing essential tools for string manipulation, memory management, I/O, data structures, and mathematical computations.
🚀 Features
🧵 String Manipulation (dkz/string.h)

    Advanced Parsing: Split strings into arrays with support for custom separators and boundary pairs (quotes, brackets).

    Memory Safe: Full suite of duplication, joining, and trimming functions (my_strdup, my_strjoin, my_strtrim).

    Searching: Implementation of the Boyer-Moore algorithm for efficient pattern matching.

    Validation: Check for numeric, alphabetical, or printable characters.

📊 Data Structures (dkz/graph.h & dkz/hashtable.h)

    Linked Lists: Simple and double-linked list implementations with head/tail operations.

    Stacks & Queues: Easy-to-use macros for LIFO and FIFO data management.

    Hashtables: Support for multiple hash algorithms (djb2, fnv_1a, sdbm) with collision handling via buckets.

    Binary Trees: Core structures for hierarchical data management.

📝 Formatted Output (dkz/printf.h & dkz/io.h)

    Custom Printf: my_printf, my_fprintf, and my_sprintf implementations.

    Debugging Tools: my_showmem for hex-dumps and my_show_word_array for inspecting string arrays.

    Base Conversion: Print integers in any base (Hex, Binary, Octal, etc.).

📂 File System (dkz/file.h)

    Content Loading: Read entire files into memory dynamically.

    Metadata: Retrieve file sizes accurately even for special files in /dev or /proc.

🧮 Math & Utils (dkz/math.h & dkz/utils.h)

    Conversions: Robust atoi, atof, and base-to-base conversion tools.

    Arithmetic: Power, square root, prime number checking, and rounding functions.

    Sorting: Standard integer array sorting and value swapping.

🛠️ Installation

    Clone the repository into your project:
    Bash

    git clone https://github.com/your-username/libdkz.git

    Include the main header in your C files:
    C

    #include "dkz.h"

    Compile with the library:
    Bash

    gcc your_file.c -L./libdkz -ldkz

📖 Usage Examples
String Splitting with Pairs
C

char **tab = my_str_to_strarr_pairs("Hello (World) 'C Programming'", " ", "(:);':'");
// Result: ["Hello", "World", "C Programming"]
my_free_strarr(tab);

Hashtable Management
C

ht_t *my_table = ht_create(&djb2, 50);
ht_insert(my_table, "key1", "data");
char *data = ht_get(my_table, "key1");
ht_destroy(my_table, NULL);

📋 Documentation

Most functions follow the Epitech naming convention (my_...). Detailed Doxygen-style comments are available within the .h files for parameter specifics and return values.

    Author: Daperkz

    Version: 1.0

    Last Updated: 2026-07-05

⚖️ License

EPITECH PROJECT, 2025-2026. All rights reserved.]