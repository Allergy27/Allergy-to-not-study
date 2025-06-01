// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 2023-2024 ICPC AJRC\e.cpp
 * @date      2025/04/15 10:12:23
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> qwq(2 * n), qvq;

    // 构造逆序长度数组
    std::vector<int> idx;
    idx.emplace_back(0);
    for (int i = 0; i < 2 * n; ++i) {
        std::cin >> qwq[i];
        if (qwq[i] > qwq[idx.back()]) idx.emplace_back(i);
    }
    idx.emplace_back(2 * n);

    for (int i = idx.size() - 1; i > 0; --i) qvq.emplace_back(idx[i] - idx[i - 1]);
    int m = qvq.size();

    std::vector<std::vector<bool>> f(m + 1, std::vector<bool>(n + 1));

    // 恰好满足型背包🎒
    f[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        int x = qvq[i - 1];
        for (int j = 0; j <= n; ++j) {
            if (j < x)
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = f[i - 1][j] || f[i - 1][j - x];
        }
    }

    // 没法恰好装满说明不符合
    if (!f[m][n]) {
        std::cout << -1 << ln;
        return;
    }

    std::vector<int> ans[2];
    std::vector<bool> used(m);
    int res = n;

    // 回溯
    for (int i = m - 1; i >= 0 && res > 0; --i) {
        if (res >= qvq[i] && f[i][res - qvq[i]]) {
            used[i] = true;
            res -= qvq[i];
        }
    }

    int point = 2 * n - 1;

    // 装填答案
    for (int i = 0; i < m; ++i) {
        for (int j = point; j > point - qvq[i]; --j) ans[used[i]].emplace_back(qwq[j]);
        point -= qvq[i];
    }

    // 倒序输出
    for (int t = 0; t < 2; ++t) {
        for (int i = n - 1; i >= 0; --i) std::cout << ans[t][i] << ' ';
        std::cout << ln;
    }

    // 用于验证答案：
    // auto merge = [](std::vector<int> a, std::vector<int> b) {
    //     std::vector<int> c;
    //     int n = a.size();
    //     int i = 0, j = 0;
    //     while (i < n && j < n) {
    //         if (a[i] < b[j])
    //             c.emplace_back(a[i++]);
    //         else
    //             c.emplace_back(b[j++]);
    //     }
    //     while (i < n) c.emplace_back(a[i++]);
    //     while (j < n) c.emplace_back(b[j++]);
    //     return c;
    // };

    // std::vector<int> a = {9, 8, 7, 15, 14, 20, 19, 18, 17, 16};
    // std::vector<int> b = {6, 5, 4, 3, 2, 1, 11, 10, 13, 12};
    // std::vector<int> c = merge(a, b);
    // for (auto x : c) std::cout << x << ' ';
    // std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
