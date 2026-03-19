# Activity 1 — Prime Numbers (Sieve of Eratosthenes)

## Description

This program was developed as part of the **Performance Evaluation** course.

The objective is to compute all prime numbers in the interval from 1 to \( N \), using an efficient algorithm.

## Features

- Reads an integer \( N > 0 \) from user input
- Handles invalid input (non-numeric or \( N < 1 \))
- Computes prime numbers up to \( N \)
- Prints:
    - The value of \( N \)
    - The list of prime numbers (separated by `-`)
    - The total number of primes found

## Algorithm

The program uses the **Sieve of Eratosthenes**, which:

- Eliminates multiples of each prime number
- Runs in approximately **O(N log log N)** time
- Is significantly faster than naive primality testing

## How to Run

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
./PrimeSieve