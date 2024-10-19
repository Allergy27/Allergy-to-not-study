/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.3\C.cpp
 *@data      2024/03/03 18:45:12
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, ans = 0, i, j, x, y;
    cin >> n;
    vector<vector<int>>qwq(n + 1);
    for(i = 1;i < n;++i) { //邻接矩阵建树
        cin >> x >> y;
        qwq[x].emplace_back(y); 
        qwq[y].emplace_back(x);
    }
    for(auto x : qwq)if(x.size() > 1)ans++; //记录不只有一条边的节点数
    if(ans == 1)cout << "Yes"; //如果只有一个点连了多条边，那就是星
    else cout << "No";
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}