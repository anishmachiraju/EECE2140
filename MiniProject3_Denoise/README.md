# MiniProject3_Denoise

Denoise a grayscale image represented as a text matrix using 3x3 neighborhood filters.

Build

```bash
g++ -std=c++17 -Wall -Wextra src/denoise.cpp -o denoise
```

Run

```bash
mkdir -p outputs
./denoise tests/small_input.txt outputs/small_output_mean.txt mean 1
./denoise tests/impulse_input.txt outputs/impulse_output_median.txt median 1
./denoise tests/border_input.txt outputs/border_output_mean.txt mean 2
```

Design notes
- Data: `std::vector<std::vector<int>>`
- Filters: `mean` and `median` (3x3)
- Border policy: clamp (replicate edge pixels)
- Values clamped to [0,255]

Copilot notes
- Copilot helped draft file parsing and median-sorting logic.
- I wrote and verified the filter loops and border handling.
- One bug Copilot suggested then missed: an off-by-one in median index; I verified median uses index 4 in 9-element array.

Demo

Example impulse noise reduction (median, 1 iteration):

```
Before - mean: 28.8 min: 0 max: 255
After - mean: 10 min: 10 max: 10
5 5
10 10 10 10 10
10 10 10 10 10
10 10 10 10 10
10 10 10 10 10
10 10 10 10 10
```

See `TESTING.md` for more examples.
