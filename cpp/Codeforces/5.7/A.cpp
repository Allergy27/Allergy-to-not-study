/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\5.7\A.cpp
 *@date      2024/05/07 20:30:58
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll x, y;
    auto gcd = [](auto self, ll x, ll y)->ll {return !y ? x : (self(self, y, x % y));};
    cin >> x >> y;
    ll t = gcd(gcd,x, y);
    cout << 1 << ' ' << (x * y) / (t * t) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    ll t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}