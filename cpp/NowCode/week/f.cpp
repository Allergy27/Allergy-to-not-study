// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\week\f.cpp
 * @date      2024/11/10 20:23:33
 */
#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 100; // 根据实际情况调整
vector<int> adj[MAXN]; // 邻接表表示图
int maxDist[MAXN][MAXN]; // maxDist[u][p] 表示从节点 u 到下 p 层的最大路径

void bfs(int start, int p) {
    queue<pair<int, int>> q; // 队列存储 (当前节点, 当前层数)
    vector<bool> visited(MAXN, false);
    q.push({start, 0});
    visited[start] = true;
    maxDist[start][0] = 0;

    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();

        if (depth == p) continue; // 达到 p 层，停止扩展

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, depth + 1});
                maxDist[start][depth + 1] = max(maxDist[start][depth + 1], maxDist[start][depth] + 1);
            }
        }
    }
}

void solve() {
    int n, m, p;
    cin >> n >> m >> p;

    // 初始化邻接表
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }

    // 读取边的信息
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 无向图
    }

    // 初始化 maxDist 数组
    memset(maxDist, -1, sizeof(maxDist));

    // 对每个节点运行 BFS
    for (int i = 0; i < n; ++i) {
        bfs(i, p);
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": ";
        for (int j = 0; j <= p; ++j) {
            if (maxDist[i][j] == -1) cout << "INF ";
            else cout << maxDist[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
