// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p4995.cpp
 * @date      2025/01/16 12:39:27
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n;

    // 排序实现
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    sort(qwq.begin(), qwq.end());
    int l = 0;
    int r = n - 1;
    int ans = qwq[n - 1] * qwq[n - 1];
    int f = 1;
    while (l < r) {
        ans += (qwq[r] - qwq[l]) * (qwq[r] - qwq[l]);
        if (f)
            --r;
        else
            ++l;
        f ^= 1;
    }
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
// 堆的实现
// std::priority_queue<int> max_heap;
// std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
// for (int i = 0; i < n; ++i) {
//     int x;
//     std::cin >> x;
//     max_heap.push(x);
//     min_heap.push(x);
// }
// for(int i=0;i<n;++i){
//     max_heap
// }