#include<bits/stdc++.h>//万能库写好了
#define ll long long
//以及ll代替long long

using namespace std;//命名空间也是

void solve() {//解题部分
    int a, b;
    cin>>a>>b;
    cout<<(a|b);
}
int main() {
    int t = 1;//如果有多个样例就把下面那个取消了

    //cin>>t;
    while(t--)solve();
    getchar();getchar();
    return 0;
}