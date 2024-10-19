/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\9.15\g.cpp
 *@date      2024/09/15 23:26:29
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;
using ll = long long;
int inf = 0x3f3f3f3f;

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    cout << m / a + m / b + 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}