/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace A.cpp
 *@date      2024/08/28 13:55:28
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, count = 0;
    bool a = 1;
    cin >> n;
    for (; n != 1;) {
        a = 0;
        if (n % 2 == 0) {
            n = n / 2;
            a = 1;
            count++;
            continue;
        }
        if (n % 3 == 0) {
            n = n / 3 * 2;
            a = 1;
            count++;
            continue;
        }
        if (n % 5 == 0) {
            n = n / 5 * 4;
            a = 1;
            count++;
            continue;
        }
        if (a == 0) break;
    }
    if (a == 0)
        cout << "-1\n";
    else
        cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
