/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\12.2\M.cpp
 *@data      2023/12/03 14:52:23
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m=0, i, j;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq) {
        cin >> x;
        m += x;
    }
    int sum = 0;
    if(m == 3) { cout << 1;return; }
    for(i = 0;i < n;++i) {
        while(qwq[i] >= 2 && qwq[i + 1] >= 1) {
            qwq[i] -= 2;--qwq[i+1];++sum;
        }
    }
    while(qwq[n - 1] >= 2 && qwq[0] >= 1) {
        qwq[n - 1] -= 2;--qwq[0];++sum;
    }
    cout << sum;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}