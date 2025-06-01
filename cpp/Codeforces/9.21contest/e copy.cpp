/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\9.21contest\e.cpp
 *@date      2024/09/22 02:03:50
 */
#include <bits\stdc++.h>
#define int long long
using ll = long long;
using namespace std;
const int N = 1000000;
const ll infll = 0x3f3f3f3f3f3f3f3f;
ll n, m, k, q;
ll ans;
bool flag;
ll a[N];

struct Node {
    int to, cost;
};

vector<Node> g[N];

struct UFSet {
    vector<int> p, sz;
    vector<set<pair<int, int>>> s;

    UFSet(int n) : p(n + 1), sz(n + 1, 1), s(n + 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (s[x].size() < s[y].size()) swap(x, y);
        for (auto p : s[y]) s[x].insert(p);
        sz[x] += sz[y];
        p[y] = x;
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }
};

int dist[N][2][2];

struct Status {
    bool horse;
    int pos;
    int cost;

    bool operator>(const Status &rhs) const {
        return cost > rhs.cost;
    }
};

void bfs(int start, int user) {
    priority_queue<Status, vector<Status>, greater<>> q;
    q.push({a[start] == 1, start, 0});
    dist[start][user][a[start]] = 0;
    while (!q.empty()) {
        auto [horse, pos, cost] = q.top();
        q.pop();
        if (dist[pos][user][horse] < cost) continue;
        horse |= a[pos];
        for (auto [to, w] : g[pos]) {
            if (horse) w /= 2;
            if (dist[to][user][horse] > cost + w) {
                dist[to][user][horse] = cost + w;
                q.push({horse, to, cost + w});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    UFSet ust(n + 1);
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        dist[i][0][0] = dist[i][0][1] = dist[i][1][0] = dist[i][1][1] = infll;
        a[i] = 0;
    }
    for (int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        ust.merge(u, v);
    }
    if (ust.find(1) != ust.find(n)) {
        cout << (-1) << '\n';
        return;
    }
    ans = infll;
    bfs(1, 0);
    bfs(n, 1);
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, max(min(dist[i][0][0], dist[i][0][1]), min(dist[i][1][0], dist[i][1][1])));
        // if (k == 1) {
        //     assert(!(dist[i][0][1] == infll && dist[i][1][1] == infll));
        // }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}