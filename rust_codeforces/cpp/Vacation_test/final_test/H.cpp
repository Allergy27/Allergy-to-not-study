/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Vacation_test\solve.cpp
 *@date      2024/08/20 13:56:29
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, x;
    cin >> n;
    vector<int>qwq(n), qaq(n + 1);
    for(int &x : qwq) {
        cin >> x;
        if(x <= n)qaq[x] += 1;
    }
    if(qwq[0] > n) {
        cout << "NO\n";
        return;
    }
    for(int i = n - 1;i >= 0;--i) {
        qaq[i] += qaq[i + 1];
        if(qwq[i] != qaq[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}