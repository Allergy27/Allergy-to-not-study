#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j,t,s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        vector<int>a(n,0);
        int Sum=0;
        for(i=0;i<n;++i){
            cin>>a[i];
            Sum+=a[i];
        }
        if(Sum<s)cout<<-1<<endl;
        else if(Sum==s)cout<<0<<endl;
        else{//滑动窗口讨论剩下的情况
            int left=0,right=0,cS=0,ans=0;
            while (right<n){
                while (right<n && cS<=s)cS+=a[right++];//先滑到超过的时候
                if (cS==s)ans=max(ans,right-left);//再比较一下这个窗口是不是最大窗口
                if (cS==s+1)ans=max(ans,right-left-1);//边界情况
                while(left<right && cS>s)cS-=a[left++];//超过了嘛，我们回收
            }
            cout<<n-ans<<endl;
        }
    }
    //getchar();getchar();
    return 0;
}