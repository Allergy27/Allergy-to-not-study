/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_6_3/8_9_3_MinCostFlow.cpp
 * @date      2025-06-03 19:11:01
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
        int n, m, k, end;
        std::cin >> n >> m >> k >> end;
        std::vector time(n, std::vector<int>(n));
        std::vector cost(n, std::vector<int>(n));

        for(auto &y : time)for(auto &x : y)std::cin >> x;
        for(auto &y : cost)for(auto &x : y)std::cin >> x;

        MinCostFlow<int> qwq(2 * m + 3); // (m - 1) * 2 + s + t + ss
        int s = 2 * m, ss = 2 * m + 1, t = 2 * m + 2;
        qwq.add(s, ss, k, 0);
        std::vector<std::array<int, 5>> qvq(m);
        for(int i = 0; i < m ; ++i){
            std::cin >> qvq[i][0] >> qvq[i][1] >> qvq[i][2] >> qvq[i][3] >> qvq[i][4];
            qwq.add(i, m + i, 1, -qvq[i][4]);
            if(time[0][qvq[i][0]] <= qvq[i][2])qwq.add(ss, i, 1, cost[0][qvq[i][0]]);
            if(qvq[i][3] + time[qvq[i][1]][0] <= end) qwq.add(m + i, t , 1, cost[qvq[i][1]][0]);
            for(int j = 0; j < i; ++j){
                if(qvq[i][3] + time[qvq[i][1]][qvq[j][0]] <= qvq[j][2])
                    qwq.add(m + i, j, 1, cost[qvq[i][1]][qvq[j][0]]);
                if(qvq[j][3] + time[qvq[j][1]][qvq[i][0]] <= qvq[i][2])
                    qwq.add(m + j, i, 1, cost[qvq[j][1]][qvq[i][0]]);
            }
        }
        auto [_, ans] = qwq.ssp(s, t);
        std::cout << -ans << '\n';
    };
    while(_--)solve();
    return 0;
}

