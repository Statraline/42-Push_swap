*This project has been created as part of the 42 curriculum by srichard.*

# Push_swap

## Description
**Push_swap** is an algorithmic project that requires sorting a stack of integers using a limited set of instructions and a secondary stack. The goal is to produce the smallest possible sequence of operations.

This implementation uses two distinct strategies depending on the input size:
* **Small Stacks (3 to 5 numbers):** A specialized sorting logic that calculates the most efficient path (using `ra` or `rra`) to sort 5 elements in approximately 8 to 11 operations.
* **Large Stacks (100+ numbers):** A **Radix Sort** algorithm (Base 2). By converting numbers into relative indexes, the algorithm sorts the data bit by bit, ensuring high stability and performance that fits within the 42 scoring brackets.

## Instructions

### Compilation
The project uses a Makefile to compile the source files. To create the `push_swap` executable, run:
```bash
make
```
### Usage
The program takes a list of integers as arguments and outputs the instructions to sort them:
```bash
./push_swap 42 15 -8 90 3
```
It also supports formatted strings as input:
```bash
./push_swap "42 15 -8 90 3"
```
### Performance Testing
To count the number of operations for 100 random numbers:
```bash
ARG=$(shuf -i 0-5000 -n 100); ./push_swap $ARG | wc -l
```

## Resources
* **Algorithms:** Radix Sort logic and Bitwise operations.
* **Data Structures:** Doubly Linked Lists for stack management.
* **AI Usage:** Artificial Intelligence (Gemini) was used as a pedagogical assistant for:
* Refactoring: Breaking down complex functions into static helpers to comply with the 25-line Norminette limit.
* Memory Safety: Debugging the ft_split integration to ensure 100% leak-free execution on all input types


