/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Algorithm\HEAPSORT.cpp
 *@data      2023/11/20 20:57:59
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
void solve() {
    void HEAPSORT(vector<int>&);
    int n;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    HEAPSORT(qwq);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}

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
    for(int i = A.size() / 2; i >= 0; --i)MAX_HEAPIFY(A, i);
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