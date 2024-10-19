/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Bb.cpp
 *@date      2024/09/14 20:53:03
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int>qwq;
    for(int i = 0;i < m;++i) {
        int a;
        char b;
        cin >> a >> b;
        if(b == 'M' && qwq[a] == 0) {
            qwq[a]++;
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}