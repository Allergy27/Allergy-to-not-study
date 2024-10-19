/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\9.15\f.cpp
 *@date      2024/09/15 23:22:31
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;
using ll = long long;
int inf = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n;
    set<int>qwq;
    for(int j = 0;j < 2;++j) {
        cin >> m;
        for(int i = 0;i < m;++i) {
            int x;
            cin >> x;
            qwq.insert(x);
        }
    }
    if(qwq.size() == n)cout << "I become the guy.";
    else cout << "Oh, my keyboard!";
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}