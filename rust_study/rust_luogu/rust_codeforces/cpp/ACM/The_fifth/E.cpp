#include<bits/stdc++.h> //万能库写好了
#define ll long long
//以及ll代替long long节约打字数

using namespace std; //命名空间也是

void solve() { //解题部分
    int n, m, x, y, i;
    cin>>x>>y>>n;
    if(x+(n*n-n)/2>y) {
        cout<<-1<<'\n';
        return;
    }
    vector<int>qwq;
    for(i = 0;i<n;++i)qwq.emplace_back(y-(i*i-i)/2);
    cout<<x<<' ';
    while(--i)cout<<qwq[i]<<(i==1 ? '\n' : ' ');
}

int main() {
    int t = 1; //如果有多个样例就把下面那个取消了

    cin>>t;
    while(t--)solve();
    getchar();getchar();
    return 0;
}