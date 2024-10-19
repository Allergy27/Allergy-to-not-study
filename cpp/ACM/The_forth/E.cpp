#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j;
    cin>>n;
    while(n--){
        cin>>i>>j;
        if(i==1&&j==1){
            cout<<0<<endl;
            continue;
        }
        cout<<max(i,j)+min(i,j)*2-2<<endl;
    }   
    getchar();getchar();
    return 0;
}