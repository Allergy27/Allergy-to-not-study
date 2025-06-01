/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\12.2\B.cpp
 *@data      2023/12/03 13:36:31
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n;
    vector<int>qwq(n * 2);
    vector<int>qvq(n);
    for(auto &x : qwq)cin >> x;
    qvq[0] = qwq[0];
    for(i = 1;i < n;++i)qvq[i] = max(qvq[i - 1], qwq[i]);
    if(qwq[n] > qvq[n - 1]) {
        for(i = 0;i < n;++i)cout << qwq[i] << ' ';
        cout << '\n';
        for(i = n;i < 2 * n;++i)cout << qwq[i] << ' ';
        return;
    }
    else {
        int t = n;
        while(--t > 0) {
            if(qwq[t] > qvq[t - 1] && qwq[t + n] >= qwq[t]) {
                for(i = 0;i < t;++i)cout << qwq[i] << ' ';
                for(i = t + n;i < 2 * n;++i)cout << qwq[i] << ' ';
                cout << '\n';
                for(i = t;i < t + n;++i)cout << qwq[i] << ' ';
                return;
            }
        }
        cout << -1;
        return;
    }

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}