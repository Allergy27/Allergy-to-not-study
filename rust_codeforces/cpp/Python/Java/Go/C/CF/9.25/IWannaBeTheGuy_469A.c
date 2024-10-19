#include <stdio.h>

int n,p,q;

int main(){
    scanf("%d",&n);
    int allLevel[n+1];for(int i=1;i<=n;++i)allLevel[i]=0;
    scanf("%d",&p);
    for(int _=0;_<p;++_){
        scanf("%d",&q);
        allLevel[q]=1;
    }
    
    scanf("%d",&q);
    for(int _=0;_<q;++_){
        scanf("%d",&p);
        allLevel[p]=1;
    }
    for(int i=1;i<=n;++i){
        if(allLevel[i]==0){
            printf("Oh, my keyboard!");
            return 0;
        }
    }
    printf("I become the guy.");
    return 0;
}