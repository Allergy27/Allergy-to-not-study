#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j,ans;
    cin>>m;
    while(m--){
        cin>>n;
        ans=0;
        vector<int>qwq(n+1,0);
        for(i=0;i<n;++i){
            cin>>j;
            if(qwq[j]==0)ans++;
            else qwq[j]=0;
            qwq[j-1]=1;
        }
        cout<<ans<<endl;
    }
    getchar();getchar();
    return 0;
}