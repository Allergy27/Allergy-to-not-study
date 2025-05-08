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

int a[70], n;
bool vis[70], flag = false;

bool check() {
    for (int i = 1; i <= n; i++)
        if (!vis[i]) return false;
    return true;
}

void dfs(int f, int num) {
    for (int i = 1; i <= n; i++) {
        if (flag) return;
        num += a[i];
        if (num <= f) {
            vis[i] = true;
            if (num == f && !check()) flag = true;
            if (flag) return;
            dfs(f, num % f);
            vis[i] = false;
        }
        num -= a[i];
    }
}

void solve() {
    int ans = 0, sum = 0, maxn = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i], maxn = max(maxn, a[i]);
    }
    int x = sum / maxn;
    // cout << x << ' ' << sum << ln;
    for (int i = x; i > 0; i--) {
        // cout << i << ln;
        if (sum % i == 0) {
            ans = sum / x;
            // cout << ans << ' ';
            if (i == 1) break;
            dfs(ans, 0);
            if (flag) break;
        }
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