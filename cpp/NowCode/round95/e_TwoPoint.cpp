/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace round95/e.cpp
 * @date      2025-06-08 20:56:14
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
struct Info{
    int min = ll_inf;
    explicit Info() {}
    explicit Info(int x) : min(x) {}
};

Info operator+(const Info &a, const Info &b){
    Info c;
    c.min = std::min(a.min, b.min);
    return c;
}

struct SegmentTree{
    int n;
    std::vector<Info> info;
    explicit SegmentTree(int n_) : n(n_), info(4 * n_) {}

    void pull(int p){
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    
    Info query(int p, int l, int r, int tl, int tr){
        if(l >= tr || r <= tl)return Info();
        if(l >= tl && r <= tr)return info[p];
        int m = (l + r) >> 1;
        return query(p << 1, l, m, tl, tr) + query(p << 1 | 1, m, r, tl, tr);
    }

    void modify(int p, int l, int r, int x, const Info &v){
        if(r - l == 1){
            info[p] = v;
            return;
        }
        int m = (l + r) >> 1;
        if(x < m)
            modify(p << 1, l, m, x, v);
        else
            modify(p << 1 | 1, m, r, x, v);
        pull(p);
    }

    Info query(int tl, int tr){
        return query(1, 0, n, tl, tr + 1);
    }

    void modify(int x, const Info &v){
        modify(1, 0, n, x, v);
    }
};

signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;

    int ans = ll_inf;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n;
        SegmentTree qwq(n + 2);
        std::vector<int> qvq(n + 2);
        for(int i = 1; i <= n; ++i){
            std::cin >> qvq[i];
            qwq.modify(i, Info(qvq[i] * (n - i + 1)));
        }
        qwq.modify(n + 1, Info(0));
        std::unordered_set<int> st;
        for(int l = 1, r = 1; l <= n; ++l){
            while(r <= n && st.find(qvq[r]) == st.end()) st.insert(qvq[r++]);
            ans = std::min(ans, qvq[l - 1] * (l - 1) + qwq.query(0, r).min); 
            st.erase(qvq[l]);
        }
        std::cout << ans << ln;
    };
    while(_--)solve();
    return 0;
}


