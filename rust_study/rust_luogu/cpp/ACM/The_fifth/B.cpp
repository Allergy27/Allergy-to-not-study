#include<bits/stdc++.h>//万能库写好了
#define ll long long
//以及ll代替long long

using namespace std;//命名空间也是

void solve() {//解题部分
    int n, m, i, j;
    cin>>n;
    vector<int>qwq(n);
    for(auto &x:qwq)cin>>x;
    if(qwq[0]!=n) {
        cout<<"NO\n";
        return;
    }
    vector<int>qaq;
    for(i = n-1;i>=0;--i)
        while(qaq.size()<qwq[i])qaq.emplace_back(i+1);//根据性质求
    for(i = 0;i<n;++i) {
        if(qwq[i]!=qaq[i]) {
            cout<<"NO\n";
            return;//原本需要用一个哨兵实现的，但是这里是函数实现，可以直接结束
        }
    }
    cout<<"YES\n";
}

int main() {
    int t = 1;//如果有多个样例就把下面那个取消了

    cin>>t;
    while(t--)solve();
    getchar();getchar();
    return 0;
}