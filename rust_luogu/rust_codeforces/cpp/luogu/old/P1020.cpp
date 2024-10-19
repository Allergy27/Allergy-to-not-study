#include<bits/stdc++.h>

using namespace std;

int Bisect(vector<int>,int);

int main(){
    int n,ans=0,i,j,top=1;vector<int> nums,stack;
    cin>>n;
    nums.emplace_back(n);
    stack.emplace_back(n);
    while(cin>>n){
        if(n<=nums[0])nums.insert(nums.begin(),n);
        else nums[Bisect(nums,n)-1]=n;
        if(n>stack[stack.size()-1])stack.emplace_back(n);
        else stack[Bisect(stack,n)]=n;
        
        //下面是判断退出的
        char ch=getchar();
        if(ch=='\n')break;
    }
    cout<<nums.size()<<'\n';
    cout<<stack.size();
    getchar();getchar();
    return 0;
}
int Bisect(vector<int> list,int num){//写好备用的二分
    int i=0,j=list.size();
    while(i<j){
        int mid=(i+j)>>1;
        if(list[mid]>=num)j=mid;
        else i=mid+1;
    }
    return i;
}