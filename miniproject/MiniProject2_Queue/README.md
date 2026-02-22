# Mini Project 2: Queue System (Header/Source Files and Modular Design)

## Overview
This project implements a reusable **array-based circular queue** in C++ with clean modular structure:
- `Queue.h` (declaration/API)
- `Queue.cpp` (implementation)
- `main.cpp` (interactive driver)

## File Structure
MiniProject4_Queue/
- include/Queue.h
- src/Queue.cpp
- main.cpp
- README.md
- TESTING.md

## Build and Run

### Option A: g++
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude main.cpp src/Queue.cpp -o queue_app
./queue_app
