# ⭐CCUT2023训练赛大一第五场
---  
**前言:**  

**难度很大**,很不好写,大概涉及了：数学、模拟、BFS、找规律、dp、二分答案
很奇怪，比上周**难度高**了不只一点，有一种**知识的美**

## 目录：
---
1. [**题目A**](#第一题)：降智签到题
2. [**题目B**](#第二题)：暴力超时题
3. [**题目C**](#第三题)：降智签到题
4. [**题目D**](#第四题)：BFS
5. [**题目E**](#第五题)：数学题
6. [**题目F**](#第六题)：找规律题
7. [**题目G**](#第七题)：找规律题
8. [**题目H**](#第八题)：博弈论+dp题
9. [**题目I**](#第九题)：二分答案题

### 第一题
[A - A](#目录)
---
- **题目分析**：
1 2 4刚好能让和和0-7一一对应，想到转二进制有1得1即按位或，降智签到题
~相应图解:~
![img1](https://gitee.com/deer-b/picture/raw/master/img/image-1.png)
我们在脑子里将其转为2进制表示(这个是6👆)
![img2](https://gitee.com/deer-b/picture/raw/master/img/image-2.png)
这个是5👆
那么对每一位都进行或运算，就得到1 1 1,即7👇
![img3](https://gitee.com/deer-b/picture/raw/master/img/image-3.png)
这也就是C/C++中按位或实际操作的形式
- **代码实现**：
~(拿第一题说明一下，就是除了第一个以外,接下来的代码只给出解题的函数solve()，主函数部分知道要有就行)~
```C++
#include<bits/stdc++.h>//这是个模板,万能库写好了
#define ll long long
//以及ll代替long long

using namespace std;//命名空间也是

void solve(){//解题部分
    int a,b;
    cin>>a>>b;
    cout<<(a|b);//按位或
}
int main(){ 
    int t=1;//如果有多个样例就把下面那个注释取消了
    //cin>>t;
    while(t--)solve();
    getchar();getchar();
    return 0;
}
```
### 第二题
[B - B](#目录)
---
- **题目分析**：
可以按上周那道铺方格的题一样，但是会超时,需要转换思路
  - 对称的图形会有特殊性质
  - 所以观察后发现:
    - 我们创建一个新的数组，遍历旧数组最后一位和第一位
    - 后面位的长度其实就是新数组当前应该有的长度,不够的话我们反复添加前面位的数字直到长度相等(比较容易验证对对称的图形这个新数组和旧的数组相等)
  - 另外，不难发现如果首位不等于数组长度一定不对称
- 这样，算法的时间复杂度为$\theta(n)$，对题目的数据来说，这样一定是不会超时的
~相应图解:~
![](https://gitee.com/deer-b/picture/raw/master/img/image-4.png)
观察发现最后一位的长度就是第一位的宽度，所以如果新数组长度不够我们扩充一个前面位也就是5👆
![](https://gitee.com/deer-b/picture/raw/master/img/image.png)
假设不对称那么就是如图所示👆
应该足够直观了吧qwq
- **代码实现**：
```C++
void solve(){//解题部分
    int n,m,i,j;
    cin>>n;
    vector<int>qwq(n);
    for(auto &x:qwq)cin>>x;
    if(qwq[0]!=n){
        cout<<"NO\n";
        return;
    }
    vector<int>qaq;
    for(i=n-1;i>=0;--i)
        while(qaq.size()<qwq[i])
            qaq.emplace_back(i+1);//根据性质求对称
    for(i=0;i<n;++i){
        if(qwq[i]!=qaq[i]){
            cout<<"NO\n";
            return;//原本需要用一个哨兵实现的，但是这里是函数实现，可以直接结束
        }
    }
    cout<<"YES\n";
}
```

### 第三题
[C - C](#目录)
---
- **题目分析**：
作两步判断：1.要不要过墙 2.能不能拿到锤子
不用过墙直接输出绝对值，拿不到锤子直接-1，能拿到输出差绝对值加到锤子距离绝对值
~相应图解:~
![](https://gitee.com/deer-b/picture/raw/master/img/image-5.png)
按说这道降智签到题不用图解，已经很直观了,但我还是画了，欸嘿qwq
- **代码部分**：
```C++
void solve(){//解题部分
    int x,y,z;
    cin>>x>>y>>z;
    if(abs(x)<abs(y)&&x*y>0||x*y<0){//如果墙没堵住，就不用想锤子的事了，直接给出答案
        cout<<abs(x);
        return;
    }
    if(abs(y)<abs(z)&&y*z>0){//如果锤子在墙后,就不用考虑了，肯定拿不到
        cout<<-1;
        return;
    }
    cout<<abs(x-z)+abs(z);
}
```

### 第四题 
[D - D](#目录)
---
- **题目分析**：
一道还算典型的宽搜题，虽然一开始其实没想到会有宽搜的题，所以这题磕磕绊绊写了好多回
  - 我们先理解一下宽搜是什么吧，想想大火应该都没接触
  - 然后又因为大火可能都没接触过，我直接配图讲
![](https://gitee.com/deer-b/picture/raw/master/img/image-6.png)
我们假设要求A到G的最短路径，那么明眼人一眼能看出来是A-D-G，那么为什么呢，其实是你通过看的方式完成了遍历，但是计算机不能这么做，我们要实现上述过程，得转换思路：
  - 首先我们从A出发，将A入队[^队列]，接着将队列里的元素出队(在这里是A)，将与出队元素相邻的元素入队,即：
  ![](https://gitee.com/deer-b/picture/raw/master/img/image-7.png)
  - 每次将队列已经入过队的数标记一下~（用你喜欢的方式）~,最后我们把这个图遍历完~（队列为空时）~
  - 最后将从G到A的路径~（之前标记过的）~加入一个新数组，然后从后往前输出这个数组即可
- 那么宽搜做这道题的思路就很明了了，最后我们用别人的动图[^动图]来演示整个过程
![](https://gitee.com/deer-b/picture/raw/master/img/16c946b4565ec047~tplv-t2oaga2asx-jj-mark%203024%200%200%200%20q75.webp)
[^队列]: 找了个视频：https://www.bilibili.com/video/BV1pL4y1n7qY/
[^动图]: https://juejin.cn/post/6844903914035232775
- **代码实现**：
```C++
oid solve(){ //解题部分
    int n,x,y;
    cin>>n>>x>>y;
    vector<vector<int>>qwq(n+1); //下标从1开始，所以n+1
    for(int i=0;i<n-1;++i){
        int U,V;
        cin>>U>>V;
        qwq[U].emplace_back(V); //边相连
        qwq[V].emplace_back(U); //边相连
    }
    vector<int>qaq(n+1,-1); //记录是不是找过了
    queue<int> que; //队列实现BFS

    qaq[x] = 0; //从x开始找，x为0
    que.push(x); //入队

    while(!que.empty()){
        int fa=que.front(); //找父亲
        que.pop(); //出队

        for(int son:qwq[fa]){ //找儿子
            if(qaq[son]!=-1)continue; //之前找过了就找下一个
            qaq[son]=fa; //孩子和父亲连接
            que.push(son); //孩子入队
        }
    }
    int i=y; //找完了
    vector<int>ans; //存放答案
    while(qaq[i]){ //qaq[i]非空
        ans.emplace_back(i); //添加
        i=qaq[i]; //找下一个
    }
    ans.emplace_back(x); //添加开头
    for(int i=ans.size()-1;i>=0;--i)cout<<ans[i]<<' '; //输出
}
```

### 第五题 
[E - E](#目录)
---
- **题目分析**：
数学题，二阶等差数列
  - 我们考虑最差情况，每个之间差只隔了1,然后用求和公式判断xy是否符合题意
  - 不符合没什么好说的，如果符合，我们用最差情况输出，然后因为题目要求边界只能为x,y，所以边界改输出x,y就行
- 公式:S~n~=a~1~+$\frac{n^2-n}{2}$
- **代码实现**：
```C++
void solve(){ //解题部分
    int n,m,x,y,i;
    cin>>x>>y>>n;
    if(x+(n*n-n)/2>y){
        cout<<-1<<'\n';
        return;
    }
    vector<int>qwq;
    for(i=0;i<n;++i)qwq.emplace_back(y-(i*i-i)/2);
    cout<<x<<' ';
    while(--i)cout<<qwq[i]<<(i==1? '\n':' ');
}
```
### 第六题 
[F - F](#目录)
---
- **题目分析**：
找规律题~（说不定带点数学？）~
  - 首先，我们确定当有偶数个非正数的时候，一定可以让所有数都变成非负数
  - 接着，如果有奇数个非正数时，我们让绝对值最小的数变成负数，
  - 于是，最后只要全部作$|x|$,奇数减去两倍最小值，偶数直接全部求和即可
- **代码实现**：
```C++
void solve(){ //解题部分
    ll n,m,i,j,ans=0,Min=1e9+7,sum=0;
    cin>>n;
    vector<ll>qwq(n);
    for(auto &x:qwq){
        cin>>x;
        if(x<=0)ans=(ans+1)%2; //记录非正数奇偶
        x=abs(x);
        sum+=x; //总和
        Min=min(Min,x);
    }
    if(ans%2!=0)sum-=Min*2;
    cout<<sum<<'\n';
}
```
### 第七题 
[G - G](#目录)
---
- **题目分析**：
找规律,给你的数一定是小于大于等于前一个数的，那就让小于前一个数的时侯添一个1。
- **代码实现**：
```C++
void solve(){ //解题部分
    int n,m,i,j;
    cin>>n;
    vector<ll>qwq;
    for (i=0;i<n;++i){
        ll x;
        cin>>x;
        if(i&&x<qwq.back())qwq.emplace_back(1);
        qwq.emplace_back(x);
    }
    cout<<qwq.size()<<"\n";
    for(auto &x:qwq)cout<<x<<" ";
    cout<<"\n";
}
```
### 第八题 
[H - H](#目录)
---
- **题目分析**：
博弈论+dp
  - 说起来我一开始以为每个人都取最大石头数最后肯定是最大石头数，后来想起来这个考博弈论的，每次不一定是取最大最后最大，我只知道有这么个结论要我举例子还是有点为难，总之大火也就记下结论吧，说起来博弈论还挺有意思的。
  - 然后说说这题的思路，虽然直接求最优方案比较困难，但是正难则反，我们考虑倒过来求最大值，先考虑0个、1个……n个石头的最大值，也就是用dp即动态规划来做
  - 写出状态转移方程：
  $f(x)=max(f(x),i-f(x-k))$
  - 这里i代表当前石头数，k代表取几个石头的方案

- **代码实现**：
```C++
void solve(){ //解题部分
    int n,m,k;
    cin>>n>>k;
    vector<int>qwq(k);
    for(auto &x:qwq)cin>>x;
    int dp[10010]={0};
    for (int i=0;i<=n;++i)
        for (int j=0;j<k;++j)
            if(i>=qwq[j])dp[i]=max(dp[i],i-dp[i-qwq[j]]);
    cout<<dp[n]<<'\n';
}
```
### 第九题 
[I - I](#目录)
---
- **题目分析**：
因为每次跑一圈每个减1，减得太慢了，我们想办法让他快点，想到用二分答案的方法
  - 二分答案，顾名思义，要知道答案
  - 我们先把篮子想象成柱子，如图所示：
  ![](https://gitee.com/deer-b/picture/raw/master/img/image-8.png)
  - 那么吃的过程就可以想象成是切柱子，我们要让剩下的部分尽可能等于k但又不一定等于k~（稍大）~ 那接着就可以作最后一轮循环取找到最后的答案了
  - 时间复杂度应该是$\theta$($nlgn$),不算大
- **代码实现**：
```C++
void solve(){ //解题部分
    ll n,k,i,j;
    cin>>n>>k;
    vector<ll>qwq(n);
    ll left=0,right=0;
    for(auto &x:qwq){//传入数据同时找右边界
        cin>>x;
        if(x>right)right=x;
    }
    right++;
    while(left<right){//二分答案
        ll mid=(left+right+1)>>1;
        ll sum=0;
        for(auto &x:qwq)sum+=min(x,mid);
        if(sum>=k)right=mid-1;
        else left=mid;
    }
    ll sum=0;
    for(auto &x:qwq){//模拟一下吃的过程
        sum+=min(x,left);
        x-=min(x,left);
    }
    ll res=k-sum;//还要吃的数量
    for(i=0;i<n&&res;++i){
        if(qwq[i]){
            --qwq[i];
            --res;
        }
    }
    for(auto &x:qwq)cout<<x<<" ";
}
```