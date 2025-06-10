/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace tmp/leetcode.cpp
 * @date      2025-06-05 19:48:26
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
    auto solve = [&]() -> void{
        using namespace std;
        array<stack<int>, 26> qwq;
        uint32_t mask = 0;
        auto f = |uint32_t x|{
            for(int i = 0; i < 26; ++i)
                if(x & 1)return i;
            return 26;
        };
        const int n = s.size();
        for(int i = 0; i < n; ++i){
            if(s[i] == '*'){
                qwq[s[i] - 'a'].push(i);
                mask |= 1 << (s[i] - 'a');
            }else{
                int tmp = f(mask);
                auto &st = qwq[tmp];
                s[st.top()] = '*';
                st.pop();
                if(st.empty()) mask ^= 1 << tmp;
            }
        }
        string ans;
        for(auto x : s) if(x != '*') ans += x;
        return ans;
    };
    while(_--)solve();
    return 0;
}

