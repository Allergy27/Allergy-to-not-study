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

int ans = -1, i = 0;
string s, e;
struct t {
    string s;
    int n;
};
struct change {
    string sl, sr;
};
vector<change> v(10);

void bfs() {
    queue<t> q;
    q.push(t{s, 0});
    while (!q.empty()) {
        t str = q.front();
        q.pop();
        if (str.s == e) {
            ans = str.n;
            return;
        }
        if (str.n > 10) return;
        for (int j = 0; j < i; j++) {
            string p = str.s;
            int x = p.find(v[j].sl, 0);
            if (x == -1) {
                continue;
            } else {
                string y = p.replace(x, v[j].sl.length(), v[j].sr);
                q.push(t{y, str.n + 1});
            }
        }
    }
}

void solve() {
    cin >> s >> e;
    while (cin >> v[i].sl >> v[i].sr) i++;

    bfs();

    if (ans == -1)
        cout << "NO ANSWER!" << ln;
    else
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