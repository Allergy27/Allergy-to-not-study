// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 398\f.cpp
 * @date      2025/03/22 20:26:36
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

bool isPalindrome(const std::string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        ++start;
        --end;
    }
    return true;
}
void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    if (n == 0) {
        std::cout << s << ln;
        return;
    }

    int max_k = 0;
    for (int k = n; k >= 1; --k) {
        if (isPalindrome(s, n - k, n - 1)) {
            max_k = k;
            break;
        }
    }
    std::string add = s.substr(0, n - max_k);
    reverse(add.begin(), add.end());
    std::cout << s + add << ln;
    return;
}


signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
