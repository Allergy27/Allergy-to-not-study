/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1616.cpp
 *@data      2023/11/26 15:04:35
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, v, i, j;
    cin >> v >> n;
    vector<ll>qwq(v + 1, 0);
    vector<ll>qwqV(n + 1, 0);
    vector<ll>qwqW(n + 1, 0);
    //输入物品及价值
    for(i = 1;i <= n;++i)cin >> qwqW[i] >> qwqV[i];
    //动态规划
    for(i = 1;i <= n;++i)
        for(j = qwqW[i];j<=v;++j) //保证了一定不越界
            qwq[j] = max(qwq[j], qwq[j - qwqW[i]] + qwqV[i]); //要么取，要么不取，不考虑空间用完
    cout << qwq[v] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}