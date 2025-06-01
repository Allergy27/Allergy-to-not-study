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
    vector<int>qvq(n*2);
    qvq[0] = qwq[0];
    for(auto &x : qwq)cin >> x;
    if(qwq.size() == 2 && qwq[0] < qwq[1]) {
        cout << qwq[0] << '\n' << qwq[1];
        return;
    }
    for(i = 1;i < 2 * n;++i)qvq[i] = max(qvq[i - 1], qwq[i]);
    if(qwq[n-1] <= qvq[n - 2]||qwq[2*n-1]<qvq[2*n-1]) { cout << -1; return; };
    for(i = 0;i < n - 1;++i)cout << qwq[i] << ' ';
    cout << qwq[2 * n - 1] << '\n';
    for(i = n-1;i < 2 * n-1;++i)cout << qwq[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}