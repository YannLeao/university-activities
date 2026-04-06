# Activity 3 — Sorting Algorithm Comparison

This activity focuses on comparing the performance of different sorting algorithms.

## Description

The program reads a list of integers from a file and sorts them using two different approaches:

- A **slow algorithm** (e.g., Bubble Sort, Insertion Sort)
- A **fast algorithm** (e.g., Quick Sort, Merge Sort)

The purpose is to observe the difference in execution time between inefficient and efficient sorting strategies.

## Requirements

The program must:

- Read integers (including negative numbers) from a file named `arq.txt`
- Store the values in a data structure such as a vector
- Sort the data using two different algorithms
- Measure execution time for each algorithm
- Execute each algorithm **five times**
- Compute and display the **average time**
- Save the sorted numbers to `arq-ordenado.txt`

## Example

### Input (`arq.txt`)

10 -3 25 0 -8 7

### Output (terminal)

Algorithm: Bubble Sort

| Execution | Time (s) |
|-----------|----------|
| 1         | 0.523    |
| 2         | 0.498    |
| 3         | 0.510    |
| 4         | 0.505    |
| 5         | 0.512    |
Average: `0.510s`

Algorithm: Quick Sort

| Execution | Time (s) |
|----------|-----------|
| 1        | 0.012     |
| 2        | 0.010     |
| 3        | 0.011     |
| 4        | 0.009     |
| 5        | 0.011     |
Average: `0.011s`

### Output file (`arq-ordenado.txt`)

-8 -3 0 7 10 25