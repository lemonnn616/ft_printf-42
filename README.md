# 🖨️ ft_printf

**ft_printf** is a custom implementation of the `printf` function from the C standard library. This project, developed as part of the 42 School curriculum, replicates the behavior of `printf` while providing insights into formatted output handling and variadic functions.

---

## 🛠️ Features

The project includes the following features:

### **Mandatory Part**
- Supports the following conversion specifiers:
  - `%c` for characters.
  - `%s` for strings.
  - `%p` for pointers.
  - `%d` and `%i` for integers.
  - `%u` for unsigned integers.
  - `%x` and `%X` for hexadecimal numbers (lowercase and uppercase).
  - `%%` for the percentage sign.
- Handles width and precision for all supported conversions.
- Manages the following flags:
  - `-` for left alignment.
  - `0` for zero padding.
  - `.` for precision.
  - Minimum field width for proper formatting.

### **Bonus Part**
- Enhanced support for additional flags:
  - `#` for alternate forms (e.g., `0x` or `0X` for hexadecimal).
  - `+` to force sign display for positive numbers.
  - A space (` `) for a blank space before positive numbers.
- Handles any combination of the following flags: `-`, `0`, `.` with field minimum width across all conversions.

---

## 🎯 Objectives

- Recreate the behavior of the standard `printf` function.
- Understand and utilize variadic functions in C.
- Implement robust handling for edge cases in formatted output.
- Provide support for advanced formatting combinations and flags.

---
