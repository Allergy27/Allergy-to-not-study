#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define me(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define ln '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define ull unsigned long long
const int MAXN = 1e5 + 5;
const int mod = 1e6 + 7;
const int MOD = 1e9 + 7;

void solve() {
    int n, m, x = 0, ans = 0;
    cin >> n >> m;
    int a = m;
    while (a) {
        if (a % 2) ans++;
        a >>= 1;
    }
    if (ans == 0 && n == 1)
        cout << -1 << ln;
    else if (ans >= n)
        cout << m << ln;
    else if (ans < n)
        if (ans > 1) {
            int y = n - ans + 1;
            cout << m + y - y % 2 << ln;
        } else {
            if ((n + ans) % 2)
                cout << n + 3 << ln;
            else
                cout << n << ln;
        }

    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    return 0;
}