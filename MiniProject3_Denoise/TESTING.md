# Testing

Build:

```bash
g++ -std=c++17 -Wall -Wextra src/denoise.cpp -o denoise
```

Runs:

1) Small matrix

```bash
./denoise tests/small_input.txt outputs/small_output_mean.txt mean 1
cat outputs/small_output_mean.txt
```

Expected: central high value (200) reduced by mean filter to uniform value (31).

2) Impulse noise

```bash
./denoise tests/impulse_input.txt outputs/impulse_output_median.txt median 1
cat outputs/impulse_output_median.txt
```

Expected: `median` filter removes salt-and-pepper noise effectively; output uniform 10.

3) Border behavior

```bash
./denoise tests/border_input.txt outputs/border_output_mean.txt mean 2
cat outputs/border_output_mean.txt
```

Expected: border pixels handled by clamping (replicating edges), not zero-padded.
