// Copyright ui
#include <bits/stdc++.h>  // NOLINT
using namespace std;      // NOLINT
#define me(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define ln '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())   // NOLINT
#define ull unsigned long long  // NOLINT
const int MAXN = 1e5 + 5;
const int mod = 1e6 + 7;
const int MOD = 1e9 + 7;

int mov[] = {-1, 0, 1, 0, -1};
int a[505][505], n, m;
bool a0[505][505][505], a1[505];
struct p {
    int x, y;
};
struct sp {
    int l = MOD, r = -1;
} ax[505];

void bfs(int k) {
    if (n == 1) a1[k] = true;
    ax[k].l = k, ax[k].r = k;
    a0[k][1][k] = true;
    queue<p> q;
    q.push(p{1, k});
    while (!q.empty()) {
        p d = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = d.x + mov[i], dy = d.y + mov[i + 1];
            if (dx < 1 || dx > n || dy < 1 || dy > m) continue;
            if (a0[k][dx][dy] == 0 && a[dx][dy] < a[d.x][d.y]) {
                a0[k][dx][dy] = true;
                q.push(p{dx, dy});
                if (dx == n) ax[k].l = min(ax[k].l, dy), ax[k].r = max(ax[k].r, dy), a1[dy] = true;
            }
        }
    }
    // cout << ax[k].l << ' ' << ax[k].r << ln;
}

void solve() {
    int ans = 0, flag = 0, l = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= m; i++) bfs(i);
    for (int i = 1; i <= m; i++)
        if (!a1[i]) flag++;
    if (flag) {
        cout << 0 << ln << flag << ln;
    } else {
        int x = -1, r = -1;
        while (l <= m) {
            for (int i = 1; i <= m; i++)
                if (ax[i].l <= l && ax[i].r > r) {
                    x = i;
                    r = ax[i].r;
                }
            l = ax[x].r + 1;
            ans++;
        }
        cout << 1 << ln << ans << ln;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    return 0;
}
