#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int _;_<T;++_){
        int y1,n,y2;
        scanf("%d",&y1);
        scanf("%d",&n);
        int s[n];
        for(int i=0;i<n;++i)scanf("%d",&s[i]);
        scanf("%d",&y2);int k=1,r=0;
        while(1){
            if(y2==y1){
                printf("%d\n",k);
                break;  
            }
            if(y1==s[r]){
                ++y1;
                ++r;
                continue;
            }
            ++y1;++k;
        }
    }
    return 0;
}