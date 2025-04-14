// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\contry_contest\b.cpp
 * @date      2025/03/13 20:38:19
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int ab = 517 * 5, bc = 2632, ca = 308 * 5;

    // std::cout << "a : b -> " << ca << " : " << bc << ln;
    // std::cout << "b : c -> " << ab << " : " << ca << ln;
    // std::cout << "c : a -> " << bc << " : " << ab << ln;
    int pa = ca * ab, pb = bc * ab, pc = ca * bc;
    int gcd = std::__gcd(pa, std::__gcd(pb, pc));
    std::cout << pa / gcd << ',' << pb / gcd << ',' << pc / gcd << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
