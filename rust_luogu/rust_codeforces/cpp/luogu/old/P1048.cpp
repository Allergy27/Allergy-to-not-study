/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1048.cpp
 *@data      2023/11/26 13:41:51
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, v, i, j;
    cin >> v >> n;
    vector<int>qwq(v + 1, 0);
    vector<int>qwqV(n + 1, 0);
    vector<int>qwqW(n + 1, 0);
    //输入物品及价值
    for(i = 1;i <= n;++i)cin >> qwqW[i] >> qwqV[i];
    //动态规划
    for(i = 1;i <= n;++i)
        for(j = v;j >=qwqW[i];--j)
            qwq[j] = max(qwq[j], qwq[j - qwqW[i]] + qwqV[i]);
    cout << qwq[v] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}