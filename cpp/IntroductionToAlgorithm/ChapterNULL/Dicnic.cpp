/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace IntroductionToAlgorithm\ChapterNULL\Dicnic.cpp
 *@date      2024/09/13 14:04:01
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
#define INF LLONG_MAX
const ll MAXN = 5e4 + 7;
const ll MAXM = 1e5 + 7;
int cnt = -1, head[MAXM], dis[MAXN], cur[MAXM];
int n, m;
struct edge {
    int to, value, net;
} e[MAXM << 1];  /// 共有n*2条边

void add(int from, int to, int value) {  /// 链式前向星
    cnt++;
    e[cnt].to = to;
    e[cnt].value = value;
    e[cnt].net = head[from];
    head[from] = cnt;
}

int bfs(int st, int ed) {  /// 建立层次图
    queue<int> que;
    memset(dis, -1, sizeof(dis));
    dis[st] = 0;
    que.push(st);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (int i = head[x]; i > -1; i = e[i].net) {
            int now = e[i].to;
            if (dis[now] == -1 && e[i].value) {
                que.push(now);
                dis[now] = dis[x] + 1;
            }
        }
    }
    return dis[ed] != -1;
}
int dfs(int x, int t, int maxflow) {
    if (x == t) return maxflow;
    int ans = 0;
    for (int i = cur[x]; i > -1; i = e[i].net) {  /// 当前弧优化
        int now = e[i].to;
        if (dis[now] != dis[x] + 1 || e[i].value == 0 || ans >= maxflow) continue;
        cur[x] = i;
        int f = dfs(now, t, min(e[i].value, maxflow - ans));
        e[i].value -= f;
        e[i ^ 1].value += f;  /// 反向边加流量
        ans += f;
    }
    if (!ans) dis[x] = -1;  /// 炸点优化
    return ans;
}
int Dinic(int st, int ed) {
    int ans = 0;
    while (bfs(st, ed)) {
        memcpy(cur, head, sizeof(head));
        int k;
        while ((k = dfs(st, ed, INF))) ans += k;
    }
    return ans;
}

void init() {
    cnt = -1;
    memset(head, -1, sizeof(head));
}

void add_init(int from, int to, int weight) {
    add(from, to, weight);
    add(to, from, 0);
}

void solve() {
    int ans = 0;
    cin >> n >> m;
    init();
    vector<int> a(n + 1), b(n + 1), v(n + 1), max_cost(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i] >> v[i];

    for (int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        add_init(0, i, w);  // 源点向菜建边
        ans += w;
        b[y] += w;
        add_init(i, m + y, w);  // 菜向人建边
        if (x != y) {
            b[x] += w;
            add_init(i, m + x, w);
        }
    }
    for (int i = 1; i <= n; ++i) {
        max_cost[i] = min(b[i] + v[i], a[i]);
        if (i != 1) {  // 对yyq以外来说
            max_cost[i] = min(max_cost[i], max_cost[1] - 1ll);
            if (max_cost[i] < v[i]) {
                cout << "NO";
                return;
            }
        }
        add_init(m + i, m + n + 1, max_cost[i] - v[i]);
    }
    if (Dinic(0, m + n + 1) == ans)
        cout << "YES";
    else
        cout << "NO";
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}