#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k,i,j;
    cin>>n>>k;
    vector<int>qwq(k);
    for(auto &x:qwq)cin>>x;
    int dp[10010]={0};
    for(i=0;i<=n;++i)
        for(j=0;j<k;j++)
            if(i>=qwq[j])dp[i]=max(dp[i],i-dp[i-qwq[j]]);
    cout<<dp[n]<<'\n';
    getchar();getchar();
    return 0;
}