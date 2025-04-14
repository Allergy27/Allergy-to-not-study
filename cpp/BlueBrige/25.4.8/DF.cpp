#include <bits/stdc++.h>
using namespace std;
#define me(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define ln '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
const int MAXN = 1e5 + 5;
const int mod = 1e6 + 7;
const int MOD = 1e9 + 7;
int kmp(string s, string t) {
    string S = t + ' ' + s;
    int n = S.length(), x = t.length(), rt = -1;
    vector<int> q(n + 1);
    for (int i = 1; i < n; i++) {
        int j = q[i - 1];
        while (j > 0 && S[i] != S[j]) j = q[j - 1];
        if (S[i] == S[j]) j++;
        if (i > x) rt = max(rt, j);
        q[i] = j;
    }
    return rt;
}
void solve() {
    string s, t;
    int n, ans, len = 0;
    cin >> s;
    n = sz(s);
    while (len * 2 + 1 <= n && s[len] == s[n - 1 - len]) len++;
    s = s.substr(len, n - 2 * len);
    t = s;
    reverse(all(s));
    ans = max(kmp(s, t), kmp(t, s));
    cout << ans + len << ln;
    return;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    return 0;
}