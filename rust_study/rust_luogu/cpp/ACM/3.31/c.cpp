/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.31\c.cpp
 *@date      2024/03/31 18:47:21
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, f = 0, a, b;
    cin >> n >> a >> b;
    int wk = a + b, mi = a + b, mx = 0;
    vector<int>qwq(n + 1);
    for(i = 1;i <= n;++i) cin >> qwq[i];
    for(i = 2;i <= n;++i) {
        int dis = (qwq[i] - qwq[1] + 1) % wk + wk;
        mi = min(mi, dis);
        mx = max(mx, dis);
    }
    cout << (mx - mi+1 > a ? "No" : "Yes");

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}