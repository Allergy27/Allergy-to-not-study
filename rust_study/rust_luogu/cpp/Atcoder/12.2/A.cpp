/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.2\A.cpp
 *@data      2023/12/02 19:52:19
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, y, m, d, D, M, j;
    cin >> M >> D;
    cin >> y >> m >> d;
    if(++d > D) {
        d = 1;
        if(++m > M) {
            m = 1;
            ++y;
        }
    }
    cout << y << ' ' << m << ' ' << d;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}