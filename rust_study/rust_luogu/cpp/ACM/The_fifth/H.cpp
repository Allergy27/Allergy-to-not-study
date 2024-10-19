/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Cpp
 *@data      2023/11/19/13:48:26
 */
#include<bits/stdc++.h> //万能库写好了
#define ll long long
//以及ll代替long long节约打字数

using namespace std; //命名空间也是

void solve() { //解题部分
    int n, m, k;
    cin>>n>>k;
    vector<int>qwq(k);
    for(auto &x:qwq)cin>>x;
    int dp[10010] = { 0 };
    for(int i = 0;i<=n;++i)
        for(int j = 0;j<k;++j)
            if(i>=qwq[j])dp[i] = max(dp[i], i-dp[i-qwq[j]]);
    cout<<dp[n]<<'\n';
}

int main() {
    ios::sync_with_stdio(false);//打消cin和cout的缓存，一般没有影响
    int t = 1; //如果有多个样例就把下面那个取消了
    //cin>>t;
    while(t--)solve();
    cin>>t;
    return 0;
}