/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace template/int128.cpp
 * @date      2025-05-30 16:54:08
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

using lll = __int128;

std::ostream &operator<<(std::ostream &os, lll n){
    if(n == 0) return os << 0;
    std::string s;
    while(n > 0) s += static_cast<char>('0' + n % 10), n /= 10;
    std::reverse(s.begin(), s.end());
    return os << s;
}

lll tolll(const std::string &s){
    lll n = 0;
    for(auto c : s) n = n * 10 + (c - '0');
    return n;
}

lll sqrtlll(lll n){
    lll lo = 0, hi = 1e16;
    while(lo < hi){
        lll x = (lo + hi + 1) / 2;
        if(x * x <= n){
            lo = x;
        }else{
            hi = x - 1;
        }
    }
    return lo;
}

lll gcd(lll a, lll b){
    while(b){
        a %= b;
        std::swap(a, b);
    }
    return a;
}
