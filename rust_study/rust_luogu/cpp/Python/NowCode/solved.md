# ⭐哈尔滨学院第十四届程序设计竞赛（低年级组）正式赛
---  
**前言:**  

手速场，全是水题，有点含金量的是D题，含金量不高，鉴于python简练，我贴出python的题解~（我在D题给了一个C/C++的解法）~


## 目录：
---
1. **题目D**
2. **其他题**


### 题目D
---
- **题目分析**：
  - 分成两部分，求前后区间和，想到用前缀和求区间的和:（蓝色部分是原数组，绿色是我们求得的前缀和(前缀和就是从索引0一直求到这个位置的和)
  ![](https://gitee.com/deer-b/picture/raw/master/img/20231122201402.png)  
  不难注意到，[l,r]区间和就是前缀和数组S~r~-S~l-1~
  - 例如我们要求这段区间内的和:
  ![](https://gitee.com/deer-b/picture/raw/master/img/20231122201818.png)
  - 那么也就是在前缀和数组中找到这两个：
  ![](https://gitee.com/deer-b/picture/raw/master/img/20231122202006.png)
  - 也可以用图像的方式直观得到：
  ![](https://gitee.com/deer-b/picture/raw/master/img/20231122202224.png)
  深色部分是从-16往前一直到第一个的和，体现在绿色数组就是右侧箭头所指的数
  - 接着我们需要再减去深深蓝色部分，也就是绿色数组的左侧箭头：
  ![](https://gitee.com/deer-b/picture/raw/master/img/20231122202333.png)
  - 于是我们只让左箭头一直向右移动就能轻松枚举分成左右两半的所有情况了:
  ![](https://gitee.com/deer-b/picture/raw/master/img/20231122202803.png)
- **代码实现**：  
  - __C++:__
    ```C++
      void solve() {
        int n, Sum = 0, i, res = 0;
        cin >> n;
        vector<int>qwq(n);
        vector<int>prefix;
        for(auto &x : qwq) {
            cin >> x;
            Sum += x;
            prefix.emplace_back(Sum);//向前缀和数组中添加和
        }
        for(i = 0;i < n - 1;++i)res += (prefix[n - 1] - prefix[i]) == prefix[i];
        cout << res;
      }
    ```
  - __Python:__
    ```Python
      input()
      a=list(map(int,input().split()))
      b=[]
      SUM=SSUM=0
      for i in a:
          SUM+=i
          b.append(SUM)
      for i in range(len(b)-1):
          if b[i]==(b[-1]-b[i]):SSUM+=1
      print(SSUM)
    ```
### 其他题
---
没什么好说的，题解贴在下面
```python
  #A--------------------
  print("Welcome to the programming contest!")


  #B--------------------
  a=input()
  if len(a)>10:print(a[0]+str(len(a)-2)+a[-1])
  else:print(a)


  #C--------------------
  n,m,a=map(int,input().split())
  p=n//a if n%a==0 else n//a+1
  q=m//a if m%a==0 else m//a+1
  print(p*q)


  #E--------------------
  n=int(input())
  if n==2:print("NO")
  elif n%2==0:print("YES")
  else:print("NO")


  #F--------------------
  input()
  a=list(map(int,input().split()))
  if a.count(1)>0:print("Hard")
  else:print("Easy")


  #G--------------------
  n=int(input())
  step=int(not n%5==0)
  print(step+n//5)


  #H--------------------
  v,w=map(int,input().split())
  t=0
  while v<=w:
      t+=1
      v*=3
      w*=2
  print(t)


  #I--------------------
  n=int(input())
  print(bin(n)[2:])


  #J--------------------
  n,m=map(int,input().split())
  if n//m%2==1:print("Helen")
  else:print("DragonLee")


  #K--------------------
  n=int(input())
  print(n//100+n%100//20+n%20//10+n%10//5+n%5)


  #E--------------------
  n=int(input())
  m=0
  for i in range(n):m+=int(input().count("1")>1)
  print(m)
```