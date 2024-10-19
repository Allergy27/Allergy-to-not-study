#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;long long k;
    cin>>n>>k;
    long long a[n];
    for(int i=0;i<n;++i)cin>>a[i];

    long long l=0,r=1e12;
    while(l<r){//二分答案
        long long mid=l+(r-l+1)/2;
        long long sum=0;
        for(int i=0;i<n;++i)sum+=min(a[i],mid);
        if(sum>=k)r=mid-1;
        else l=mid;
    }
    long long sum=0;
    for(int i=0;i<n;++i){
        sum+=min(a[i],l);
        a[i]-=min(a[i],l);
    }

    long long rem=k-sum;
    for(int i=0;i<n&&rem;++i){
        if(a[i]){a[i]--;rem--;}
    }
    
    for(int i=0;i<n;++i)cout<<a[i]<<" ";//输出

    getchar();getchar();
    return 0;
}
