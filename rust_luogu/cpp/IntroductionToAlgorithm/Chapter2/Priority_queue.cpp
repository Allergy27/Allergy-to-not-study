/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace IntroductionToAlgorithm\Chapter2\Priority_queue.cpp
 *@data      2023/11/21 17:37:23
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

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

void solve() {
    int n, m, i, j;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    Priority_queue qaq;
    qaq.BUILD_MAX_HEAP(qwq);
    while(n--)qaq.Extract_max();
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}