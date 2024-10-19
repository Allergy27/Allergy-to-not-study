/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.23\B.cpp
 *@data      2023/12/24 12:44:58
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    long double a, m, l, r;
    cin >> a >> m >> l >> r;
    ll ans = floor((r - a) / m) - floor((l - a - 1) / m);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}