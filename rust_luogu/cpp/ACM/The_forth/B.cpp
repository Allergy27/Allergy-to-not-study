#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j;
    cin>>n;
    while(n--){
        cin>>m;
        vector<int>qwq(m);
        int Min=0,Max=0,ans=0;
        cin>>qwq[0];
        for(int x=1;x<m;++x){
            cin>>qwq[x];
            if(qwq[x]>qwq[Max])Max=x;
            if(qwq[x]<qwq[Min])Min=x;
            if(qwq[x-1]-qwq[x]>ans)ans=qwq[x-1]-qwq[x];
        }
        ans=max(ans,max(qwq[Max]-qwq[0],qwq[m-1]-qwq[Min]));
        cout<<ans<<endl;
    }
    getchar();getchar();
    return 0;
}