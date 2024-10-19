#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j;
    cin>>n;
    while(n--){
        cin>>m;int D=0,S=0;
        vector<int>ans(m);
        for(auto& x:ans){
            cin>>x;
            if(x%2==0)++D;
            else ++S;
        }
        cout<<min(D,S)<<endl;
    }
    getchar();getchar();
    return 0;
}