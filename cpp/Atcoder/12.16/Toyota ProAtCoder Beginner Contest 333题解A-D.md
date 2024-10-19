# ⭐Toyota Programming Contest 2023#8（AtCoder Beginner Contest 333）
---
**前言:**
好的,比赛的时候给比赛忘了，少跑二十多分钟，好在这次题目都比较简单，也算是迅速赶上了
顺带一提，为了赶时间貌似没有一题是用C++写的……
![](https://gitee.com/deer-b/picture/raw/master/img/20231217172652.png)
>模拟只会猜题意，贪心只能过样例；数学上来先打表，DP一般看规律；组合数学靠运气，计算几何瞎暴力；图论强行套模板，数论只会GCD；递推莫名UKE，递归堆栈往外溢；深搜茫然TLE，广搜队列MLE；二分查找总CE，叉堆结果必RE；高精算法找规律，做完全都OLE；数据结构干瞪眼，水题也都WA;长知识也不容易，考试一来全懵Ｂ！
## 目录：
---
*点击题目跳转*
1. [**题目A**](#第一题)：签到题,循环
2. [**题目B**](#第二题)：签到题,标记（也可以叫染色？
3. [**题目C**](#第三题)：打表（也有别的做法，但是打表最合适
4. [**题目D**](#第四题)：建表,再暴搜
5. [**比赛时候用的代码**](#比赛时用的代码)

### 第一题
[A - A](#目录)
---
- **题目分析**：
遍历比较即可
- **代码实现**：
```C++
void solve() {
    int n,i;
    cin >> n;
    for(i=0;i<n;++i)cout << n;
}
```
### 第二题
[B - B](#目录)
---
- **题目分析**：
签到题,真正比赛的时候建议打表，见比赛代码
然后这题思路即保证后一个比前一个大（通过+5），接着相减，我们得到：
1 2 3 4
然鹅我们需要的是1 2 2 1
那么只要将大于2的都做%2+1处理即可
- **代码实现**：
```C++
void solve() {
    char s1, s2, t1, t2;
    cin >> s1 >> s2;
    cin >> t1 >> t2;
    if(s1 > s2)s2 += 5;
    if(t1 > t2)t2 += 5;
    s1 = s2 - s1 > 2 ? (s2 - s1) % 2 + 1 : s2 - s1;
    t1 = t2 - t1 > 2 ? (t2 - t1) % 2 + 1 : t2 - t1;
    if(s1 == t1)cout << "Yes";
    else cout << "No";
}
```

### 第三题
[C - C](#目录)
---
- **题目分析**：
  - 这题的确可以用数学的方式做，但是出于条件限制怎么做都不理想，题目数据限制在333个，我们直接打表
- **代码部分**：
```Python
a=[]
for i in range(1,20):
    for j in range(i,20):
        for k in range(j,20):
            a.append(int(i*'1')+int(j*'1')+int(k*'1'))
a.sort()
print(a[0:334])#接着输出即可
```

### 第四题
[D - D](#目录)
---
- **题目分析**：
  - 这题只需以1为根找到1的最大子树并用总节点数减去它即可
- **代码实现**：
```C++
int dfs(vector<vector<int>> &tree, int node, int fa) {
    int ans = 1;
    for(auto &x : tree[node]) {
        if(x != fa) {
            int k = dfs(tree, x, node);
            if(node != 1)ans += k;
            else ans = max(ans, k + 1);
        }
    }
    return ans;
}
void solve() {
    int n, m, i, j, a, b;
    cin >> n;
    vector<vector<int>>qwq(n + 1);
    for(i = 1;i < n;++i) {
        cin >> a >> b;
        qwq[a].emplace_back(b);
        qwq[b].emplace_back(a);
    }
    m = dfs(qwq, 1, 1);
    cout << n  - m+1;
}
```

# 比赛时用的代码
A.
```Python
n=int(input())
print(str(n)*n)
```
B.
```Python
A={'AB':1,
'AC':2,
'AD':2,
'AE':1,
'BA':1,
'BC':1,
'BD':2,
'BE':2,
'CA':2,
'CB':1,
'CD':1,
'CE':2,
'DA':2,
'DB':2,
'DC':1,
'DE':1,
'EA':1,
'EB':2,
'EC':2,
'ED':1,
}
a=input()
b=input()
if A[a]==A[b]:print("Yes")
else: print("No")
```
C.
```Python
a=[]#一个很长的表
print(a[int(input())-1])
```
D.
```Rust
//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1395.rs
//@data      2023/12/13 14:08:21
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut qwq: Vec<Vec<usize>> = vec![vec![]; n + 1];
    for _ in 0..n - 1 {
        //读输入
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut input = input.split_whitespace();
        //建树
        let (a, b): (usize, usize) = (
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
        );
        qwq[b].push(a);
        qwq[a].push(b);
    }
    //处理
    let x= bfs(&qwq, 1, 1);
    println!("{}",x.0-x.1);
}
fn bfs(t: &Vec<Vec<usize>>, node: usize, fa: usize) -> (usize, usize) {
    let mut ans = (1,0); //子树和,所有中最大的那个和
    for &son in t[node].iter() {
        if son != fa {
            let k = bfs(t, son, node);
            ans.0 += k.0;
            if fa == 1 {
                ans.1=ans.1.max(k.0);
            }
        }
    }
    ans
}
```