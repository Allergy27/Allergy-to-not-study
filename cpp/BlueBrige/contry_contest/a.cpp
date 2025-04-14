// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\contry_contest\a.cpp
 * @date      2025/03/13 20:26:49
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::string s =
        "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
    int n = s.size();
    int ans = 0;
    for (int i = 8; i <= 16; ++i) {
        for (int j = 0; j < n - i; ++j) {
            bool fh = 0, num = 0;
            for (int k = 0; k < i; ++k) {
                if (isdigit(s[j + k])) num = 1;
                if (s[j + k] == '#') fh = 1;
            }
            if (fh && num) ++ans;
        }
    }
    std::cout << ans << ln;  // std::cout << 400 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
