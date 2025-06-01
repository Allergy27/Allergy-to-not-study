/* copyright 2025 allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace cf 1023 div2/c_SegmentTree.cpp
 * @date      2025-05-30 20:07:55
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

struct Info{
    int sum = 0;
    int max = -1e18;
    int rmax = -1e18;
    int lmax = -1e18;
    explicit Info() {}
    explicit Info(int x) : sum(x), max(x), lmax(x), rmax(x) {}
};

Info operator+(const Info &a, const Info &b){
    Info c;
    c.sum = a.sum + b.sum;
    c.lmax = std::max(a.lmax, a.sum + b.lmax);
    c.rmax = std::max(b.rmax, b.sum + a.rmax);
    c.max = std::max({a.max, a.rmax + b.lmax, b.max});
    return c;
}

struct SegmentTree{
    int n;
    std::vector<Info> info;
    explicit SegmentTree(int n_) : n(n_), info(4 * n) {}

    void pull(int p){
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    Info query(int p, int l, int r, int tl, int tr){
        if(l >= tr || r <= tl)return Info();
        if(l >= tl && r <= tr)return info[p];
        int m = l + r >> 1;
        return query(p << 1, l, m, tl, tr) + query(p << 1 | 1, m, r, tl, tr);
    }

    void modify(int p, int l, int r, int x, const Info &v){
        if(r - l == 1){
            info[p] = v;
            return;
        }
        int m = l + r >> 1;
        if(x < m)
            modify(p << 1, l, m, x, v);
        else
            modify(p << 1 | 1, m, r, x, v);
        pull(p);
    }

    Info query(int tl, int tr){
        return query(1, 0, n, tl + 1, tr + 1);
    }
    void modify(int x, const Info &v){
        modify(1, 0, n, x + 1, v);
    }
};


signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;
    std::cin >> _;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;

        SegmentTree qwq(n + 1);
        std::vector<int> qvq(n);
    
        const int INF = 1e13;

        for(int i = 0;i < n ; ++i){
            std::cin >> qvq[i];
            if(s[i] == '0') qwq.modify(i, Info(-INF));
            else qwq.modify(i, Info(qvq[i]));
        }

        if(qwq.query(0, n).max > m){
            std::cout << "No\n";
            return;
        }

        for(int i = 0; i < n ; ++i){
            if(s[i] == '0'){
                int tmpl = qwq.query(0, i).rmax;
                int tmpr = qwq.query(i + 1, n).lmax;
                if(tmpl < 0)tmpl = 0;
                if(tmpr < 0)tmpr = 0;
                qwq.modify(i, Info(m - tmpl - tmpr));
                break;
            }
        }
    
        if(qwq.query(0, n).max != m){
            std::cout << "No\n";
            return;
        }

        std::cout << "Yes\n";
        for(int i = 0; i < n; ++i)
            std::cout << qwq.query(i,i + 1).sum << " \n"[i == n - 1];
        
    };
    while(_--)solve();
    return 0;
}


