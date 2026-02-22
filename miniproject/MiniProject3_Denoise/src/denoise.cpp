#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

static int clamp255(int v) {
    if (v < 0) return 0;
    if (v > 255) return 255;
    return v;
}

static bool loadMatrix(const std::string &path, Matrix &m) {
    std::ifstream in(path);
    if (!in) return false;
    int rows = 0, cols = 0;
    if (!(in >> rows >> cols)) return false;
    m.assign(rows, std::vector<int>(cols));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int v;
            if (!(in >> v)) return false;
            m[r][c] = clamp255(v);
        }
    }
    return true;
}

static bool saveMatrix(const std::string &path, const Matrix &m) {
    std::ofstream out(path);
    if (!out) return false;
    if (m.empty()) return false;
    int rows = (int)m.size();
    int cols = (int)m[0].size();
    out << rows << " " << cols << "\n";
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            out << m[r][c] << (c + 1 < cols ? ' ' : '\n');
        }
    }
    return true;
}

// Border policy: clamp (replicate edge pixels)
static int getClamped(const Matrix &m, int r, int c) {
    int rows = (int)m.size();
    int cols = (int)m[0].size();
    r = std::max(0, std::min(r, rows - 1));
    c = std::max(0, std::min(c, cols - 1));
    return m[r][c];
}

static Matrix meanFilter(const Matrix &in) {
    int rows = (int)in.size();
    int cols = (int)in[0].size();
    Matrix out(rows, std::vector<int>(cols, 0));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int sum = 0;
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    sum += getClamped(in, r + dr, c + dc);
                }
            }
            out[r][c] = clamp255(sum / 9);
        }
    }
    return out;
}

static Matrix medianFilter(const Matrix &in) {
    int rows = (int)in.size();
    int cols = (int)in[0].size();
    Matrix out(rows, std::vector<int>(cols, 0));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int vals[9];
            int k = 0;
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    vals[k++] = getClamped(in, r + dr, c + dc);
                }
            }
            std::sort(vals, vals + 9);
            out[r][c] = vals[4];
        }
    }
    return out;
}

static void printStats(const std::string &label, const Matrix &m) {
    if (m.empty() || m[0].empty()) return;
    long sum = 0;
    int mn = 255, mx = 0;
    for (auto &row : m) for (int v : row) { sum += v; mn = std::min(mn, v); mx = std::max(mx, v); }
    double mean = double(sum) / (m.size() * m[0].size());
    std::cout << label << " - mean: " << mean << " min: " << mn << " max: " << mx << "\n";
}

int main(int argc, char **argv) {
    if (argc < 5) {
        std::cerr << "Usage: denoise <input.txt> <output.txt> <mean|median> <iterations>\n";
        return 1;
    }
    std::string inPath = argv[1];
    std::string outPath = argv[2];
    std::string filter = argv[3];
    int iterations = std::max(1, std::atoi(argv[4]));

    Matrix img;
    if (!loadMatrix(inPath, img)) {
        std::cerr << "Failed to load input: " << inPath << "\n";
        return 2;
    }

    printStats("Before", img);

    Matrix cur = img;
    for (int i = 0; i < iterations; ++i) {
        if (filter == "mean") cur = meanFilter(cur);
        else if (filter == "median") cur = medianFilter(cur);
        else {
            std::cerr << "Unknown filter: " << filter << "\n";
            return 3;
        }
    }

    printStats("After", cur);

    if (!saveMatrix(outPath, cur)) {
        std::cerr << "Failed to write output: " << outPath << "\n";
        return 4;
    }

    return 0;
}
