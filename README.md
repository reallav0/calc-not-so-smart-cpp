# Not So Smart Calc (I jumped right into doing this without knowing any basic C++ knowledge, so the codes are not really optimize and clean)

A simple yet powerful C++ calculator capable of evaluating mathematical expressions with addition (+), subtraction (-), multiplication (*), division (/), and parentheses ().
It automatically checks for syntax and typing errors before evaluating the expression.

---

## Features

* Supports `+`, `-`, `*`, `/`, and nested parentheses `()`
* Detects and reports syntax and typing errors
* Correctly handles operator precedence
* Supports decimal numbers
* Automatically simplifies equations step by step
* Interactive command-line interface (type `exit` to quit)

---

## Example Usage

```
Enter your equation (or type 'exit' to quit): (12-9.125+1368-1)
|| The answer is : 1369.875 ||

=== Finished! Restarting... ===

Enter your equation (or type 'exit' to quit): (10+5)*2
|| The answer is : 30 ||
```

---

## Code Structure

| Function              | Purpose                                                   |
| --------------------- | --------------------------------------------------------- |
| `validEquation()`     | Validates equation syntax and parentheses                 |
| `detachPriority()`    | Extracts the highest-priority subexpression in `()`       |
| `seperator()`         | Finds and isolates multiplication/division parts          |
| `PlusAndMinusCal()`   | Calculates `+` and `-` expressions with decimal precision |
| `MultiAndDivideCal()` | Calculates `*` and `/` expressions with decimal precision |
| `main()`              | Handles user input, validation, and final output display  |

---

## How It Works

1. The program first validates the input for proper operators and parentheses balance.
2. It finds and evaluates the innermost parentheses first, following operator precedence.
3. Solved expressions are replaced by their numeric results.
4. The process repeats until all parentheses and operations are fully evaluated.

---

## Compilation and Run

To compile and run the calculator:

```bash
g++ -o SmartCalc main.cpp
./SmartCalc
```

On Windows:

```bash
g++ main.cpp -o SmartCalc.exe
SmartCalc.exe
```

---

## Example Test Cases

| Input         | Output                 | Notes                            |
| ------------- | ---------------------- | -------------------------------- |
| `(5*2+3)/2`   | `6.5`                  | Nested parentheses               |
| `12--3`       | `15`                   | Handles double negative          |
| `3+-2`        | `1`                    | Mixed signs                      |
| `(2+3*(5-1))` | `14`                   | Correct order of operations      |
| `12/0`        | Error (optional check) | Division by zero not yet handled |

---

## Author

**ReallAv0**
© 2025 — Open-source educational project

---

## License

MIT License — free to use, modify, and distribute with attribution.

---
