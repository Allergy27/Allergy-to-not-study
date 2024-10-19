/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace VPE.cpp
 *@date      2024/04/11 18:47:32
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, K, m, a, b;
    cin >> n >> K >> m >> a >> b;
    if(n % m == 0) { cout << "0\n"; return; }
    if(K == 1) { cout << "-1\n"; return; }

    ll ans = 1e18, cost = 0;
    while(true) {
        ll l = n % m, qwq = 1;
        for(int i = 0; ; i++) {
            ll qaq = (m - l) % m;
            if(qaq < qwq) { //区间包含答案
                ans = min(ans, cost + i * a);
                break;
            }
            l = l * K % m;
            qwq *= K;
        }
        if(!n) break;
        n /= K;
        cost += b;
    }
    cout << ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}