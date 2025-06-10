/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace abc 407/g.cpp
 * @date      2025-05-31 16:58:52
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
        T cost = 0;
        while(spfa(s, t)){
            std::fill(ptr.begin(), ptr.end(), 0);
            while(T x = dfs(s, t, INF)){
                ans += x ;
                cost = std::min(cost, ret);
            }
        }
        return {ans, cost};
    }

};

signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n >> m;
        std::vector qwq(n, std::vector<int>(m));

        for(auto &y : qwq)
            for(auto &x : y)std::cin >> x;
        
        MinCostFlow<int> g(n * m + 2);

        int s = 0, t = 1 + n * m;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j + 1 < m ; ++j)
                if(qwq[i][j] + qwq[i][j + 1] < 0){
                    g.add(1 + i * m + j + ((i ^ j) & 1), 1 + i * m + j + !((i ^ j) & 1), 1, qwq[i][j] + qwq[i][j + 1]);
                }
        for(int i = 0; i + 1 < n; ++i)
            for(int j = 0; j < m; ++j)
                if(qwq[i][j] + qwq[i + 1][j] < 0){
                    g.add(1 + (i + ((i ^ j) & 1)) * m + j, 1 + (i + !((i ^ j) & 1)) * m + j, 1, qwq[i][j] + qwq[i + 1][j]);
                }           
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m ; ++j)
                if((i ^ j) & 1){
                    g.add(1 + i * m + j, t, 1, 0);
                }else{
                    g.add(s, 1 + i * m + j, 1, 0);
                }
        auto [flow, cost] = g.ssp(s, t);
        int ans = -cost;
        for(int i = 0; i < n; ++i)
            for(int j =0; j < m; ++j) ans += qwq[i][j];
        std::cout << ans << ln;

    };
    while(_--)solve();
    return 0;
}


