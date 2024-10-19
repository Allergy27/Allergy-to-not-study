# ⭐TOYOTA SYSTEMS Programming Contest 2023(AtCoder Beginner Contest 330)
---  
**前言:**  
好的,比赛的时候纠结于第三题,完全没注意到第四题也是一道相当暴力的降智题
只做出四道,那就只分享一下这四道的代码了
>模拟只会猜题意，贪心只能过样例；数学上来先打表，DP一般看规律；组合数学靠运气，计算几何瞎暴力；图论强行套模板，数论只会GCD；递推莫名UKE，递归堆栈往外溢；深搜茫然TLE，广搜队列MLE；二分查找总CE，叉堆结果必RE；高精算法找规律，做完全都OLE；数据结构干瞪眼，水题也都WA;长知识也不容易，考试一来全懵Ｂ！
## 目录：
---
*点击题目跳转*
1. [**题目A**](#第一题)：签到题,枚举
2. [**题目B**](#第二题)：签到题,判断
3. [**题目C**](#第三题)：暴力枚举
4. [**题目D**](#第四题)：建表,再暴搜

### 第一题
[A - A](#目录)
---
- **题目分析**：
遍历比较即可
- **代码实现**：
```C++
void solve() {
    int n, l, i=0, j;
    cin >> n >> l;
    vector<int>qwq(n);
    for(auto &x : qwq) {
        cin >> x;
        if(x >= l)++i;
    }
    cout << i;
}
```
### 第二题
[B - B](#目录)
---
- **题目分析**：
签到题,判断即可
- **代码实现**：
```C++
void solve() {
    int n, l, r, m, i, j;
    cin >> n >> l >> r;
    vector<int>qwq(n);
    for(auto &x : qwq) {
        cin >> x;
        if(x <= l)cout << l << ' '; //在左侧
        else if(x <= r)cout << x << ' '; //在区间内
        else cout << r << ' '; //在右侧
    }
}
```

### 第三题
[C - C](#目录)
---
- **题目分析**：
  - 先让a变成 $\sqrt{D}$，然后枚举b即可，要是超时了我们考虑a < b的时候结束循环（虽然条件给得很宽没必要
  - 然后还有就是 **记得开long long**
  - 枚举b要分两种情况，1.$n<a*a+b*b$ 2. $n>a*a+b*b$
  - 时间复杂度大概是$\theta(\sqrt{D})$,$D$给得挺小的，所以能过 **(记得开long long)**
> 十年OI一场空，不开long long见祖宗。
- **代码部分**：
```C++
void solve() {
    ll n;
    cin >> n;
    ll a = (ll) sqrt(n) + 1, b = 0;
    ll ans = abs(n - a * a - b * b);
    for(ll i = 0;i < (ll) sqrt(n);++i) {
        a -= a > 1 ? 1 : 0;
        b = (ll) sqrt(n - a * a);
        if(abs(n - a * a - b * b) < ans)ans = abs(n - a * a - b * b);
        if(abs(n - a * a - (b + 1) * (b + 1)) < ans)ans = abs(n - a * a - (b + 1) * (b + 1));
    }
    cout << ans;
}
```

### 第四题 
[D - D](#目录)
---
- **题目分析**：
我们求出各行各列的`o`个数，接着暴力搜索就行，如果搜到了`o`，那就直接拿 **行数-1**（因为要去掉自己）* **列数-1** (这里的行数列数指的是该行有多少`o`)
- **代码实现**：
```C++
//全局变量
char qwq[2002][2002];
int rows[2002], ranks[2002];
ll Sum = 0;

void solve() {
    int n, m, i, j;
    cin >> n;
    for(i = 0;i < n;++i) {
        cin >> qwq[i];
        for(j = 0;j < n;++j)if(qwq[i][j] == 'o')++rows[i];
    }
    for(i = 0;i < n;++i) 
        for(j = 0;j < n;++j)if(qwq[j][i] == 'o')++ranks[i];
    for(i = 0;i < n;++i)
        for(j = 0;j < n;++j)
            if(qwq[i][j] == 'o')if(rows[i] > 0 && ranks[j] > 0)Sum += (rows[i] - 1) * (ranks[j] - 1);
    cout << Sum;
}
```