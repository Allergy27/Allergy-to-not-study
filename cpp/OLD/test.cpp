/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace test.cpp
 *@data      2024/01/04 12:47:59
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void turn(int x, int n) {
    string str = "";
    while (x != 0) {
        str = to_string(x % 2) + str;
        x /= 2;
    }
    while (str.size() < n) str = "0" + str;
    cout << str << '\n';
}

void GospersHack(int k, int n) {
    int cur = (1 << k) - 1;
    int limit = (1 << n);
    while (cur < limit) {
        // do something
        turn(cur, n);
        cur = ((((cur + (cur & -cur)) ^ cur) >> 2) / (cur & -cur)) | (cur + (cur & -cur));
    }
}

void solve() {
    GospersHack(3, 7);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}