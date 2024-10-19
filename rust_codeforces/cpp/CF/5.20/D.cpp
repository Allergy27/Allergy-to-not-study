/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\5.20\D.cpp
 *@date      2024/05/20 23:48:00
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> qwq;
    qwq['N'] = 0;
    qwq['S'] = 0;
    qwq['W'] = 0;
    qwq['E'] = 0;
    vector<int>qvq(s.size());
    for(auto x : s)
        ++qwq[x];
    int NS = qwq['N'] + qwq['S'], WE = qwq['W'] + qwq['E'];
    /*
    if(NS & 1 || WE & 1
        || (qwq['N'] == qwq['S'] && NS == 2 && WE == 0)
        || (qwq['W'] == qwq['E'] && NS == 0 && WE == 2)) {
        cout << "NO\n";
        return;
    }
    */
    auto maxNSWE = [&](char x, char y) {
        return qwq[x] > qwq[y] ? x : y;
        }
    int mNS = maxNSWE('N', 'S'), mWE = maxNSWE('W', 'E');
    for() {

    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}