/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.11\A.cpp
 *@date      2024/03/11 18:40:51
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, w, x, i, ans = 0;
    cin >> n;
    vector<int>qwq(49);
    for(i = 0;i < n;++i) {
        cin >> w >> x;
        qwq[9 + x] += w;
        qwq[18 + x] -= w;
    }
    for(i = 1;i < 49;++i)qwq[i] += qwq[i - 1];
    for(i = 0;i < 24;++i) {
        qwq[i] += qwq[24 + i];
        if(qwq[i] > ans)ans = qwq[i];
    }
    cout << ans;
}

int main() {
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}