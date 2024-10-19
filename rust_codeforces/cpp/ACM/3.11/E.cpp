/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.11\E.cpp
 *@date      2024/03/11 19:20:51
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N, n, v, i, j, num, cnt = 0, a, b,ans=0;
    cin >> N;
    vector<int>qaq(N);
    for(auto &x : qaq)cin >> x;
    vector<int>qwq(10005, 0);
    vector<int>qwqV(10005, 0);
    vector<int>qwqW(10005, 0);
    //输入物品及价值(二进制优化)
    for(i = 1;i <= 2;++i) {
        cin >> a >> b >> num;
        for(j = 1;j <= num;j <<= 1) {
            qwqV[++cnt] = j * a;
            qwqW[cnt] = j * b;
            num -= j;
        }
        if(num)qwqV[++cnt] = a * num, qwqW[cnt] = b * num;
    }
    //动态规划
    for(auto x : qaq) {
        for(i = 1;i <= cnt;++i)
            for(j = x+10;j >= qwqW[i];--j) //保证了一定不越界
                qwq[j] = max(qwq[j], qwq[j - qwqW[i]] + qwqV[i]); //要么取，要么不取，不考虑空间用完
        ans += qwq[x];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}