#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j,A,B,C,D,ans=0;
    cin>>n;
    vector<vector<int>> peper(105,vector<int>(105,0));

    for(m=0;m<n;++m){
        cin>>A>>B>>C>>D;
        for(i=A;i<B;++i)
            for(j=C;j<D;++j)
                if(!peper[i][j]){
                    ++ans;
                    peper[i][j]=1;
                }
    }
    cout<<ans;
    getchar();getchar();
    return 0;
}