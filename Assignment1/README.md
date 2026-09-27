# CGM Lab Assignment - 1: Basic Graphics Primitives

## Objective
To understand and implement basic 2D computer graphics primitives using C/C++ and the `graphics.h` (WinBGIm) library.

## Problem Statement
Write a C/C++ program to draw the following basic graphics primitives in a single program:
1. **A Straight Line**: Drawn using `line(x1, y1, x2, y2)` with marked endpoints.
2. **A Circle**: Drawn using `circle(xc, yc, radius)` with center and radius indicators.
3. **A Rectangle**: Drawn using `rectangle(left, top, right, bottom)` with corner coordinates.
4. **A Triangle**: Constructed by connecting 3 vertices using `line()` functions with marked vertices.

---

## Program Output Screenshot

![Program Output](output.png)

---

## Compilation & Execution

### Prerequisites
- C/C++ MinGW (32-bit) compiler with `graphics.h`, `winbgim.h`, and `libbgi.a` configured.

### Compile Command
```bash
g++ main.cpp -o main.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
```

### Run Command
```bash
./main.exe
```
