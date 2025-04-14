// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\IntroductionToAlgorithm\ChapterNULL\markefu.cpp
 * @date      2025/03/19 16:55:33
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

std::vector<double> gauss(std::vector<std::vector<double>> a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int max_row = i;
        for (int k = i; k < n; ++k)
            if (std::abs(a[k][i]) > std::abs(a[max_row][i])) max_row = k;
        std::swap(a[i], a[max_row]);
        if (std::fabs(a[i][i]) < 1e-9) return std::vector<double>();

        double factor = a[i][i];
        for (int k = i; k <= n; ++k) a[i][k] /= factor;

        for (int j = 0; j < n; ++j) {
            if (j != i && std::fabs(a[j][i]) > 1e-9) {
                double mult = a[j][i];
                for (int k = i; k <= n; ++k) a[j][k] -= mult * a[i][k];
            }
        }
    }

    std::vector<double> x(n);
    for (int i = 0; i < n; ++i) x[i] = a[i][n];
    return x;
}

double solve_expectation(int start) {
    if (start == 0 || start == 18) return 0.0;
    if (start < 1 || start > 17) return -1.0;

    int n = 17;
    std::vector<std::vector<double>> mat(n, std::vector<double>(n + 1, 0.0));

    for (int k = 0; k < n; ++k) {
        int i = k + 1;
        mat[k][k] = 1.0;
        mat[k][n] = 1.0;

        if (1 <= i && i <= 8) {
            if (i - 1 >= 1) mat[k][k - 1] = -0.4;
            if (i + 1 <= 17) mat[k][k + 1] = -0.6;
        } else if (i == 9) {
            mat[k][k - 1] = -0.5;
            if (k + 1 < n) mat[k][k + 1] = -0.5;
        } else if (10 <= i && i <= 17) {
            mat[k][k - 1] = -0.6;
            if (i + 1 <= 17) mat[k][k + 1] = -0.4;
        }
    }

    std::vector<double> x = gauss(mat);
    if (x.empty()) return -1.0;

    return x[start - 1];
}

double solve_probability(int start) {
    if (start == 0 || start == 18) return 0.0;

    const int max_time = 480;
    std::vector<double> prob(19, 0.0);
    prob[start] = 1.0;

    for (int t = 0; t < max_time; ++t) {
        std::vector<double> next_prob(19, 0.0);
        for (int j = 0; j <= 18; ++j) {
            if (j == 0 || j == 18) {
                next_prob[j] += prob[j];
                continue;
            }
            if (1 <= j && j <= 8) {
                next_prob[j - 1] += prob[j] * 0.4;
                next_prob[j + 1] += prob[j] * 0.6;
            } else if (j == 9) {
                next_prob[j - 1] += prob[j] * 0.5;
                next_prob[j + 1] += prob[j] * 0.5;
            } else {
                next_prob[j - 1] += prob[j] * 0.6;
                next_prob[j + 1] += prob[j] * 0.4;
            }
        }
        prob = std::move(next_prob);
    }

    double sum = 0.0;
    for (int j = 1; j <= 17; ++j) sum += prob[j];
    return sum;
}

void solve() {
    int start_pos;
    std::cin >> start_pos;

    double expectation = solve_expectation(start_pos);
    double probability = solve_probability(start_pos);

    std::cout << "Expected time: " << expectation << std::endl;
    std::cout << "Probability of surviving 8min: " << probability << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
