/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\4.20\e.cpp
 *@date      2024/04/20 19:38:46
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int>qwq(n);
    map<int, int>qaq;
    for(auto &x : qwq) {
        cin >> x;
        ++qaq[x];
    }
    vector<int>qvq;
    vector<int>p;
    for(auto &[x, y] : qaq)qvq.emplace_back(x), --y;
    swap(qvq[qvq.size() - 1], qvq[qvq.size() - 2]);
    for(auto [x, y] : qaq)if(y)p.emplace_back(x);
    sort(p.begin(), p.end(), greater<>());
    for(auto x : p)qvq.emplace_back(x);
    for(int i = 0;i < qvq.size();++i)ans = max(abs(qvq[(i + 1) % qvq.size()] - qvq[i]), ans);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}