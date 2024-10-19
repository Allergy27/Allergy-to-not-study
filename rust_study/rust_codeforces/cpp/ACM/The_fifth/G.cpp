/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Cpp
 *@data      2023/11/19/12:41:39
 */
#include<bits/stdc++.h> //万能库写好了
#define ll long long
//以及ll代替long long节约打字数

using namespace std; //命名空间也是

void solve() { //解题部分
    int n, m, i, j;
    cin>>n;
    vector<ll>qwq;
    for(i = 0;i<n;++i) {
        ll x;
        cin>>x;
        if(i&&x<qwq.back())qwq.emplace_back(1);
        qwq.emplace_back(x);
    }
    cout<<qwq.size()<<"\n";
    for(auto &x:qwq)cout<<x<<" ";
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(0);//打消cin和cout的缓存，一般没有影响
    int t = 1; //如果有多个样例就把下面那个取消了
    cin>>t;
    while(t--)solve();
    getchar();getchar()
        return 0;
}