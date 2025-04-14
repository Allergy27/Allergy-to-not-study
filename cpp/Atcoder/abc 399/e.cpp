// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc399\e.cpp
 * @date      2025/03/29 20:52:06
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int countCycles(const std::map<char, char>& qwq) {
    std::set<char> visited;
    int cycleCount = 0;

    for (auto [start, _] : qwq) {
        if (visited.contains(start)) continue;

        std::set<char> currentPath;
        char current = start;
        bool isCycle = false;

        while (qwq.contains(current)) {
            if (currentPath.contains(current)) {
                isCycle = true;
                break;
            }
            if (visited.contains(current)) break;

            currentPath.insert(current);
            visited.insert(current);
            current = qwq.at(current);
        }

        if (isCycle) ++cycleCount;
    }

    return cycleCount;
}
void solve() {
    int n, m;
    std::cin >> n;
    std::map<char, char> qwq;
    std::string s, t;
    std::cin >> s;
    std::cin >> t;
    for (int i = 0; i < n; ++i) {
        if (qwq.contains(s[i]) && qwq[s[i]] != t[i]) {
            std::cout << -1 << ln;
            return;
        }
        qwq[s[i]] = t[i];
    }
    int cnt = countCycles(qwq);
    int ans = 0;
    for (auto [x, y] : qwq) {
        if (x != y)
            ++ans;
        else
            --cnt;
    }

    if (qwq.size() == 26 && cnt > 0) {
        std::cout << -1 << ln;
    } else {
        std::cout << cnt + ans << ln;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
