# 归并排序的算法实现
---
## 目录：  
1. [**代码分析**](#代码分析)
2. [**递归代码**](#递归代码)
3. [**合并代码**](#合并代码)
4. [**代码实现**](#代码实现)
5. [**算法分析**](#算法分析)
---
### 代码分析
[~返回目录~](#目录)
首先理解归并排序的思想  
归并排序主要步骤如下:  
- 将原先无序的的序列分解成若干个($log$<sub>2</sub>$(n)$)有序的子序列  
- 对于每个子序列都是有序序列  
- 接着开始回升，回升的过程中合并相邻子序列  
- 合并结束时序列已经有序
---
### 递归代码
[~返回目录~](#目录)
我们每次将序列分为两份，每次分为左半边和右半边，需要注意的是：  
- 这个过程中要保证左右半边都能取到，不能遗漏数据  
- 当左侧索引大于等于右侧索引时递归结束开始回升  
- 需要一个中间变量用于区别左半边和右半边  
**代码如下**
```C++
void MERGE_SORT(vector<int> &list,int p,int r){
    if(p>=r)return;
    int q=(p+r)/2;
    MERGE_SORT(list,p,q);
    MERGE_SORT(list,q+1,r);//因为上面取到q为止，所以这里从q+1开始取
    MERGE(list,p,q,r);//这部分是回升的代码，可以直接写，但是下面要讲的，先占位
}
```
---
### 合并代码
[~返回目录~](#目录)
- 这部分我们想象成有两个序列和一个主序列，两个序列分别是已经触底之后回升的有序左序列和有序右序列，我们用三个指针分别指向主序列、左序列、右序列。移动左右序列的指针进行比较大小，不断向主序列传入值，使其有序。
- 代码部分:
```C++
void MERGE(vector<int> &list,int p,int q,int r){
    vector<int> L,R;
    int a=0,b=0;//两个指针，记录左右各自取到哪里了。
    for(int x=p;x<=q;++x)L.emplace_back(list[x]);
    for(int x=q+1;x<=r;++x)R.emplace_back(list[x]);
    for(int k=p;k<=r;++k){
        if(a==q+1-p) list[k]=R[b++];//如果L取完了，那就只取R了
        else if(b==r-q) list[k]=L[a++];//如果R取完了，那就只取L了
        else if(L[a]<R[b]) list[k]=L[a++];//取小的那一个放
        else list[k]=R[b++];
    }
}
```
---
### 代码实现
[~返回目录~](#目录)
```c++
#include<bits/stdc++.h>

using namespace std;

void MERGE_SORT(vector<int>&,int,int);

int main(){
    int n;
    cout<<"Please enter the lenth of the list:";
    cin>>n;
    vector<int> qwq(n);
    for(auto& x:qwq)cin>>x;
    MERGE_SORT(qwq,0,n-1);
    for(auto& x:qwq)cout<<x<<" ";
    getchar();getchar();
    return 0;
}

void MERGE_SORT(vector<int>& list,int p,int r){
    int q=(p+r)/2;//二分
    if(p>=r)return;//当左大于右的时候退出
    MERGE_SORT(list,p,q);//分裂左边
    MERGE_SORT(list,q+1,r);//分裂右边
    //下面是合并函数，干脆写在一起了。
    vector<int>L,R;//记录左右子树？可以这么理解罢。
    int a=0,b=0;//两个指针，记录左右各自取到哪里了。
    for(int x=p;x<=q;++x)L.emplace_back(list[x]);
    for(int x=q+1;x<=r;++x)R.emplace_back(list[x]);
    for(int k=p;k<=r;++k){
        if(a==q+1-p) list[k]=R[b++];//如果L取完了，那就只取R了
        else if(b==r-q) list[k]=L[a++];//如果R取完了，那就只取L了
        else if(L[a]<R[b]) list[k]=L[a++];//取小的那一个放
        else list[k]=R[b++];
    }
}
```
### 算法分析
[~返回目录~](#目录)
时间复杂度：$\theta(n\lg n)$  
空间复杂度：$O(n)$  