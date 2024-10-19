#include<bits/stdc++.h> //万能库写好了
#define ll long long
//以及ll代替long long节约打字数

using namespace std; //命名空间也是

void solve() { //解题部分
    ll n, m, i, j, ans = 0, Min = 1e9+7, sum = 0;
    cin>>n;
    vector<ll>qwq(n);
    for(auto &x:qwq) {
        cin>>x;
        if(x<=0)ans = (ans+1)%2; //记录非正数奇偶
        x = abs(x);
        sum += x; //总和
        Min = min(Min, x);
    }
    if(ans%2!=0)sum -= Min*2;
    cout<<sum<<'\n';

}

int main() {
    int t = 1; //如果有多个样例就把下面那个取消了

    cin>>t;
    while(t--)solve();
    getchar();getchar();
    return 0;
}
