/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\9.14\b.cpp
 *@date      2024/09/14 22:54:42
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;
using ll = long long;
int inf = 0x3f3f3f3f;

void solve() {
    int n, m, q, dvd;
    cin >> n >> m >> q;
    set<int>qvq;
    for(int i = 0;i < m;++i) {
        int cnt;
        cin >> cnt;
        qvq.insert(cnt);
    }
    vector<int>qwq;
    for(auto x : qvq)qwq.emplace_back(x);
    while(q--) {
        cin >> dvd;
        int r = upper_bound(qwq.begin(), qwq.end(), dvd) - qwq.begin();
        if(r == 0)cout << qwq[0] - 1 << '\n';
        else if(r == m)cout << n - qwq[m - 1] << '\n';
        else cout << ((qwq[r] - qwq[r - 1]) >> 1) << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}