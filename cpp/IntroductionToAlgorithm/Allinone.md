# 珍藏的乱七八糟的算法&数据结构
---
## 目录:
- __算法__
  - [二分查找](#二分查找)
  - [归并排序](#归并排序)
  - [堆排序](#堆排序)
- __数据结构__
  - [优先队列](#优先队列)
  - [二叉查找树](#二叉查找树)
---
### 二分查找
[~返回目录~](#目录)
- __算法思想__: 
    - 先找到中位数
    - 检查中位数和目标数的大小关系
<details>
    <summary>代码部分</summary>

```C++
int Bisect_left(vector<int> list, int num) {//左偏的二分
    int low = 0, high = list.size() - 1;
    while(low < high) {
        int mid = low + high >> 1;
        if(list[mid] >= num)high = mid;
        else low = mid + 1;
    }
    return low;
}
int Bisect_right(vector<int> list, int num) {//右偏的二分
    int low = 0, high = list.size() - 1;
    while(low < high) {
        int mid = low + high >> 1;
        if(list[mid] >= num)high = mid - 1;
        else low = mid;
    }
    return high;
}
```

</details>

---
### 归并排序
[~返回目录~](#目录)
- __算法思想__:
    - 将原先无序的的序列分解成若干个($log$<sub>2</sub>$(n)$)有序的子序列  
    - 对于每个子序列都是有序序列  
    - 接着开始回升，回升的过程中合并相邻子序列  
    - 合并结束时序列已经有序
<details>
    <summary>代码部分</summary>

```C++
void MERGE_SORT(vector<int> &list, int p, int r) {
    int q = (p + r) / 2;//二分
    if(p >= r)return;//当左大于右的时候退出
    MERGE_SORT(list, p, q);//分裂左边
    MERGE_SORT(list, q + 1, r);//分裂右边
    //下面是合并函数，干脆写在一起了。
    vector<int>L, R;//记录左右子树？可以这么理解罢。
    int a = 0, b = 0;//两个指针，记录左右各自取到哪里了。
    for(int x = p;x <= q;++x)L.emplace_back(list[x]);
    for(int x = q + 1;x <= r;++x)R.emplace_back(list[x]);
    for(int k = p;k <= r;++k) {
        if(a == q + 1 - p) list[k] = R[b++];//如果L取完了，那就只取R了
        else if(b == r - q) list[k] = L[a++];//如果R取完了，那就只取L了
        else if(L[a] < R[b]) list[k] = L[a++];//取小的那一个放
        else list[k] = R[b++];
    }
}
```
</details>

---
### 堆排序
[~返回目录~](#目录)
- __算法思想__：
  - 建立最大堆
  - 每次将根节点抽离
  - 输出
  - (有点像选择排序，得益于堆的性质，会比他快一些)
<details>
    <summary>代码部分</summary>

```C++
void HEAPSORT(vector<int> &A) { //堆排序
    void BUILD_MAX_HEAP(vector<int>&); //建堆
    void MAX_HEAPIFY(vector<int>&, int); //维护堆
    BUILD_MAX_HEAP(A);
    vector<int>B; //保存排序结果
    for(int i = A.size() - 1; i >= 1; --i) {
        B.emplace_back(A[0]); //传入最大值（堆的根节点
        A[i] ^= A[0]; A[0] ^= A[i]; A[i] ^= A[0]; //交换
        A.pop_back(); //去掉原先的根节点避免反复读取
        MAX_HEAPIFY(A, 0); //维护
    }
    B.emplace_back(A[0]); //输出最后一个值
    reverse(B.begin(), B.end()); //去掉输出倒序
    for(auto &x : B)cout << x << ' ';
}

void BUILD_MAX_HEAP(vector<int> &A) { //建堆
    void MAX_HEAPIFY(vector<int>&, int);
    for(int i = A.size() / 2; i >= 0; --i)MAX_HEAPIFY(A, i); //维护建堆
}

void MAX_HEAPIFY(vector<int> &A, int i) { //维护堆
    int root = i;
    while(true) {
        int l = 2 * root + 1, r = 2 * root + 2; //左右孩子
        int largest = root;
        if(l<A.size() && A[l]>A[root])largest = l;
        if(r<A.size() && A[r]>A[largest])largest = r;
        if(largest != root) { A[root] ^= A[largest]; A[largest] ^= A[root]; A[root] ^= A[largest]; } //交换
        else break;
        root = largest;
    }
}
```

</details>

---
### 优先队列
[~返回目录~](#目录)
- __底层实现__：堆
- 可用操作：
  - 构建优先队列
  - 插入一个值
  - 返回最大值
  - 返回并删去最大值
  - 将x的值增加到k
<details>
    <summary>代码部分：</summary>

```C++
class Priority_queue { //优先队列（最大堆实现
public:
    void BUILD_MAX_HEAP(vector<int> A) { //构建优先队列
        S = A;
        for(int i = S.size() / 2; i >= 0; --i)MAX_HEAPIFY(S, i);
    }
    void Insert(int k) { //向优先队列插入元素
        S.emplace_back(k - 1);
        Increase_key(S.size() - 1, k);
    }
    int Maximum() { return S[0]; } //返回最大值
    void Extract_max() { //去掉并返回最大值
        if(S.size() < 0) { cout << "No\n";return; }
        int Max = S[0];
        S[0] = S[S.size() - 1];
        S.pop_back();
        MAX_HEAPIFY(S, 0);
        cout << Max << ' ';
    }
    void Increase_key(int i, int k) { //将字段i的值增加到k
        if(k < S[i]) { cout << "No\n";return; }
        S[i] = k;
        while(i > 0 && S[(i - 1 >> 1)] < S[i]) {
            S[i] ^= S[(i - 1 >> 1)];S[(i - 1 >> 1)] ^= S[i];S[i] ^= S[(i - 1 >> 1)];
            i = i - 1 >> 1;
        }
    }
private:
    vector<int> S;
    void MAX_HEAPIFY(vector<int> &A, int i) { //维护堆
        int root = i;
        while(true) {
            int l = 2 * root + 1, r = 2 * root + 2; //左右孩子
            int largest = root;
            if(l<A.size() && A[l]>A[root])largest = l;
            if(r<A.size() && A[r]>A[largest])largest = r;
            if(largest != root) {
                A[root] ^= A[largest];A[largest] ^= A[root]; A[root] ^= A[largest];
            } //交换
            else break;
            root = largest;
        }
    }
};
```
</details>

---
### 二叉查找树
[~返回目录~](#目录)
- __底层实现：__ 一颗 __二叉树__，满足如下性质：
  - 所有 __左__ 子树上元素 __小__ 于根节点
  - 所有 __右__ 子树上元素 __大__ 于等于根
- 于是 __中序遍历__ 时这个树是有序的


<details>
    <summary>代码部分：</summary>

```C++
class Tree { //二叉查找树
public:
    void init(int x) { //初始化
        this->val = x;
        this->p = NULL;
        this->left = NULL;
        this->right = NULL;
    }
    void add(int x) { //添加新元素
        Tree *root = this;
        Tree *son = new Tree;
        son->init(x);
        while(true) {
            if(x < root->val) { //新元素满足小于根节点
                if(root->left == NULL) { //左子树为空
                    son->p = root;
                    root->left = son;
                    break;
                }
                else root = root->left; //非空向左搜索
            }
            else { //大于等于根节点
                if(root->right == NULL) { //右子树为空
                    son->p = root;
                    root->right = son;
                    break;
                }
                else root = root->right; //非空向右搜
            }
        }
    }

    void INORDER_TREE() { //中序遍历
        Tree *x = this;
        INORDER_TREE_WALK(x);
    }

    void Tree_Search(int k) { //搜索
        Tree *x = this;
        Tree *tmp = Search(x, k);
        if(tmp != NULL)cout << "\n" << tmp->val;
        else cout << "\n-1";
    }
private:
    int val;
    Tree *p, *left, *right;
    void INORDER_TREE_WALK(Tree *x) { //中序遍历底层
        if(x != NULL) {
            INORDER_TREE_WALK(x->left);
            cout << x->val << ' ';
            INORDER_TREE_WALK(x->right);
        }
    }
    Tree *Search(Tree *x, int k) { //搜索底层
        if(x == NULL || k == x->val)return x;
        if(k < x->val)return Search(x->left, k);
        else return Search(x->right, k);
    }
};
```
</details>

<details>
    <summary>实例：</summary>

```C++
void solve() {
    Tree *qwq = new Tree; //声明二叉查找树
    qwq->init(527); //初始化

    vector<int>pvp(27); //创建容器放入二叉查找树
    for(auto &x : pvp)x = rand() % 1000;

    for(auto x : pvp)qwq->add(x); //创建二叉查找树

    qwq->INORDER_TREE(); //中序遍历这棵树
    qwq->Tree_Search(527); //查找527
}
```
</details>
