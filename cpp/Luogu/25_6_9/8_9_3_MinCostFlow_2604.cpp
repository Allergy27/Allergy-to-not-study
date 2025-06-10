/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_6_9/8_9_3_MinCostFlow_2604.cpp
 * @date      2025-06-09 19:51:35
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

#define int int64_t /* R.I.P */
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

struct MinCostFlow{
    struct Edge{
        int to, re;
        i64 cep, cost;
        explicit Edge(int to, int re, i64 cep, i64 cost) : to(to), re(re), cep(cep), cost(cost) {}
    };
    
    explicit MinCostFlow(int n_) : n(n_), qwq(n_), vis(n_), ptr(n_), dis(n_), ret(0) {}

    static constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;
    int n;
    i64 ret;
    std::vector<std::vector<Edge>> qwq;
    std::vector<bool> vis;
    std::vector<int> ptr;
    std::vector<i64> dis;
    
    void add(int u, int v, i64 cep, i64 cost){
        Edge eu = Edge(v, qwq[v].size(), cep, cost);
        Edge ev = Edge(u, qwq[u].size(), 0,  -cost);
        qwq[u].emplace_back(eu);
        qwq[v].emplace_back(ev);
    }

    bool spfa(int s, int t){
        std::fill(vis.begin(), vis.end(), false);
        std::fill(dis.begin(), dis.end(), INF);
        std::queue<int> que{{s}};
        dis[s] = 0, vis[s] = true;
        while(!que.empty()){
            auto u = que.front();
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

    i64 dfs(int u, int t, i64 flow){
        if(u == t) return flow;
        i64 ans = 0;
        vis[u] = true;
        for(int &i = ptr[u]; i < qwq[u].size(); ++i){
            auto &v = qwq[u][i];
            if(!vis[v.to] && v.cep > 0 && dis[v.to] == dis[u] + v.cost){
                if(i64 x = dfs(v.to, t, std::min(flow - ans, v.cep))){
                    v.cep -= x;
                    qwq[v.to][v.re].cep +=x;
                    ans += x;
                    ret += x * v.cost;
                }
            }
        }
        vis[u] = false;
        return ans;
    }

    std::pair<i64, i64> ssp(int s, int t){
        i64 ans = 0;
        while(spfa(s, t)){
            std::fill(ptr.begin(), ptr.end(), 0);
            while(i64 x = dfs(s, t, INF)){
                ans += x;
            }
        }
        return {ans, ret};
    }
};

signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;

    auto solve = [&]() -> void{
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::array<int, 4>> edges(m);
    
        int s = 0, t = n - 1, tt = n;
        MinCostFlow qwq(n + 1);
        for(auto &[u, v, cep, cost] : edges){
            std::cin >> u >> v >> cep >> cost;
            --u, --v;
            qwq.add(u, v, cep, 0);
        }
        auto [origin_flow, _cost] = qwq.ssp(s, t);
        
        for(auto [u, v, cep, cost] : edges) qwq.add(u, v, ll_inf, cost);
        qwq.add(t, tt, k, 0);
        
        auto [_maxflow, ans] = qwq.ssp(s, tt);
        std::cout << origin_flow << ' ' << ans << '\n';
    };
    while(_--)solve();
    return 0;
}

