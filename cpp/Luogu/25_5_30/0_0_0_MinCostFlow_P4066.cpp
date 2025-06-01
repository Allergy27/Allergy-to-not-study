/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_5_30/P4066.cpp
 * @date      2025-05-30 18:30:48
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
    //std::cin >> _;
    auto solve = [&]() -> void{
        int n;
        std::cin >> n;
        std::vector<std::array<int, 3>> qvq(n);
        for(int i = 0; i < n; ++i){
            int x, y;
            std::cin >> qvq[i][0] >> qvq[i][1];
            qvq[i][2] = i;
        }

        int s = 2 * n, t = 2 * n + 1, ss = t + 1;
        MinCostFlow<int> qwq(ss + 1);
        qwq.add(s, ss, 2, 0);

        for(int i = 0; i < n; ++i){
            qwq.add(ss, i, inf, 0);    //  second to all_1
            qwq.add(i + n, t, inf, 0); //  all_2 to end
            qwq.add(i, i + n, 1, -1);  //  first_time u get 1
            qwq.add(i, i + n, 2, 0);   //  second_time u just pass
        }

        std::sort(qvq.begin(), qvq.end());

        for(int i = 0; i < n - 1; ++i){
            int tmp = inf;
            for(int j = i + 1; j < n; ++j){
                /* Must uppper than past so u can transform */
                if(qvq[j][1] >= qvq[i][1]  && qvq[j][1] < tmp){
                    tmp = qvq[j][1];
                    qwq.add(n + qvq[i][2], qvq[j][2], inf, 0);
                }
            }
        }
        
        auto [_, cost] = qwq.ssp(s, t);
        std::cout << -cost << ln;
    };
    while(_--)solve();
    return 0;
}


