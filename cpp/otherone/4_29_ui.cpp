#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define me(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define ln std::endl
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define ull unsigned long long
const int MAXN = 1e5 + 5;
const int mod = 1e6 + 7;
const int MOD = 1e9 + 7;

void solve() {
    int n, m, x = 0, mx = -1, ans = 0;
    cin >> n;
    vector<int> a(n), an(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
        an[i] = mx;
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << ans + an[i] << ' ';
        ans += a[i];
    }
    cout << ln;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    return 0;
}