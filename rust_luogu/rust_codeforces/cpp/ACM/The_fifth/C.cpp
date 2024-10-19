#include<bits/stdc++.h>//万能库写好了
#define ll long long
//以及ll代替long long节约打字数

using namespace std;//命名空间也是

void solve() {//解题部分
    int x, y, z;
    cin>>x>>y>>z;
    if(abs(x)<abs(y)&&x*y>0||x*y<0) {//如果墙没堵住，就不用想锤子的事了，直接给出答案
        cout<<abs(x);
        return;
    }
    if(abs(y)<abs(z)&&y*z>0) {//如果锤子在墙后,就不用考虑了，肯定拿不到
        cout<<-1;
        return;
    }
    cout<<abs(x-z)+abs(z);
}

int main() {
    int t = 1;//如果有多个样例就把下面那个取消了

    //cin>>t;
    while(t--)solve();
    getchar();getchar();
    return 0;
}