/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.23\D.cpp
 *@data      2023/12/24 14:35:54
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, q, i;
    ll j;
    cin >> n >> q;
    vector<ll>qwq(n);
    for(auto &x : qwq)cin >> x;
    sort(qwq.begin(), qwq.end());
    for(i = 1;i < n;++i)qwq[i] += qwq[i - 1];
    for(i = 0;i < q;++i) {
        cin >> j;
        cout <<' '<< (upper_bound(qwq.begin(), qwq.end(), j)-qwq.begin())<<'\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}