# ft_printf

`ft_printf` is a reimplementation of the standard C `printf` function, written as part of the 42 / Codam curriculum. It provides a drop-in replacement for formatted output, packaged as a static library `libftprintf.a` that can be reused across other C projects.

This version includes both the **full mandatory behavior** and the **bonus features** (flags, width and precision handling).

---

## 📚 Overview

The public interface is intentionally minimal:

```c
int ft_printf(const char *format, ...);
```

- Prints formatted output to `stdout`, like the original `printf`.
- Returns the **number of characters written**, or a negative value on error.
- Accepts a variable number of arguments using `va_list` / `va_start` / `va_arg` / `va_end`.

The implementation supports all required conversions:

- `%c` – character  
- `%s` – C-string  
- `%p` – pointer, printed in hexadecimal with `0x` prefix  
- `%d` / `%i` – signed decimal integer  
- `%u` – unsigned decimal integer  
- `%x` / `%X` – unsigned hexadecimal (lowercase / uppercase)  
- `%%` – literal percent sign

---

## ✨ Formatting features

### Supported flags, width and precision

This implementation goes beyond the bare minimum and supports the project’s bonus flags.

- **Field width** (e.g. `%10d`, `%-15s`)
- **Precision** for numbers and strings (e.g. `%.3d`, `%.5s`)
- **Left alignment** with `-`
- **Zero padding** with `0` (e.g. `%08d`)
- **Alternative form** with `#`:
  - `0x` / `0X` prefix for non-zero hexadecimal values (`%#x`, `%#X`)
- **Explicit plus sign** with `+` for positive numbers (e.g. `%+d`)
- **Leading space** with ` ` (space) for positive numbers when `+` is not used

These options can be combined, and the formatter respects the same precedence rules as the standard `printf` (for example, `+` overrides the space flag, precision disables zero-padding for integers, etc.).

### Pointer and string handling

- `NULL` pointers with `%p` are printed as `(nil)`.
- `NULL` strings with `%s` are printed as `(null)`.
- Width and precision are correctly applied to strings, allowing truncation and alignment.

---

## 🧱 Project structure

Key files in the project:

- **Core API**
  - `ft_printf.c` – main implementation of `ft_printf`, format parsing and dispatch.
  - `ft_printf.h` – public header, `t_fmt` structure and function prototypes.

- **Formatting handlers**
  - `ft_putchar_printf.c` – `%c` conversion with padding/alignment.
  - `ft_putstr_printf.c` – `%s` conversion with width and precision.
  - `ft_putptr_printf.c` – `%p` conversion with `0x` prefix, `(nil)` for `NULL`.
  - `ft_putint_printf.c` – `%d` / `%i` conversions with sign, width, precision, and flags.
  - `ft_putuint_printf.c` – `%u`, `%x`, `%X` conversions with base handling and `#` flag.

- **Utility functions**
  - `ft_printf_utils.c` – helpers for lengths, absolute values, numeric output, etc.
  - `ft_utils_utils.c` – additional small utilities shared across formatters.
  - `ft_putchar_fd.c`, `ft_putstr_fd.c` – minimal I/O helpers that wrap `write(2)`.

- **Testing**
  - `test_ft_printf.c` – comparison program printing the same format strings using both the system `printf` and `ft_printf`, useful during development. This file is **not** part of the library itself.

The static library is named:

```text
libftprintf.a
```

and is created at the root of the repository.

---

## 🧮 Internal design

### Format state (`t_fmt`)

Formatting state is stored in a dedicated structure:

```c
typedef struct s_fmt
{
    int     len;
    int     offset;
    int     pad;
    int     width;
    int     precision;
    int     hashtag;
    int     zero;
    int     minus;
    int     space;
    int     plus;
    int     dot;
    int     upper;
    va_list args;
}   t_fmt;
```

This structure tracks:

- total number of characters printed (`len`),
- padding and alignment (`offset`, `pad`, `width`, `minus`, `zero`),
- precision and dot flag (`precision`, `dot`),
- numeric flags (`hashtag`, `space`, `plus`, `upper`),
- the active variadic argument list (`args`).

`ft_printf` iterates over the format string, and whenever it encounters `%`, it:

1. Resets the `t_fmt` structure to default values.
2. Parses flags, width and precision characters.
3. Dispatches to the appropriate handler based on the conversion specifier.
4. Updates `fmt.len` with the number of characters written.

At the end, `ft_printf` returns the accumulated `len` to the caller.

### Number formatting

Integer formatting is built on top of a small set of helpers:

- Functions to compute the number of digits (`ft_numlen`, `ft_unumlen`).
- Functions to print signed and unsigned numbers in an arbitrary base
  (e.g. `ft_putfnbr_base_fd`, `ft_putunbr_base_fd`).
- Logic that:
  - applies sign (`-`, `+`, or leading space),
  - decides how many zeroes to pad for precision,
  - calculates additional spacing to satisfy the field width,
  - optionally enables uppercase digits for `%X`.

This layered design keeps the code maintainable and makes it easy to add new conversions or extend behavior if needed.

---

## 🔧 Building

The project comes with a simple `Makefile`:

```make
NAME = libftprintf.a

SRC = ft_putchar_printf.c ft_putint_printf.c       ft_putstr_printf.c ft_printf_utils.c ft_putptr_printf.c       ft_putuint_printf.c ft_printf.c ft_putchar_fd.c       ft_putstr_fd.c ft_utils_utils.c
```

Available targets:

- `make` / `make all` – compile all sources and create `libftprintf.a`.
- `make bonus` – identical for this project; the bonus behavior is integrated into the same codebase.
- `make clean` – remove object files.
- `make fclean` – remove objects and `libftprintf.a` (and compiled test binaries, if any).
- `make re` – full rebuild.

---

## ▶️ Using ft_printf in your project

### 1. Add the library

Copy the source files / `Makefile` into your project or keep `ft_printf` as a separate repository and build it there.

### 2. Build

```bash
make            # builds libftprintf.a
```

### 3. Link with your program

```bash
cc main.c -L. -lftprintf -o demo
```

Make sure the compiler can find `ft_printf.h`:

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;

    ft_printf("Hello, %s! Answer = %d\n", "world", n);
    ft_printf("Hex: %#08x | Pointer: %p\n", 2550, &n);
    ft_printf("Signed: %+d | Space flag: % d\n", 7, 7);
    return 0;
}
```

Compile and run:

```bash
cc main.c -L. -lftprintf -o demo
./demo
```

---

## 🚫 Constraints & compliance

The implementation respects the project constraints:

- **Language**: C, compiled with `cc` and the flags `-Wall -Wextra -Werror`.
- **External functions used**: `write`, `malloc`, `free`, and the variadic macros
  `va_start`, `va_arg`, `va_copy`, `va_end`.
- **Output**: no custom buffering layer; all writes go directly to `stdout`.
- **Memory**: no leaks or double frees; dynamic memory is kept minimal and local.
- **Style**: all code is written according to the 42 Norm.

---

## 🧠 What I learned

Implementing `ft_printf` with bonus features was a great exercise in:

- Handling **variadic functions** and format strings in C.
- Designing a small but extensible **formatting engine**.
- Implementing **flags, width and precision** in a way that matches real-world `printf` behavior.
- Managing **integer and pointer formatting** in multiple bases.
- Writing clean, reusable C code that can be integrated into larger projects (for example, by merging `ft_printf` into `libft` later).

This project now provides a solid foundation for formatted output in my future C projects.
