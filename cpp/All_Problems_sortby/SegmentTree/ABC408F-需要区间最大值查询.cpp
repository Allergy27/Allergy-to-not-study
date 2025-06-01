/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace abc 408/f.cpp
 * @date      2025-06-01 12:32:13
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
    int max = -inf;
    int cnt = 0;
    explicit Info() {}
    explicit Info(int x) : sum(x), max(x), cnt(1) {}
};

Info operator+(const Info &a, const Info &b){
    Info c;
    c.sum = a.sum + b.sum;
    c.max = std::max(a.max, b.max);
    c.cnt = a.cnt + b.cnt;
    return c;
}

struct SegmentTree{
    int n;
    std::vector<Info> info;
    
    explicit SegmentTree(int n_) : info(4 * n_), n(n_) {}

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

    auto solve = [&]() -> void{
        int n, d, r;
        std::cin >> n >> d >> r;
        std::vector<int> qvq(n);
        for(auto &x : qvq)std::cin >> x, x--;
        std::vector<int> pos(n);
        for(int i = 0; i < n ; ++i)pos[qvq[i]] = i;
        std::vector<int> dp(n);
        SegmentTree qwq(n);
        for(int i = 0; i < n; ++i){
            if(i - d >= 0){
                qwq.modify(pos[i - d], Info(dp[i - d]));
            }
            auto tmp = qwq.query(std::max(0L, pos[i] - r), std::min(n, pos[i] + r + 1)).max;
            dp[i] = std::max(dp[i], tmp + 1);
        }
        std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    };
    while(_--)solve();
    return 0;
}


