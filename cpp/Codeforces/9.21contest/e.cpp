/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\9.21contest\e.cpp
 *@date      2024/09/22 02:03:50
 */
#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
const int INF = LLONG_MAX;
const int N = 2e5 + 5;
int n, m, h;
vector<pair<int, int>> adj[N];
vector<int> horse_positions;
int t_m[N], t_r[N];    // Arrival times without horses
int assigned_horse[N]; // Assigned horse per node (-1: no horse, 0: Marian, 1: Robin)
int dis_m[N][2];       // Marian's distances [node][state]
int dis_r[N][2];       // Robin's distances [node][state]
bool visited_m[N][2];
bool visited_r[N][2];

void dijkstra_no_horse(int start, int t[], int person) {
    fill(t, t + n + 1, INF);
    t[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (t[u] < d) continue;
        for (auto [v, w] : adj[u]) {
            if (t[v] > t[u] + w) {
                t[v] = t[u] + w;
                pq.emplace(t[v], v);
            }
        }
    }
}

void dijkstra_with_horse(int start, int dis[][2], bool visited[][2], int person) {
    for (int i = 1; i <= n; ++i) {
        dis[i][0] = dis[i][1] = INF;
        visited[i][0] = visited[i][1] = false;
    }
    dis[start][0] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, start, 0); // distance, node, state
    while (!pq.empty()) {
        auto [d, u, state] = pq.top();
        pq.pop();
        if (visited[u][state]) continue;
        visited[u][state] = true;
        // Try to pick up a horse if we don't have one and there's an assigned horse here
        if (state == 0 && assigned_horse[u] == person) {
            if (dis[u][1] > dis[u][0]) {
                dis[u][1] = dis[u][0];
                pq.emplace(dis[u][1], u, 1);
            }
        }
        for (auto [v, w] : adj[u]) {
            int cost = w;
            if (state == 1) cost /= 2;
            if (dis[v][state] > dis[u][state] + cost) {
                dis[v][state] = dis[u][state] + cost;
                pq.emplace(dis[v][state], v, state);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> h;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        assigned_horse[i] = -1;
    }
    horse_positions.clear();

    for (int i = 0; i < h; ++i) {
        int x;
        cin >> x;
        horse_positions.push_back(x);
    }

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // Check connectivity between 1 and n
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    if (!visited[n]) {
        cout << -1 << '\n';
        return;
    }

    // Step 1: Dijkstra without horses for both Marian and Robin
    dijkstra_no_horse(1, t_m, 0); // Marian
    dijkstra_no_horse(n, t_r, 1); // Robin

    // Step 2: Assign horses based on arrival times
    for (int x : horse_positions) {
        if (t_m[x] < t_r[x]) {
            assigned_horse[x] = 0; // Marian
        } else if (t_r[x] < t_m[x]) {
            assigned_horse[x] = 1; // Robin
        } else {
            assigned_horse[x] = 0; // Tie-breaker to Marian
        }
    }

    // Step 3: Dijkstra with assigned horses for both Marian and Robin
    dijkstra_with_horse(1, dis_m, visited_m, 0); // Marian
    dijkstra_with_horse(n, dis_r, visited_r, 1); // Robin

    // Step 4: Find the earliest meeting time
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int t_mar = min(dis_m[i][0], dis_m[i][1]);
        int t_rob = min(dis_r[i][0], dis_r[i][1]);
        int T_v = max(t_mar, t_rob);
        ans = min(ans, T_v);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
