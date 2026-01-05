# Tiny Compiler with IR Optimization (C++)

## Overview
This project is a miniature compiler implemented in C++ to demonstrate
core compiler design concepts such as:

- Intermediate Representation (IR)
- Optimization Passes
- Backend Code Generation

The compiler takes arithmetic instructions, converts them into IR,
optimizes them using Constant Folding, and generates machine-like instructions.

---

## Features
- Custom Intermediate Representation (IR)
- Constant Folding Optimization
- Backend code generation (pseudo machine instructions)
- Modular compiler pipeline (Frontend → Optimization → Backend)

---

## Example
### Input Expression
(2 * 5) + (3 * 4)

### IR Before Optimization
MUL 2 5  
MUL 3 4  
ADD 10 12  

### After Constant Folding
All expressions are reduced to constants at compile-time.

---

## Technologies Used
- C++
- STL (vector, string)

---

## Learning Outcomes
- Understanding of compiler internals
- Optimization techniques
- Systems-level programming concepts

---

## Future Improvements
- Expression parsing
- Dead Code Elimination
- Register allocation
- LLVM IR support
