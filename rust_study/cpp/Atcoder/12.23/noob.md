# ⭐AtCoder Beginner Contest 334
---
**前言:**
[比赛题目链接](https://atcoder.jp/contests/abc334/tasks "比赛题目链接")
*--按照惯例只写了主要部分的代码--*
*特别说明：Rust有一个竞赛用的输入库，并且写ABC是可以用的，但是平时写洛谷是用不了的，所以我自己写了一个cin(),凑活能用，代码见下：*

<details>
<summary>读输入函数</summary>

```Rust
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
```
</details>

明明 2、3 都是简单题却过不了，果然是因为做了一天题导致晚上状态下滑了嘛
> 模拟只会猜题意，贪心只能过样例；数学上来先打表，DP一般看规律；组合数学靠运气，计算几何瞎暴力；图论强行套模板，数论只会GCD；递推莫名UKE，递归堆栈往外溢；深搜茫然TLE，广搜队列MLE；二分查找总CE，叉堆结果必RE；高精算法找规律，做完全都OLE；数据结构干瞪眼，水题也都WA;长知识也不容易，考试一来全懵Ｂ！
## 目录：
---
*点击题目跳转*
1. [**题目A**](#第一题)：签到题
2. [**题目B**](#第二题)：数学植树问题
3. [**题目C**](#第三题)：类似滑动窗口
3. [**题目D**](#第四题)：前缀和+二分查找

### 第一题
[A](#目录)
---
**题目分析**：

签到题，输出大的就行，题目还说明了不会有相等的情况

**代码实现**：

<details>
<summary>C++代码</summary>

```C++
void solve() {
    int b, g;
    cin >> b >> g;
    cout << (b > g ? "Bat" : "Glove");
}
```

</details>

<details>
<summary>Rust代码</summary>

```
fn solve() {
    let (a, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<i32>().unwrap()));
    println!("{}", if a > b { "Bat" } else { "Glove" });
}
```
</details>

### 第二题
[B](#目录)
---
**题目分析**：

数学题，我们分别计算出 r 到 a 有多少点以及 l 到 a 有多少点。我们希望左区间减一后向下取整，右区间向下取整，接着作差得到答案
  - Rust代码中，我们使用`div_euclid()`实现向下取整。`div_euclid()` 是执行欧几里得除法，即找到$Self=q*rhs+r$中的 q ，实现向下取整（默认的除法是省略小数部分，并非向下取整）

**代码实现**：


<details>
<summary>C++代码</summary>

```C++
void solve() {
    long double a,m,l,r;
    cin >> a >> m >> l >> r;
    ll ans = floor((r - a) / m) - floor((l - 1 - a) / m);
    cout << ans;
}
```
</details>

<details>
<summary>Rust代码</summary>

```Rust
fn solve() {
    let (a, b, c, d) = cin().split_whitespace().fold((0, 0, 0, 0), |x, y| {
        (x.1, x.2, x.3, y.parse::<i128>().unwrap()) //读输入
    });
    println!("{}", (d - a).div_euclid(b) - (c - 1 - a).div_euclid(b));
}
```
</details>

### 第三题
[C](#目录)
---
- **题目分析**：
理解题意，题目中的袜子按递增顺序给出，而我们都知道差值最小的方案就是两个颜色最接近的，而对于任意两个袜子之间的最大值，我们按如下方式考虑：
![](https://gitee.com/deer-b/picture/raw/master/img/20231224135923.png)
- **代码部分**：
```C++

```
### 第四题
[D](#目录)
---
- **题目分析**：
签到题，按题意模拟即可
- **代码部分**：
```C++

```