// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1024 div2\c.cpp
 * @date      2025/05/11 22:56:40
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n;
        std::vector qwq(n, std::vector<int>(n));
        int num = n * n - 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) qwq[top][i] = num--;
            top++;

            for (int i = top; i <= bottom; ++i) qwq[i][right] = num--;
            right--;

            for (int i = right; i >= left; --i) qwq[bottom][i] = num--;
            bottom--;

            for (int i = bottom; i >= top; --i) qwq[i][left] = num--;
            left++;
        }
        for (auto x : qwq) {
            for (auto y : x) std::cout << y << ' ';
            std::cout << ln;
        }
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
