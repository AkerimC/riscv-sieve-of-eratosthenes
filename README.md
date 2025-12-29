# RISC-V Sieve of Eratosthenes

This project implements the **Sieve of Eratosthenes** algorithm to find prime numbers up to a given limit using **RISC-V Assembly** and **C language**.

The main goal of this project is to demonstrate how low-level assembly code can be combined with C to achieve efficient CPU-oriented computation.

---

## Project Description

In this project, I implemented the Sieve of Eratosthenes algorithm to identify prime numbers up to a user-defined value `N`.  
The program is divided into two parts. The C part handles user input, memory allocation, and result processing. The RISC-V Assembly part performs the core sieve algorithm by marking non-prime numbers directly in memory.

---

## Algorithm

The Sieve of Eratosthenes works as follows:

- All numbers are initially assumed to be prime.
- Starting from 2, multiples of each prime number are marked as non-prime.
- The process continues until the square of the current number exceeds `N`.

This approach is efficient and well-suited for low-level optimization.

---

## Implementation Details

- **Language:** C and RISC-V Assembly  
- **Data Structure:** `uint8_t` array (1 byte per number)  
- **Memory Access:** Sequential and cache-friendly  
- **Assembly Function:** Leaf function without stack usage  

Each number is represented by one byte:
- `1` → prime  
- `0` → not prime  

---

## Build and Run

### Requirements
- `riscv64-linux-gnu-gcc`
- `qemu-riscv64`

### Compile
```bash
riscv64-linux-gnu-gcc -O2 -Wall find_Prime.c mark_prime.S -o findPrime
qemu-riscv64 ./findPrime
