/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.28\A.cpp
 *@data      2024/02/28 18:45:10
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
int qvq[101][101];
void solve() {
    int n, m, i, j, k, ans = 0;
    cin >> n >> m; //输入
    for(i = 0;i < m;++i) {
        cin >> k;
        vector<int>qwq(k); //每次开趴的人数
        for(auto &x : qwq)cin >> x; //读入
        for(int x : qwq)
            for(int y : qwq)
                qvq[x][y] = 1; //遍历过去，标记
    }
    for(i = 1;i <= n;++i)
        for(j = 1;j <= n;++j)
            ans += qvq[i][j]; //统计是否有漏洞
    cout << (ans == n * n ? "Yes" : "No");
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}