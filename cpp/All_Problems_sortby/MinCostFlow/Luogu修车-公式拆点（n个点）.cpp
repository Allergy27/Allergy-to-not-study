/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_6_8/8_9_3_MinCostFlow_2053.cpp
 * @date      2025-06-08 12:18:26
 *
 *   ▄████████  ▄█        ▄█          ▄████████    ▄████████    ▄██████▄  ▄██   ▄   
 *  ███    ███ ███       ███         ███    ███   ███    ███   ███    ███ ███   ██▄ 
 *  ███    ███ ███       ███         ███    █▀    ███    ███   ███    █▀  ███▄▄▄███ 
 *  ███    ███ ███       ███        ▄███▄▄▄      ▄███▄▄▄▄██▀  ▄███        ▀▀▀▀▀▀███ 
 *▀███████████ ███       ███       ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ▀▀███ ████▄  ▄██   ███ 
 *  ███    ███ ███       ███         ███    █▄  ▀███████████   ███    ███ ███   ███ 
 *  ███    ███ ███▌    ▄ ███▌    ▄   ███    ███   ███    ███   ███    ███ ███   ███ 
 *  ███    █▀  █████▄▄██ █████▄▄██   ██████████   ███    ███   ████████▀   ▀█████▀  
 *             ▀         ▀                        ███    ███                        
 */
#include<bits/stdc++.h>

#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n");
#define lowbit(x) ((x)&-(x))
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 0x3f3f3f3f;
const i64 ll_inf = 0x3f3f3f3f3f3f3f3f;
template<class T>
struct MinCostFlow{
    struct Edge {
        int to, re;
        T cep, cost;
        explicit Edge(int to, T cep, T cost, int re) : to(to), cep(cep), cost(cost), re(re) {}
    };

    int n;
    std::vector<std::vector<Edge>> qwq;
    std::vector<bool> vis;
    std::vector<int> ptr;
    std::vector<T> dis;
    T ret;

    static constexpr T INF = std::numeric_limits<T>::max() / 2;

    explicit MinCostFlow(int n) : n(n), qwq(n), vis(n), ptr(n), dis(n), ret(0) {}

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
                }
            }
        }
        vis[u] = false;
        return ans;
    }

    std::pair<T, T> ssp(int s, int t){
        T ans = 0;
        while(spfa(s, t)){
            std::fill(ptr.begin(), ptr.end(), 0);
            while(T x = dfs(s, t, INF))ans += x;
        }
        return {ans, ret};
    }

};

signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;

    auto solve = [&]() -> void{
        int n, m;
        std::cin >> m >> n;
        std::vector qvq(n, std::vector<int>(m));
        for(auto &y : qvq)for(auto &x : y)std::cin >> x;
        
        // n -> 每个点只进入一次，拆点 n + n * m
        int s = n + n * m, t = n + n * m + 1;
        MinCostFlow<i64> qwq(t + 1);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                for(int k = 1; k <= n; ++k)
                    /* 每个人都有可能等 1 - n */
                    qwq.add(i, n + j * n + k - 1, 1, qvq[i][j] * k);
        //公式拆点
        for(int i = 0; i < n; ++i)qwq.add(s, i, 1, 0);
        for(int i = 0; i < n * m; ++i)qwq.add(n + i, t, 1, 0);
        auto [_, cost] = qwq.ssp(s, t);
        std::cout << std::fixed << std::setprecision(2) << static_cast<double>(cost) / n << "\n";
    };
    while(_--)solve();
    return 0;
}

