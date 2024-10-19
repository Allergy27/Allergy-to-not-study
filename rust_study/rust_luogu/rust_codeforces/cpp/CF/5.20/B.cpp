/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\5.20\B.cpp
 *@date      2024/05/20 22:59:27
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n;
    string s;
    cin >> s;
    set<char>qaq;
    for(i = 0;i < n;++i)
        qaq.insert(s[i]);
    vector<int>qwq;
    for(auto x : qaq)qwq.emplace_back(x);
    int SZ = qwq.size();
    unordered_map<char, char>qvq;
    if(SZ & 1)qvq[qwq[SZ >> 1]] = qwq[SZ >> 1];
    for(i = 0;i < SZ >> 1;++i) {
        qvq[qwq[i]] = qwq[SZ - i - 1];
        qvq[qwq[SZ - i - 1]] = qwq[i];
    }
    for(auto x : s)cout << qvq[x];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}