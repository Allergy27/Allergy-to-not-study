#include<bits/stdc++.h>
#define ll long long

using namespace std;



int main(){
    int n;ll k;
    cin>>n>>k;
    ll i=0,j=0;//为二分边界初始化
    vector<ll>qwq(n);
    for(auto &x:qwq){
        cin>>x;
        if(x>j) j=x;
    }
    while(i<j){
        ll mid=(i+j+1)>>1;
        ll sum=0;
        for(auto &x:qwq)sum+=min(x,mid);
        if(sum>k)j=mid-1;
        else i=mid;
    }
    ll sum=0;
    for(auto &x:qwq){
        sum+=min(x,i);
        x-=min(x,i);
    }

    ll qvq=k-sum;
    for(int m=0;m<n&&qvq;++m)if(qwq[m]){
        --qwq[m];
        --qvq;
    }
    for(int i=0;i<n;++i)cout<<qwq[i]<<" ";//输出
    getchar();getchar();

    return 0;
}
/*
2 1000000000000
1000000000000 999999999999
*/