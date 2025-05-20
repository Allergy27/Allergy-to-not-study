/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\IntroductionToAlgorithm\Chapter1\MERGE_SORT Dictation.cpp
 * @date      2025/05/18 16:26:45
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void MERGE_SORT(std::vector<int> &, int, int);

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n;
        std::cout << "Please enter the lenth of the list:";
        std::cin >> n;
        std::vector<int> qwq(n);
        for (auto &x : qwq) std::cin >> x;
        MERGE_SORT(qwq, 0, n - 1);
        for (auto &x : qwq) std::cout << x << " ";
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}

void MERGE_SORT(std::vector<int> &list, int p, int r) {
    int q = (p + r) / 2;         // 二分
    if (p >= r) return;          // 当左大于右的时候退出
    MERGE_SORT(list, p, q);      // 分裂左边
    MERGE_SORT(list, q + 1, r);  // 分裂右边
    // 下面是合并函数，干脆写在一起了。
    std::vector<int> L, R;  // 记录左右子树？可以这么理解罢。
    int a = 0, b = 0;       // 两个指针，记录左右各自取到哪里了。
    for (int x = p; x <= q; ++x) L.emplace_back(list[x]);
    for (int x = q + 1; x <= r; ++x) R.emplace_back(list[x]);
    for (int k = p; k <= r; ++k) {
        if (a == q + 1 - p)
            list[k] = R[b++];  // 如果L取完了，那就只取R了
        else if (b == r - q)
            list[k] = L[a++];  // 如果R取完了，那就只取L了
        else if (L[a] < R[b])
            list[k] = L[a++];  // 取小的那一个放
        else
            list[k] = R[b++];
    }
}