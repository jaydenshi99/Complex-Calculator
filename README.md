# Complex Number Calculator

This is a **complex number calculator** written in **C++** that can evaluate mathematical expressions involving complex numbers, variables, constants, and common mathematical functions. It supports basic arithmetic operations, power operations, and trigonometric/hyperbolic functions.

---

## Features

1. **Arithmetic Operations**:
   - Addition (`+`)
   - Subtraction (`-`)
   - Multiplication (`*`)
   - Division (`/`)
   - Powers (`^`)

2. **Constants**:
   - `e` (Euler's number)
   - `pi` (π)

3. **Complex Numbers**:
   - Supports both real and imaginary numbers, e.g., `3`, `2i`, or `3+2i`.

4. **Functions**:
   - Exponential: `exp(z)`
   - Logarithm: `log(z)`
   - Trigonometric: `sin(z)`, `cos(z)`, `tan(z)`
   - Hyperbolic: `sinh(z)`, `cosh(z)`, `tanh(z)`

5. **Variable Assignment**:
   - Variables can store expressions or values, e.g.:
     ```plaintext
     a=2+3i
     b=a*2
     ```

6. **Debug Mode**:
   - Toggleable with the command `debug` to view internal evaluation steps.

7. **Exit Command**:
   - Type `exit` to terminate the program.

---

## Dependencies

This program relies on:
- **C++ Standard Library**:

Ensure that a C++ compiler supporting **C++20** or later is installed.

---

## Compilation and Execution

### Compile

Use the provided **Makefile** for easy compilation:

```bash
make
```

This will generate an executable named `calc`.

### Run

Execute the program:

```bash
./calc
```

### Clean

To clean up generated files (object files and executable):

```bash
make clean
```

---

## Commands

- Enter **mathematical expressions** like `3+2i`, `exp(2+3i)`, or `a=2+3i`.
- **Assign variables**: Use `=` to store expressions, e.g., `b=a+3`.
- Toggle **debug mode**: Type `debug`.
- Exit the calculator: Type `exit`.

---

## Debug Mode

- Debug mode shows the internal evaluation steps for each expression.  
- Toggle debug mode by typing `debug`.

---

## Future Improvements

- Implement more robust **error handling** for invalid inputs.

---

## Author

- **Jayden Shi**  
- Contact: [jaydenshi.js@gmail.com]  