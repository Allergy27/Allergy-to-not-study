/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.2\E.cpp
 *@data      2023/12/02 20:54:56
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j, l, c, d, Max = 0;
    cin >> n >> m >> l;
    vector<int>qwq(n);
    vector<int>qaq(m);
    for(auto &x : qwq)cin >> x;
    for(auto &x : qaq)cin >> x;
    map<vector<int>, int>qvq; //记录不合理的搭配
    while(l--) {
        cin >> c >> d;
        qvq.insert(pair<vector<int>, int>({ qwq[c - 1], qaq[d - 1] }, 1)); //装个表
    }
    sort(qaq.begin(), qaq.end());
    for(i = 0;i < n;++i) {
        for(j = m - 1;j >= 0;--j) {
            if(!qvq.contains({ qwq[i], qaq[j] })) {
                Max = max(qwq[i] + qaq[j], Max);
                break; //后面的配菜都会更便宜，没必要找了
            }
        }
    }
    cout << Max;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}