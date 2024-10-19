/*Copyright [year]
 *@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\9.21contest\b.cpp
 *@date      2024/09/21 23:04:34
 */
#include <bits/stdc++.h>
// #define int long long

using namespace std; // NOLINT
using ll = __int64;
int inf = 0x3f3f3f3f;

void solve() {
    int n, k, f;
    __gcd(1, 12);
    cin >> n >> k;
    if (n & 1)
        f = (k - 1) / 2 + 1;
    else
        f = k / 2;
    cout << (f & 1 ? "NO\n" : "YES\n");
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
