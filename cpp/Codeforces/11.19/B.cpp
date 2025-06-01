/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Cpp
 *@data      2023/11/19/23:10:50
 */
#include<bits/stdc++.h> //万能库写好了
#define ll long long
//以及ll代替long long节约打字数
#pragma GCC optimize(2)
using namespace std; //命名空间也是

void solve() { //解题部分
    ll n, m = 0, i, j;
    cin >> n;
    vector<ll>qwq(n);
    for(auto &x : qwq)cin >> x;
    for(i = n - 2;i >= 0;--i) {
        if(qwq[i] <= qwq[i + 1])continue;
        ll res = (qwq[i]%qwq[i+1]==0?0:1)+qwq[i]/qwq[i+1];
        m += res-1;
        qwq[i]/=res;
    }
    cout << m << '\n';

}

int main() {
    ios::sync_with_stdio(false);//打消cin和cout的缓存，一般没有影响
    int t = 1; //如果有多个样例就把下面那个取消了
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}