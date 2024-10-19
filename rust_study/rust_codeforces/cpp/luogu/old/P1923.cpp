/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1923.cpp
 *@data      2024/01/17 19:25:03
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void changed_qsort(int l, int r, vector<int> &qwq, int k) {
    int i = l, j = r, mid = qwq[(l + r) / 2];
    do {
        while(qwq[j] > mid)--j;
        while(qwq[i] < mid)++i;
        if(i <= j)swap(qwq[i++], qwq[j--]);
    } while(i <= j);//上面这部分以及下面这部分是传统快排
    if(k <= j)changed_qsort(l, j, qwq, k);//这里操作后我们使其分成成 l-j j-i i-r 三个部分
    else if(i <= k)changed_qsort(i, r, qwq, k);//并只去排序 k 所在的区间，当然 j-i 中间是 mid，所以每个区间都局部有序
    else cout << qwq[j + 1];
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    changed_qsort(0, n - 1, qwq, k);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}