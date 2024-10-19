/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace IntroductionToAlgorithm\ChapterNULL\bag.cpp
 *@data      2023/11/26 13:03:58
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, v, i, j;
    n = rand() % 10 + 5;
    v = rand() % 10 + 10;
    vector<vector<int>>qwq(n + 1, vector<int>(v + 1));
    vector<int>qwqV(n);
    vector<int>qwqW(n);
    //输入物品及价值
    for(auto &x : qwqW)x=rand()%10;qwqW.insert(qwqW.begin(), 0);
    for(auto &x : qwqV)x=rand()%10;qwqV.insert(qwqV.begin(), 0);
    //动态规划
    for(i = 1;i <= n;++i) {
        for(j = 1;j <= v;++j) {
            if(qwqW[i] > j)qwq[i][j] = qwq[i - 1][j];
            else qwq[i][j] = max(qwq[i - 1][j], qwq[i - 1][j - qwqW[i]] + qwqV[i]);
        }
    }
    cout << qwq[n][v] << '\n';
    while(n > 0 && v > 0) {
        if(qwq[n][v] == qwq[n - 1][v])n -= 1;
        else {
            cout << n << ' ';
            n -= 1;
            v -= qwqW[n];
        }
    }
}
int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}