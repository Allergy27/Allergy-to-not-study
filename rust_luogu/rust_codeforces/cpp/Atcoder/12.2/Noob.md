# ⭐Daiwa Securities Co. Ltd. Programming Contest 2023（AtCoder Beginner Contest 331）
---  
**前言:**  
前两题都是签到题，不知道为什么这次做了很久，**状态每况愈下了**
第三题也不复杂，不清楚为什么一直到最后才写出来
第四题也有偏暴力的做法，不知道为什么当时没写出来
*状态好差，睡眠不足的原因嘛*
只做出四道,只能分享一下这四道的代码了
>模拟只会猜题意，贪心只能过样例；数学上来先打表，DP一般看规律；组合数学靠运气，计算几何瞎暴力；图论强行套模板，数论只会GCD；递推莫名UKE，递归堆栈往外溢；深搜茫然TLE，广搜队列MLE；二分查找总CE，叉堆结果必RE；高精算法找规律，做完全都OLE；数据结构干瞪眼，水题也都WA;长知识也不容易，考试一来全懵Ｂ！
## 目录：
---
*点击题目跳转*
1. [题目A](#第一题)：签到题,嵌套判断
2. [题目B](#第二题)：签到题,百钱买百鸡变式
3. [题目C](#第三题)：哈希表预处理+前缀和
4. *题目D：一道二维前缀和的题，没写过板子也不会用，只能说是下次一定了*
5. [题目E](#第五题)：建表,再暴搜

### 第一题
[A](#目录)
---
- **题目分析**：
嵌套判断即可
- **代码实现**：
```C++
void solve() {
    ll n, y, m, d, D, M, j;
    cin >> M >> D;
    cin >> y >> m >> d;
    if(++d > D) {
        d = 1;
        if(++m > M) {
            m = 1;
            ++y;
        }
    }
    cout << y << ' ' << m << ' ' << d;
}
```
### 第二题
[B](#目录)
---
- **题目分析**：
签到题,百钱买百鸡变式，没有太需要注意的点(开long long都不需要)
- **代码实现**：
```C++
void solve() {
    int n, m, i, j, s, l;
    cin >> n >> s >> m >> l;
    int sum = n * (s + m + l);// 先随便给个较大值
    for(int S = 0;S < n / 6 + 2;++S) //小鸡
        for(int M = 0;M < n / 8 + 2;++M) //中鸡
            for(int L = 0;L < n / 12 + 2;++L) //大鸡
                if(S * 6 + M * 8 + L * 12 >= n && S * s + M * m + L * l < sum)
                    sum = S * s + M * m + L * l; //取较小值
    cout << sum;
}
```

### 第三题
[C](#目录)
---

> 十年OI一场空，不开long long见祖宗。
- **题目分析**：
  - 首先要知道这题**得开long long**
  - 然后是这题的**思路部分**：
    - 首先题目要求比这个数大的数的和，那我们需要找到所有比这个数大的数
    - 为了在少于`O(n)`的时间内找到,我们需要对数组**排个序**
    - 接着我们需要找这个数的位置，有多种考虑方式，如果大火课外什么都没学，那这里我们可以**尝试用二分查找**这个数的位置
    - 接着我们需要求和，为了在`O(1)`内求和我们需要用**前缀和**，所以创建一个前缀和数组
    - 最后输出即可
  - **实现时注意的点：**
    - 其实**二分是会超时的**，虽然脑测一下，时间复杂度应该是排序的`O(nlgn)`+二分查找`O(lgn)*n`次查询即：`O(nlgn)`,那么复杂度还是`O(nlgn)`，但是很可惜并不能过
    - 我们考虑更快的查询，查询里最快的就是**哈希表**了，我们建一个哈希表，接着问题完美解决 **记得开long long**
  - **哈希表是什么？**
    - 如果学过**Python**，那哈希表对你来说应该不陌生，其实就是Python中的字典，而在C++中，我们用map映射来构造哈希表（也可以手搓一个，但考虑到**冲突**，最好还是别在比赛的时候手搓吧...
    - 我们简单介绍一下哈希表，介绍完也会贴出一篇视频教程，希望大火能尽快理解
    - **简单介绍部分：**
      - 哈希表相当于吧数组下标变成了一个可自定义的值称为键，我们可以用键去访问哈希表中键对应的值
      - 举个例子，我们有一个哈希表长这样：`qwq{1:2,2:3,3:4}`
      - 那么我们访问`qwq[1]`的时候对应的值就是2
    - **视频部分：**
      - [例子](https://www.bilibili.com/video/BV1PN41167ph/)
      - [教学](https://www.bilibili.com/video/BV1Ra41177RB/)
- **代码部分**：
```C++
void solve() {
    ll n, i;
    cin >> n;
    vector<ll>qwq(n);
    for(auto &x : qwq)cin >> x;
    vector<ll>qvq(qwq); //因为最后按原数组序输出，所以复制一个
    unordered_map<int, int>ck; //哈希表检索位置
    sort(qvq.begin(), qvq.end()); //排序确定比这个数大的和是多少
    ck[qvq[0] + 1] = 0; //让第一个的位置定为0
    for(i = 1;i < n;++i) {
        if(qvq[i] + 1 != qvq[i - 1] + 1) { //如果不相同，则创建一个新的键(key)
            ck[qvq[i] + 1] = ck[qvq[i - 1] + 1];
        }
        ++ck[qvq[i] + 1]; //相同则把位置向后移
    }
    vector<ll>qaq(n); //创建一个前缀和数组
    qaq[0] = qvq[0];
    for(i = 1;i < n;++i)qaq[i] = qvq[i] + qaq[i - 1]; //初始化前缀和数组
    for(auto x : qwq)cout << qaq[n - 1] - qaq[ck[x + 1]] << ' '; //按位置输出即可
}
```

### 第五题 
[E](#目录)
---
- **题目分析**：
  - 蛮暴力的一道题，当然纯暴力是过不了的，我试过了
    - 考虑优化，我们对主菜或者配菜排个序，然后每次去匹配最大值就行了，如果匹配的菜是*难吃的*，那我们就去找下一个
    - 最后在遍历的过程中取最大值即可
  - 那然后我们考虑实现:
    - 首先排序找最大值都不算难点了，我们需要考虑的是如何判断这个搭配是符合题意的，如果用的是Python，可以直接用一个in，如果是C++20，可以用contains来判断（map的一个方法
  - 然后我发现这种输入好多行的用Rust写读输入要写好长（因为你大概率没法保证用户的输入是合法的）
- **代码实现**：
```C++
void solve() {
    int n, m, i, j, l, c, d, Max = 0;
    cin >> n >> m >> l;
    vector<int>qwq(n);
    vector<int>qaq(m);
    for(auto &x : qwq)cin >> x;
    for(auto &x : qaq)cin >> x;
    map<vector<int>, int>qvq; //记录不合理的搭配
    while(l--) {
        cin >> c >> d;
        qvq.insert(pair<vector<int>, int>({ qwq[c - 1], qaq[d - 1] }, 1)); //装个表
    }
    sort(qaq.begin(), qaq.end());
    for(i = 0;i < n;++i) {
        for(j = m - 1;j >= 0;--j) {
            if(!qvq.contains({ qwq[i], qaq[j] })) {
                Max = max(qwq[i] + qaq[j], Max);
                break; //后面的配菜都会更便宜，没必要找了
            }
        }
    }
    cout << Max;
}
```
<details>
  <summary>我的Rust学得还比较浅，各种迭代器的语法不熟练，所以语法上写得会比较像C，感兴趣可以展开看一眼</summary>

```Rust
fn solve() {
    //以下是读取输入，不用知道在干嘛，只要知道读取了输入就行
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.trim().split_whitespace();
    let (n, m, l): (usize, usize, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let a: Vec<i128> = input //读取数组
        .trim() //去掉首尾空格
        .split_whitespace()
        .map(|s: &str| s.parse().unwrap()) //转整型
        .collect();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut b: Vec<i128> = input //同上，读取数组
        .trim()
        .split_whitespace()
        .map(|s: &str| s.parse().unwrap()) //转整型
        .collect();
    let mut qwq = HashMap::new(); //创建一个哈希表
    for _ in 0..l {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut input = input.trim().split_whitespace();
        let (c, d): (usize, usize) = (
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
        );
        qwq.insert((a[c - 1], b[d - 1]), 1);
    }

    //好，我们在上面读取完了输入，接下来开始操作
    b.sort_unstable(); //排个序
    let mut max_cost = 0;
    for i in 0..n {
        for j in (0..m).rev() {
            let qvq = qwq.get(&(a[i], b[j]));
            match qvq {
                Some(_qvq) => continue, //在集合中的话找下一个
                None => {
                    max_cost = std::cmp::max(a[i] + b[j], max_cost);
                    break;
                }
            }
        }
    }
    println!("{}", max_cost);
}
```
</details>