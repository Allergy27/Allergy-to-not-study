/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1776.cpp
 *@data      2023/11/26 13:55:50
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, v, i, j, num, cnt = 0, a, b;
    cin >> n >> v;
    vector<int>qwq(1000005, 0);
    vector<int>qwqV(1000005, 0);
    vector<int>qwqW(1000005, 0);
    //输入物品及价值(二进制优化)
    for(i = 1;i <= n;++i) {
        cin >> a >> b >> num;
        for(j = 1;j <= num;j <<= 1) {
            qwqV[++cnt] = j * a;
            qwqW[cnt] = j * b;
            num -= j;
        }
        if(num)qwqV[++cnt] = a * num, qwqW[cnt] = b * num;
    }
    //动态规划
    for(i = 1;i <= cnt;++i)
        for(j = v;j >= qwqW[i];--j) //保证了一定不越界
             qwq[j] = max(qwq[j], qwq[j - qwqW[i]] + qwqV[i]); //要么取，要么不取，不考虑空间用完
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