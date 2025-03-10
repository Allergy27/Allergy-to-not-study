// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 2\sort.cpp
 * @date      2025/01/14 19:04:34
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct Student {
    int id, score;
};

int cmp(Student a, Student b) {
    return a.score > b.score;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Student> a(n);

    std::sort(a.begin(), a.end(), cmp);  // O(nlogn)
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
