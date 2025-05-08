// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 794 div2\d.cpp
 * @date      2025/04/14 18:13:07
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> ab, ba, odd;

    if (std::count(s.begin(), s.end(), 'A') != a + c + d || std::count(s.begin(), s.end(), 'B') != b + c + d) {
        std::cout << "No" << ln;
        return;
    }

    int cnt_ab = 0, cnt_ba = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j + 1 < n && s[j] != s[j + 1]) ++j;
        int len = j - i + 1;
        if (len & 1) {
            odd.emplace_back(len / 2);
        } else {
            if (s[i] == 'A')
                ab.emplace_back(len / 2), cnt_ab += len / 2;
            else
                ba.emplace_back(len / 2), cnt_ba += len / 2;
        }
        i = j;
    }

    for (auto x : odd) {
        int tmp = std::min(std::max(0LL, c - cnt_ab), x);
        cnt_ab += tmp;
        cnt_ba += x - tmp;
    }

    std::sort(ab.begin(), ab.end(), std::greater<int>());
    std::sort(ba.begin(), ba.end(), std::greater<int>());

    for (int x : ba) {
        if (cnt_ba > d) {
            int tmp = std::min(--cnt_ba - d, --x);
            cnt_ba -= tmp;
            cnt_ab += tmp;
        }
    }
    for (int x : ab) {
        if (cnt_ab > c) {
            int tmp = std::min(--cnt_ab - c, --x);
            cnt_ab -= tmp;
            cnt_ba += tmp;
        }
    }

    if (cnt_ab >= c && cnt_ba >= d)
        std::cout << "Yes" << ln;
    else
        std::cout << "No" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
