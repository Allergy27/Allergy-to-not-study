/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.3\E.cpp
 *@data      2024/03/03 18:58:13
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<ll> score(n); //存各个玩家得分
    unordered_map<ll, int> qwq; //存种类数
    qwq[0] = n; //一开始玩家得分都是0
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        --a; //也可以一开始就 n+1 ，这里就不用--了
        if (--qwq[score[a]] == 0) qwq.erase(score[a]); //移除0种的避免污染 .size() 的统计
        score[a] += b; //记录得分
        ++qwq[score[a]]; //记录种类
        cout << qwq.size() << '\n'; //输出
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}