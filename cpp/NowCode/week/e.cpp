// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\week\e.cpp
 * @date      2024/11/10 20:18:12
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f;

int digit_sum(const string& s) {
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

void update(string s, ll L_num, int& ans) {  // NOLINT
    ll s_num = stoll(s);
    if (s_num >= L_num) {
        int sum = digit_sum(s);
        if (sum > ans) {
            ans = sum;
        }
    }
}

void solve() {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    ll L = l1 + l2;
    ll R = r1 + r2;
    string L_str = to_string(L);
    string R_str = to_string(R);
    int ans = digit_sum(R_str);

    for (int i = 0; i < R_str.size(); ++i) {
        if (R_str[i] > '0') {
            string s = R_str.substr(0, i);
            s += (char)(R_str[i] - 1);  // NOLINT
            s += string(R_str.size() - i - 1, '9');
            update(s, L, ans);
        }
    }
    // 检查 L
    int L_digit_sum = digit_sum(L_str);
    if (L_digit_sum > ans) {
        ans = L_digit_sum;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
