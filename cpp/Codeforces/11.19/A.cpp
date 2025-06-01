/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Cpp
 *@data      2023/11/19/22:40:04
 */
#include<bits/stdc++.h> //万能库写好了
#define ll long long
//以及ll代替long long节约打字数

using namespace std; //命名空间也是

void solve(){ //解题部分
    int n,m,i,j,ans=0;
    cin>>n>>m;
    char qwq[103];
    for(i=0;i<n;++i){
        cin>>qwq[i];
        if(qwq[i]=='B')++ans;
    }
    if(ans==m){
        cout<<0<<"\n";
        return;
    }
    cout<<1<<"\n";
    for(i=0;i<n&&ans<m;++i)if(qwq[i]=='A')++ans;
    if(i){
        cout<<i<<" B\n";
        return;
    }
    else for(i=0;i<n&&ans>m;++i)if(qwq[i]=='B')--ans;
    cout<<i<<" A\n";

    
}

int main(){ 
    ios::sync_with_stdio(false);//打消cin和cout的缓存，一般没有影响
    int t=1; //如果有多个样例就把下面那个取消了
    cin>>t;
    while(t--)solve();
    cin>>t;
    return 0;
}