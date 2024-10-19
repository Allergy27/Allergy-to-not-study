/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.21\a.cpp
 *@date      2024/03/21 18:55:00
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    ans += b / 3 + a;
    b %= 3;
    if(b != 0 && b + c < 3)cout << "-1\n";
    else cout << (ans + (b + c) / 3 + ((b + c) % 3 != 0)) << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}