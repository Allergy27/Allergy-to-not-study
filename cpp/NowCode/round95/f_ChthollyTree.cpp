/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace round95/f_ODT.cpp
 * @date      2025-06-10 11:39:08
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

signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;
    std::cin >> _;

    struct Node{
        int l, r;
        mutable int v;
        explicit Node(const int &l,const int &r,const int &v) : l(l), r(r), v(v) {}
        bool operator<(const Node &rhs) const { return l < rhs.l; }
    };

    const int N = 1e5 + 27;
    

    /* use Chtholly Tree */
    std::set<Node>odt{{Node(0, N - 1, 0)}};
    std::map<int, int> cnt{{0, 1}};
    std::set<int> ans{0};

    auto split = [&](int x) -> std::set<Node>::iterator {
        auto it = odt.lower_bound(Node(x, 0, 0));
        if(it != odt.end() && it -> l == x) return it;
        --it;
        int l = it -> l, r = it -> r, v = it -> v;
        odt.erase(it);
        odt.insert(Node(l, x - 1, v));
        auto res = odt.insert(Node(x, r, v)).first;

        /* extra for this problem */
        if(--cnt[v] == 0)ans.erase(v);
        cnt[v] += 2;
        if(cnt[v] > 0)ans.insert(v);
        /* END */

        return res;
    };  

    auto assign = [&](int l, int r, int v) -> void{
        auto itr =split(r + 1), itl = split(l);

        /* extra for this problem */
        std::vector<Node> tmp;
        auto it = itl;
        while(it != itr) tmp.emplace_back(*it), it++;
        for(auto node : tmp){
            int v = node.v;
            if(--cnt[v] == 0) ans.erase(v);
        }
        if(cnt[v]++ == 0) ans.insert(v);
        /* END */

        odt.erase(itl, itr);
        odt.insert(Node(l, r, v));

   };

    auto solve = [&]() -> void{
        int l, r, v;
        std::cin >> l >> r >> v;
        assign(l, r, v);
        std::cout << ans.size() << '\n';
    };

    while(_--)solve();
    return 0;
}

