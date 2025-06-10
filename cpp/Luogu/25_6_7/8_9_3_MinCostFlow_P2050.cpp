/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_6_7/P2050.cpp
 * @date      2025-06-07 14:05:48
 */
#include<bits/stdc++.h>

#define int int64_t /* R.I.P */
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n");
#define lowbit(x) ((x)&-(x))

using ll = int64_t;
using PII = std::pair<int, int>;
const int inf = 0x3f3f3f3f;
const int ll_inf = 0x3f3f3f3f3f3f3f3f;

template<class T>
struct MinCostFlow{
    struct Edge {
        int to, re;
        T cep, cost;
        explicit Edge(int to, T cep, T cost, int re) : to(to), cep(cep), cost(cost), re(re) {}
    };
    
    /* extra add to solve this problem */
    std::vector<int> nxt, top;

    int n;
    std::vector<std::vector<Edge>> qwq;
    std::vector<bool> vis;
    std::vector<int> ptr;
    std::vector<T> dis;
    T ret;

    static constexpr T INF = std::numeric_limits<T>::max() / 2;

    explicit MinCostFlow(int n) : n(n), qwq(n), vis(n), ptr(n), dis(n), ret(0), nxt(n), top(n) {}
    
    void add(int u, int v, T cep, T cost){
        Edge eu = Edge(v, cep, cost, qwq[v].size());
        Edge ev = Edge(u, 0 , -cost, qwq[u].size());
        qwq[u].emplace_back(eu);
        qwq[v].emplace_back(ev);
    }

    bool spfa(int s, int t){
        std::fill(dis.begin(), dis.end(), INF);
        std::fill(vis.begin(), vis.end(), false);
        std::queue<int> que{{s}};
        dis[s] = 0, vis[s] = true;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            vis[u] = false;
            for(auto &v : qwq[u]){
                if(v.cep > 0 && dis[v.to] > dis[u] + v.cost){
                    dis[v.to] = dis[u] + v.cost;
                    if(!vis[v.to])vis[v.to] = true, que.push(v.to);
                }
            }
        }
        return dis[t] != INF;
    }

    T dfs(int u, int t, T flow){
        if(u == t)return flow;
        vis[u] = true;
        T ans = 0;
        for(int &i = ptr[u]; i < qwq[u].size() && ans < flow; ++i){
            auto &v = qwq[u][i];
            if(!vis[v.to] && v.cep > 0 && dis[v.to] == dis[u] + v.cost){
                if(T x = dfs(v.to, t, std::min(v.cep, flow - ans))){
                    ret += x * v.cost;
                    v.cep -= x;
                    qwq[v.to][v.re].cep += x;
                    ans += x;
                    /* extra to solve this problem */
                    nxt[u] = v.to;
                }
            }
        }
        vis[u] = false;
        return ans;
    }
    
    std::pair<T, T> ssp(int s, int t, int n, int m, int sum, std::vector<std::vector<int>> &time){
        T ans = 0;
        while(spfa(s, t)){
            std::fill(ptr.begin(), ptr.end(), 0);
            ans += dfs(s, t, INF);
            /* extra to solve this problem */
            for(int j = 0; j < m; ++j){
                if(nxt[n + j * sum + top[j] - 1] && top[j] < sum){ 
                    ++top[j];
                    int now = n + j * sum + top[j] - 1;
                    for(int i = 0; i < n; ++i) add(i, now, 1, time[i][j] * top[j]);
                    add(now, t, 1, 0);
                }
            }
        }
        return {ans, ret};
    }
};

signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;
    //std::cin >> _;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n >> m;
        std::vector<int> qvq(n);
        std::vector time(n, std::vector<int>(m));
        int sum = 0;
        for(auto &x : qvq)std::cin >> x, sum += x;
        for(auto &y : time)for(auto &x : y)std::cin >> x;
        
        int s = m * sum + n, t = m * sum + n + 1;
        MinCostFlow<int> qwq(t + 1);
        
        for(int i = 0; i < n; ++i)qwq.add(s, i, qvq[i], 0);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                qwq.add(i, n + j * sum, 1, time[i][j]);

        for(int i = 0; i < m; ++i){
            qwq.top[i] = 1;
            qwq.add(n + i * sum, t, 1, 0);
        }
        auto [_, cost] = qwq.ssp(s, t, n, m, sum, time);
        std::cout << cost << ln;
    };
    while(_--)solve();
    return 0;
}

