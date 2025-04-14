// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1014 div3\d.cpp
 * @date      2025/04/08 14:50:47
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
    std::string s;
    std::cin >> s;

    if (std::count(s.begin(), s.end(), s[0]) == n) {
        std::cout << -1 << ln;
        return;
    }

    std::vector<int> cnt(3), qwq(n);
    std::map<char, int> mp = {{'L', 0}, {'I', 1}, {'T', 2}};
    for (int i = 0; i < n; ++i) {
        qwq[i] = mp[s[i]];
        ++cnt[qwq[i]];
    }
    int min = *std::min_element(cnt.begin(), cnt.end());
    std::vector<int> ans;

    for (int x = 0; x < 3; x++) {
        if (cnt[x] == min) continue;
        int p = 1;
        while ((qwq[p] == x) == (qwq[p - 1] == x)) p++;
        while (cnt[x] > min) {
            if (qwq[p] == x) {
                int y = qwq[p - 1];
                qwq.insert(qwq.begin() + p, 3 - x - y);
                ans.push_back(p);
                qwq.insert(qwq.begin() + p + 1, y);
                ans.push_back(p + 1);
                p += 2;
            } else {
                int y = qwq[p];
                qwq.insert(qwq.begin() + p, 3 - x - y);
                ans.push_back(p);
                qwq.insert(qwq.begin() + p, y);
                ans.push_back(p);
            }
            cnt[x]--;
        }
    }
    std::cout << ans.size() << ln;
    for (auto x : ans) std::cout << x << ln;
}
signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
