/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.10\C.cpp
 *@data      2023/12/10 20:15:01
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i;
    char qwq[1005];
    cin >> n >> m;
    cin >> qwq;
    int pa = m, la = 0, pn = m, ln = 0;
    for(i = 0;i < n;++i) {
        if(qwq[i] == '0') { pn = pa; ln = la; }
        else if(qwq[i] == '1') {
            if(pn == 0) {
                if(ln == 0)++la;
                else --ln;
            }
            else --pn;
        }
        else if(qwq[i] == '2') {
            if(ln == 0)++la;
            else --ln;
        }
    }
    cout << la;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}