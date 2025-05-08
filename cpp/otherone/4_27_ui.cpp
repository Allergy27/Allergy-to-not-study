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

vector<vector<int>> st(55, vector<int>(55, 17));
int a[55][55], n, m;
char ward[4] = {'E', 'S', 'W', 'N'};
int turn[4] = {0, 1, 2, 1};
int mox[4] = {0, 1, 0, -1}, moy[4] = {1, 0, -1, 0};
struct node {
    char chr;
    int x, y;
};

void dfs(int sx, int sy, char chr) {
    queue<node> q;
    q.push(node{chr, sx, sy});
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        int fa, so;
        for (int i = 0; i < 4; i++)
            if (ward[i] == p.chr) {
                fa = i;
                break;
            }
        for (int i = 0; i < 4; i++) {
            so = (fa + i) % 4;
            for (int j = 1; j <= 3; j++) {
                int mx = p.x + mox[so] * j, my = p.y + moy[so] * j;
                if (mx < 1 || my < 1 || mx > n || my > m || (mx == sx && my == sy) || a[mx][my]) {
                    break;
                } else {
                    if (st[p.x][p.y] + 1 + turn[i] <= st[mx][my]) {
                        st[mx][my] = st[p.x][p.y] + 1 + turn[i];
                        q.push(node{ward[so], mx, my});
                    }
                }
            }
        }
    }
    return;
}

void solve() {
    int ex, ey, sx, sy, x;
    char chr;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> x;
            if (x == 1) a[i - 1][j] = a[i + 1][j] = a[i][j - 1] = a[i][j + 1] = 1;
        }
    cin >> ex >> ey >> sx >> sy >> chr;
    st[sx][sy] = 0, a[ex][ey] = -1;
    dfs(sx, sy, chr);
    if (st[ex][ey] == MOD) st[ex][ey] = -1;
    cout << st[ex][ey] << ln;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    return 0;
}