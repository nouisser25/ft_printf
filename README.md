*This project has been created as part of the 42 curriculum by anouisse.*

# ft_printf

## Description

**ft_printf** is a custom implementation of the standard C library `printf()` function, developed as part of the 42/1337 Common Core curriculum. The objective of this project is to understand variadic functions in C (`<stdarg.h>`) and to build a modular, reusable static library (`libftprintf.a`) capable of formatting and writing data to standard output.

### Supported Conversions

This implementation handles the following format specifiers:

| Specifier | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (outputs `(null)` if the pointer is `NULL`). |
| `%p` | Prints a `void *` pointer address in hexadecimal format prefixed with `0x` (outputs `(nil)` if `NULL`). |
| `%d` | Prints a signed decimal (base 10) integer. |
| `%i` | Prints a signed integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) integer. |
| `%x` | Prints a number in lowercase hexadecimal (base 16). |
| `%X` | Prints a number in uppercase hexadecimal (base 16). |
| `%%` | Prints a literal percent sign (`%`). |

### Algorithm & Data Structure Choices

* **Variadic Argument Parsing (`<stdarg.h>`)**: `ft_printf` initializes a `va_list` with `va_start`, iterates linearly through the format string, and dispatches each `%` specifier to a static helper (`ft_formats`) that extracts the promoted argument via `va_arg` before cleaning up with `va_end`.
* **Unbuffered Direct Output & Error Handling**: Characters are written directly to file descriptor `1` using `write(1, &c, 1)` without internal buffering or dynamic memory allocation (`malloc`). Every helper returns the number of bytes written (or `-1` if `write` fails), allowing `ft_printf` to stop immediately and return `-1` on I/O error.
* **Recursive Base Conversion**: Numbers (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) are printed recursively via division and modulo (`10` for decimal, `16` for hexadecimal). Signed integers are cast to `long` to safely handle `INT_MIN` (`-2147483648`) without overflow, and pointers are cast to `unsigned long` to preserve full 64-bit memory addresses.

## Instructions

### Compilation

Run `make` at the root of the repository to compile the static library `libftprintf.a`:

```bash
make
```

Available `Makefile` rules:
* `make` or `make all` — Compiles the `.c` source files with `-Wall -Wextra -Werror` and archives them into `libftprintf.a` (`ar rcs`).
* `make clean` — Removes the compiled object files (`.o`).
* `make fclean` — Removes the object files and `libftprintf.a`.
* `make re` — Performs a full recompilation (`fclean` followed by `all`).

### Usage

Include `"ft_printf.h"` in your C source file and link `libftprintf.a` during compilation:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s! Number: %d | Hex: %x | Ptr: %p\n",
		"1337", 42, 255, &main);
	return (0);
}
```

Compile your program with:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

## Resources

### Classic References
* Linux Programmer's Manual: `man 3 printf`, `man 3 stdarg`, `man 2 write`.
* [GNU C Library Manual — Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
* [cppreference.com — Variadic functions (`va_start`, `va_arg`, `va_end`)](https://en.cppreference.com/w/c/variadic)

### AI Usage
* **Code Review & Edge Cases**: AI assistance was used to review `write()` error propagation (such as handling a closed `stdout` file descriptor) and to verify C default argument promotion rules in variadic functions.
* **Documentation**: AI assistance was used to structure and format this `README.md` file in accordance with the 42 curriculum requirements.