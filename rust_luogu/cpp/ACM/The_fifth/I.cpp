/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Cpp
 *@data      2023/11/19/13:59:58
 */
#include<bits/stdc++.h> //万能库写好了
#define ll long long
//以及ll代替long long节约打字数

using namespace std; //命名空间也是

void solve() { //解题部分
    ll n, k, i, j;
    cin>>n>>k;
    vector<ll>qwq(n);
    ll left = 0, right = 0;
    for(auto &x:qwq) {//传入数据同时找右边界
        cin>>x;
        if(x>right)right = x;
    }
    right++;
    while(left<right) {//二分答案
        ll mid = (left+right+1)>>1;
        ll sum = 0;
        for(auto &x:qwq)sum += min(x, mid);
        if(sum>=k)right = mid-1;
        else left = mid;
    }
    ll sum = 0;
    for(auto &x:qwq) {//模拟一下吃的过程
        sum += min(x, left);
        x -= min(x, left);
    }
    ll res = k-sum;//还要吃的数量
    for(i = 0;i<n&&res;++i) {
        if(qwq[i]) {
            --qwq[i];
            --res;
        }
    }
    for(auto &x:qwq)cout<<x<<" ";

}

int main() {
    ios::sync_with_stdio(false);//打消cin和cout的缓存，一般没有影响
    int t = 1; //如果有多个样例就把下面那个取消了
    //cin>>t;
    while(t--)solve();
    cin>>t;
    return 0;
}