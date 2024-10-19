/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace IntroductionToAlgorithm\ChapterNULL\Dicnic.cpp
 *@date      2024/09/13 14:04:01
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
typedef pair<int, int> pii;
vector<pii> e[N];
int g[N], cnt=0, d[N], cur[N], n, m;

void add(int a, int b, int w) {
    int x = cnt++, y = cnt++;
    e[a].push_back({ b, x });
    e[b].push_back({ a, y });
    g[x] = w, g[y] = 0;
}
bool bfs(int s, int t) {
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto [v, w] : e[N]) {
            if(d[v] == 0 && g[w]) {
                q.push(v);
                d[v] = d[u] + 1;
                if(v == t) return true;
            }
        }
    }
    return false;
}
int dfs(int u, int t, int flow) {
    if(u == t) return flow;
    int ans = 0;
    for(int &i = cur[u];i < e[u].size();i++) {
        auto [v, w] = e[u][i];
        if(d[v] == d[u] + 1 && g[w]) {
            int re = dfs(v, t, min(flow, g[w]));
            ans += re;
            flow -= re;
            g[w] -= re;
            g[w ^ 1] += re;
            if(flow == 0)
                return ans;
        }
    }
    if(ans == 0) d[u] = 0;
    return ans;
}
int dinic(int s, int t) {
    int ans = 0;
    while(bfs(s, t)) {
        // cout << 1 << endl;
        memset(cur, 0, sizeof(cur));
        ans += dfs(s, t, 1e9);
    }
    return ans;
}
void solve() {
    int ans = 0;
    cin >> n >> m;
    // init();
    // cout << n << m;
    vector<int> a(n + 1), b(n + 1), v(n + 1), max_cost(n + 1);

    for(int i = 1; i <= n; ++i)cin >> a[i] >> v[i];

    for(int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        add(0, i, w); //源点向菜建边
        ans += w;
        b[y] += w;
        add(i, m + y, w); //菜向人建边
        if(x != y) {
            b[x] += w;
            add(i, m + x, w);
        }
    }
    for(int i = 1;i <= n;++i) {
        max_cost[i] = min(b[i] + v[i], a[i]);
        if(i != 1) { //对yyq以外来说
            max_cost[i] = min(max_cost[i], max_cost[1] - 1ll);
            if(max_cost[i] < v[i]) {
                cout << "NO";
                return;
            }
        }
        add(m + i, m + n + 1, max_cost[i] - v[i]);
    }
    if(dinic(0, m + n + 1) == ans)cout << "YES";
    else cout << "NO";
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}