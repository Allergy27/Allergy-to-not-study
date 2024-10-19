#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j;
    cin>>n;
    vector<int>qwq(n);
    for(auto& x:qwq)cin>>x;
    //下面这里就是插入排序的内容了，因为比较简单所以可以不单独写函数（大概
    for(i=1;i<n;++i)
        for(j=i;j>=1;--j){
            if(qwq[j]>qwq[j-1])break;
            m=qwq[j];
            qwq[j]=qwq[j-1];
            qwq[j-1]=m;
        }
    for(auto& x:qwq)cout<<x<<" ";
    getchar();getchar();
    return 0;
}