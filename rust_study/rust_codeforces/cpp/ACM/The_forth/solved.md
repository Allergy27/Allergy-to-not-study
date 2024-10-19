# ⭐CCUT2023训练赛大一第四场
---  
**前言:**  

这次难度和题量都有一点点上来了，但是其实还是基础题，只涉及基础算法  
那先简单分析一下每道题目好了(<u>点对应题目可以跳转至对应分析,之后点题目序号返回目录</u>)：

## 目录：
---
1. [**题目A**](#第一题)：这题的话考的还是==数学知识==，属于签到题
2. [**题目B**](#第二题)：这题考的是读题，从模拟的角度下手然后==找规律==吧，能发现题目中的三种状态[^三种状态]应该就会好做很多
3. [**题目C**](#第三题)：比题目A还简单的==签到题==，应该不会有什么困难
4. [**题目D**](#第四题)：一道==模拟题==，可以先创建一个二维数组，然后开始覆盖，遍历题目中给的ABCD范围，然后每当没被覆盖就开始覆盖，并使计数器加一
5. [**题目E**](#第五题)：也是==读题==，只要理解最短路径是唯一的就很好下手了
6. [**题目F**](#第六题)：一道稍难的题，可以==模拟==去做，也可以提前判断要买多少张“一日券”，总之不是很复杂
7. [**题目G**](#第七题)：还是==读题==，需要理解什么情况下要增加堆栈，以及如何判断
8. [**题目H**](#第八题)：也许是这次最难的题，用相向双指针做了老半天过不去，只好改成用==滑动窗口==[^滑动窗口]去做
9. [**题目I**](#第九题)：==理解题意==即可，不过暴力时间会超，需要优化[^优化]

### 第一题
[A - A](#目录)
---
- **题目分析**：
我们知道：偶数加偶数得到偶数，奇数加奇数也为偶数，所以只要考虑让数组中的数都为奇数或是偶数即可。
- **代码实现**：
```C++
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j;
    cin>>n;
    while(n--){
        cin>>m;int D=0,S=0;
        //D代表Double，也就是双数的意思，而S代表Single，也就是单数
        vector<int>ans(m);
        for(auto& x:ans){//C++11新标准的for
            cin>>x;
            if(x%2==0)++D;//偶数个数增加
            else ++S;//奇数个数增加
        }
        cout<<min(D,S)<<endl;//输出较小值
    }
    return 0;
}
```
### 第二题
[B - B](#目录)
---
- **题目分析**：
就像在目录说的，这题需要理解题意，要想末尾值减去开头值最大，则要么增加最大值，要么减少最小值，而我们只能移动一次。好在虽然范围固定了，但我们能找无穷次，因此从中寻找规律：  
  1. 可以选择第二位到末尾，一直旋转下去，一定能将最大值移动到末尾。
  2. 可以选择开头到倒数第二位，一直旋转下去，一定能将最小值移动到开头
  3. 可以选择开头到结尾，一直旋转下去，一定能将相邻值移动到：开头/结尾。  

  所以只要判断这三种情况下的最大值即可。
- **代码实现**：
```C++
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j;
    cin>>n;
    while(n--){//有n组输入
        cin>>m;//读取长度
        vector<int>qwq(m);
        int Min=0,Max=0,ans=0;
        cin>>qwq[0];
        for(int x=1;x<m;++x){
            cin>>qwq[x];//读入数据
            if(qwq[x]>qwq[Max])Max=x;//同时寻找最大值的索引
            if(qwq[x]<qwq[Min])Min=x;//以及寻找最小值的索引
            if(qwq[x-1]-qwq[x]>ans)ans=qwq[x-1]-qwq[x];//第三种情况
        }
        ans=max(ans,max(qwq[Max]-qwq[0],qwq[m-1]-qwq[Min]));
        cout<<ans<<endl;
    }
    return 0;
}
```

### 第三题
[C - C](#目录)
---
- **题目分析**：
签到题，没什么好讲的，注意M>N的情况即可
- **代码部分**：
```C++
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, i, j;
    cin >> n >> m >> j;
    if (m > n)i = 0;//特殊考虑一下
    else i = (n - m) / j + 1;
    cout << i;
    return 0;
}
```

### 第四题 
[D - D](#目录)
---
- **题目分析**：
用二维数组创建整个大区域,接着根据所给定的范围遍历即可。
- **代码实现**：
```C++
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j,A,B,C,D,ans=0;
    cin>>n;
    vector<vector<int>> peper(105,vector<int>(105,0));

    for(m=0;m<n;++m){
        cin>>A>>B>>C>>D;
        for(i=A;i<B;++i)
            for(j=C;j<D;++j)
                if(!peper[i][j]){
                    ++ans;//计数器++
                    peper[i][j]=1;//标记为已覆盖
                }
    }
    cout<<ans;
    return 0;
}
```

### 第五题 
[E - E](#目录)
---
- **题目分析**：
对任何超过1x1的矩阵，我们恒有经过长边传送短边路径最短，于是可以给出方程式(假设x为长边，y为短边,z为最终结果)： $z=x+2*(y-1)$
- **代码实现**：
```C++
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j;
    cin>>n;
    while(n--){
        cin>>i>>j;
        if(i==1&&j==1){//当矩阵为1x1时单独给出答案
            cout<<0<<endl;
            continue;
        }
        cout<<max(i,j)+min(i,j)*2-2<<endl;//直接打印给定的关系
    }   
    return 0;
}
```
### 第六题 
[F - F](#目录)
---
- **题目分析**：
这道题需要判断买捆绑票便宜还是直接买当日的票便宜，我们可以这么考虑：
  - 如果要买票的话肯定是在当日价钱比较高的时候去使用，所以我们可以先对传入后的数组进行一个排序(这里我是用了自己写的归并排序，其他排序我没试过，不清楚)，来保证自己每次顶替的都是更贵的。
  - 以及考虑买几张的问题，我们有两种思路；一种是直接计算最后的值，另一种是直接暴力遍历，避免出错(因为我在使用方法一的时候出错了所以这里只介绍方法二)
- **代码实现**：
```C++
#include<bits/stdc++.h>

using namespace std;

void MERGE_SORT(vector<long long>&,long long,long long);//因为自己写了int型的情况并不对，所以直接上long long。

int main(){
    long long n,d,p,i,j,Sum=0;
    cin>>n>>d>>p;
    vector<long long>qwq(n);
    for(auto& x:qwq){
        cin>>x;
        Sum+=x;
    }
    long long ans=Sum;
    MERGE_SORT(qwq,0,n-1);//自己写的归并降序排列
    for(i=0;i<n;i+=d){
        for(j=i;j<min(n,i+d);++j)Sum-=qwq[j];
        Sum+=p;
        ans=min(Sum,ans);
    }
    cout<<ans;
    return 0;
}
void MERGE_SORT(vector<long long>& list,long long p,long long r){
    long long q=(p+r)/2;//二分
    if(p>=r)return;//当左大于右的时候退出
    MERGE_SORT(list,p,q);//分裂左边
    MERGE_SORT(list,q+1,r);//分裂右边
    //下面是合并函数，干脆写在一起了。
    vector<long long>L,R;//记录左右子树？可以这么理解罢。
    long long a=0,b=0;//两个指针，记录左右各自取到哪里了。
    for(long long x=p;x<=q;++x)L.emplace_back(list[x]);
    for(long long x=q+1;x<=r;++x)R.emplace_back(list[x]);
    for(long long k=p;k<=r;++k){
        if(a==q+1-p) list[k]=R[b++];//如果L取完了，那就只取R了
        else if(b==r-q) list[k]=L[a++];//如果R取完了，那就只取L了
        else if(L[a]>R[b]) list[k]=L[a++];//取大的那一个放
        else list[k]=R[b++];
    }
}
```
### 第七题 
[G - G](#目录)
---
- **题目分析**：
求需要的最少个堆栈数，那么考虑什么情况下要增加堆栈数：
  - 首先可以确定的是，至少会需要一个堆栈
  - 接着可以发现当这个数找不到比它大一的数的堆栈时需要新的堆栈。
- **代码实现**：
```C++
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j,ans;
    cin>>m;
    while(m--){
        cin>>n;
        ans=0;
        vector<int>qwq(n+1,0);
        for(i=0;i<n;++i){
            cin>>j;
            if(qwq[j]==0)ans++;//如果没有比他大一的堆栈则计数器++
            else qwq[j]=0;
            qwq[j-1]=1;//无论如何它本身都标记为存在，又因为数据不重复，所以没有问题
        }
        cout<<ans<<endl;
    }
    return 0;
}
```
### 第八题 
[H - H](#目录)
---
- **题目分析**：
最难绷的一题，可以用滑动窗口来解决（什么？你问什么是滑动窗口？~~这里写不合适，你直接来问我吧~~）：
  - 首先我们创建一个左至右的滑动窗口，使得里面的值恰为s。并且记录此时的窗口长度
  - 接着我们开始移动它，每当符合s时停止移动并且记录下此时的窗口长度，用此时的长度与最大长度进行比较，
  - 最后我们输出总长度-最大长度即可
- **代码实现**：
```C++
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
    return 0;
}
```
### 第九题 
[I - I](#目录)
---
- **题目分析**：
  - 这题我是用哈希表~（我的算法导论上管他叫散列表，总之都一样）~存的数据,主要是我的做法里需要存一些经常查找的数据，所以用哈希表查起来快些，又因为题目给的范围很好，N个数范围就在0~n，所以用了哈希表，另一方面原因是python自带一个哈希表叫字典，所以实现起来非常方便。
  
  好的，现在分析题目，题目要求的三元组满足左右数据相等，但三个数不能都相等，所以我们只需要在第一次遇到这个数的时候存到哈希表里，在之后遇到这个数的时候去求它和之前的数能构成多少个组合即可。
  那么明确了大致思路我们构思代码：
  - 首先，需要创建哈希表
  - 接着我们需要遍历一遍数组，遍历的同时求符合条件的组数 ~~这个过程需要抽象一个数学公式，也是写写麻烦直接找我好了~~
- **代码实现**：
```C++
#include<bits/stdc++.h>

using namespace std;

struct qaq{
    long long sumTuple;//记录前面的元组个数的和
    long long nowIndex;//记录当前最右端的索引值
    long long sumNumber;//记录和最左端之间有多少个重复的数(毕竟重复的数是不能取的)
};


int main(){
    long long n,m,i,j,ans=0;
    cin>>n;
    vector<long long>qwq(n);
    for(auto& x:qwq)cin>>x;
    qaq QWQ={0,0,0};
    vector<qaq>useful(n+1,QWQ);
    for(i=0;i<n;++i){
        if(useful[qwq[i]].sumNumber==0)useful[qwq[i]]={0,i,1};//当这个数在表中没有记录时，将其放入
        else{
            useful[qwq[i]].sumTuple+=(i-useful[qwq[i]].nowIndex-1)*(useful[qwq[i]].sumNumber);//利用抽象出的数学公式求组数
            ans+=useful[qwq[i]].sumTuple;
            useful[qwq[i]].nowIndex=i;//更新索引
            ++useful[qwq[i]].sumNumber;//更新计数器
        }   
    }
    cout<<ans<<endl;
    return 0;
}
```
[^三种状态]:分别是最大值放到末尾、最小值放到开头、相邻值放到开头结尾
[^滑动窗口]:其实也是双指针，这里贴出灵神的教程：BV1hd4y1r7Gq，如果还是不懂可以来找我问问看看，应该是不难理解的~（灵神为什么是神）~
[^优化]:这里是用了哈希表，用空间换了时间，一般来讲优化都是时间换空间，空间换时间。