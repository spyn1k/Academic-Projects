# Aliquot Sequence Generator (C)

This project is a simple C program that generates the **Aliquot Sequence** for a given positive integer.

An aliquot sequence is a sequence of integers in which each term is the sum of the proper divisors of the previous term.

---

## Features

- Supports large numbers using `unsigned long long`
- Option to:
  - Print the **full sequence**, or
  - Print only the **length of the sequence**
- Handles invalid input cases
- Special handling for known repeating cases (e.g. the number 6)
- Protection against extremely large numbers

---

## How It Works

The program:
1. Asks the user to enter a starting number
2. Asks for the maximum sequence length (or `0` for unlimited)
3. Allows the user to choose between:
   - `f` → full sequence output
   - `l` → only sequence length
4. Calculates the sequence using the sum of proper divisors until it reaches:
   - `0`, or  
   - the chosen maximum length

---

## How to Compile and Run

### Compile
```bash
gcc aliquot.c -o aliquot -lm
