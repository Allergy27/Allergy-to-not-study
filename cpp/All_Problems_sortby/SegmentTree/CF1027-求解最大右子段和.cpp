#include<bits/stdc++.h>

#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n":"No\n");

#define int int64_t

using ll = int64_t;
using PII = std::pair<int,int>;

const int inf = 0x3f3f3f3f3f3f3f3f;

struct Info{
    int rmax = -inf;
    int sum = 0;
    explicit Info(int x) : rmax(x), sum(x) {}
    explicit Info() {}
};

Info operator+(const Info &a, const Info &b){
    Info c;
    c.sum = a.sum + b.sum;
    c.rmax = std::max(b.rmax , b.sum + a.rmax);
    return c;
}

struct SegmentTree{
    int n;
    std::vector<Info> info;

    explicit SegmentTree(int n_) : n(n_), info(4*n_) {}
    
    void pull(int p){
        info[p] = info[p*2] + info[p * 2 + 1];
    }

    Info query(int p , int l , int r , int tl , int tr){ 
        if(l >= tr || r <= tl)return Info();
        if(l >= tl && r <= tr)return info[p];
        int m = l + r >> 1;
        return query(p*2 , l ,m, tl , tr) + query(p*2+1, m, r, tl , tr);
    }

    void modify(int p , int l , int r ,int x , const Info &v){
        if(r - l == 1){
            info[p] = v;
            return;
        }
        int m = l + r >> 1;
        if(x < m)
            modify(p * 2 , l, m , x , v);
        else
            modify(p*2 +1, m, r , x , v);
        pull(p);
    }
    
    Info query(int tl, int tr){
        return query(1,0,n,tl,tr);
    }
    void modify(int x, const Info &v){
        modify(1,0,n,x,v);
    }
};


int32_t main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    auto solve = [&](){
        int n, m;
        std::cin  >> n;

        std::vector<int> deg(n + 1),ans(n + 1);
        for(int i= 1; i <= n ;++i)std::cin >> deg[i];
        std::vector<std::vector<int>> qwq(n + 1);
        for(int i=1;i<n;++i){
            int u, v;
            std::cin >> u >> v;
            qwq[u].emplace_back(v);
            qwq[v].emplace_back(u);
        }
         
        SegmentTree t1(n + 1),t2(n + 1);

        auto dfs = [&](auto &&dfs, int u , int fa ,int dep) -> void{
            if(dep % 2 == 1){
                t1.modify(dep,Info(deg[u]));
                t2.modify(dep,Info(-deg[u]));
                ans[u] = t1.query(1,dep + 1).rmax;
            }else{
                t1.modify(dep,Info(-deg[u]));
                t2.modify(dep,Info(deg[u]));
                ans[u] = t2.query(1,dep + 1).rmax;
            }
            for(auto v: qwq[u]){
                if(v != fa){
                    dfs(dfs, v, u , dep + 1);
                }
            }
        };
        dfs(dfs,1,0,1);
        for(int i = 1; i<=n;++i)std::cout << ans[i] << ' ';
        std::cout << ln;
    };
    while(_--)solve();
    return 0;
}
