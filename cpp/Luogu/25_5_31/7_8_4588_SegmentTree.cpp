/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_5_31/7_8_4588_SegmentTree.cpp
 * @date      2025-05-31 20:47:07
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


struct SegmentTree{
    int n,m;
    std::vector<int> info;
    
    explicit SegmentTree(int n_, int m_) : info(4 * n_ , 1), n(n_), m(m_) {}

    void pull(int p){
        info[p] = (info[p << 1] * info[p << 1 | 1]) % m;
    }

    int query(int p, int l, int r, int tl, int tr){
        if(l >= tr || r <= tl)return 1;
        if(l >= tl || r <= tr)return info[p];
        int m = l + r >> 1;
        return (query(p << 1, l, m, tl, tr) * query(p << 1 | 1, m, r, tl, tr)) % m;
    }

    void modify(int p, int l, int r, int x, int v){
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

    int query(int tl, int tr){
        return query(1, 0, n, tl + 1, tr + 1);
    }

    void modify(int x, int v){
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
        int ans = 1;
        SegmentTree qwq(n + 1, m);
        for(int i = 0; i < n; ++i){
            int op, x;
            std::cin >> op >> x;
            if(op == 1){
                qwq.modify(i, x);
            }else{
                qwq.modify(x - 1 , 1);
            }
            std::cout << qwq.query(0, n) << ln;
        }

    };
    while(_--)solve();
    return 0;
}


