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
    for(auto x : s)
        ++qwq[x];
    int NS = qwq['N'] + qwq['S'], WE = qwq['W'] + qwq['E'];
    if(NS & 1 || WE & 1
        || (qwq['N'] == qwq['S'] && NS == 2 && WE == 0)
        || (qwq['W'] == qwq['E'] && NS == 0 && WE == 2)) {
        cout << "NO\n";
        return;
    }
    int a = qwq['N'] + qwq['S'] >> 1, b = qwq['W'] + qwq['E'] >> 1;
    int ra = 0, rb = 0;
    int mNS = qwq['N'] > qwq['S'] ? 'N' : 'S';
    int mWE = qwq['W'] > qwq['E'] ? 'W' : 'E';
    bool flag = false;
    for(auto x : s) {
        if(qwq['N'] == qwq['S'] && WE == 0
            || qwq['W'] == qwq['E'] && NS == 0)
            if(x == 'N' || x == 'S') {
                cout << (flag ? 'R' : 'H'), ra += (x == mNS ? 1 : -1);
                if(ra == a)flag = true;
            }
            else {
                cout << (flag ? 'R' : 'H'), rb += (x == mWE ? 1 : -1);
                if(rb == b)flag = true;
            }

        else if(x == 'N' || x == 'S')
            cout << (ra != a ? 'R' : 'H'), ra += (x == mNS ? 1 : -1);
        else
            cout << (rb != b ? 'R' : 'H'), rb += (x == mWE ? 1 : -1);
    }
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