#include <bits/stdc++.h>
using namespace std;
#define me(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define ln '\n'
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int>(x.size())
const int MAXN = 1e6 + 5;
const int mod = 1e6 + 7;
const int MOD = 1e9 + 7;
int n, m;
int a[105][105], a0[105][105];
bool check(int x) {
    int res = 0;
    int floyd[105][105];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) floyd[i][j] = max(a[i][j] - x / n - (x % n >= i), a0[i][j]);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) res += floyd[i][j];
    return res <= m;
}
void solve() {
    int ans = -1;
    cin >> n >> m;
    int l = 0, r = (1e5 + 5) * n, mid;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a0[i][j];
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << ln;
    return;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    return 0;
}