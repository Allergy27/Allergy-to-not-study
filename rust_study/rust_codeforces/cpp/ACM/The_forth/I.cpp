#include<bits/stdc++.h>

using namespace std;

struct qaq{
    long long sumTuple;
    long long nowIndex;
    long long sumNumber;
};


int main(){
    long long n,m,i,j,ans=0;
    cin>>n;
    vector<long>qwq(n);
    for(auto& x:qwq)cin>>x;
    qaq QWQ={0,0,0};
    vector<qaq>useful(n+1,QWQ);
    for(i=0;i<n;++i){
        if(useful[qwq[i]].sumNumber==0)useful[qwq[i]]={0,i,1};
        else{
            useful[qwq[i]].sumTuple+=(i-useful[qwq[i]].nowIndex-1)*(useful[qwq[i]].sumNumber);
            ans+=useful[qwq[i]].sumTuple;
            useful[qwq[i]].nowIndex=i;
            ++useful[qwq[i]].sumNumber;
        }   
    }
    cout<<ans<<endl;
    getchar();getchar();
    return 0;
}
/*
N=int(input())
a=list(map(int,input().split()))
b={}
ans=0
for i,num in enumerate(a):
    if num not in b:
        b[num]=[0,i,1]
    else:
        b[num][0]+=(i-b[num][1]-1)*b[num][2]
        ans+=b[num][0]
        b[num][1]=i
        b[num][2]+=1
print(ans)
*/