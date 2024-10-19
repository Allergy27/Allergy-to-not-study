/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\9.15\d.cpp
 *@date      2024/09/15 23:19:50
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;
using ll = long long;
int inf = 0x3f3f3f3f;

void solve() {
    int n, a, b, c, ans = 0;
    cin >> n;
    while(n--) {
        cin >> a >> b >> c;
        if(a + b + c > 1)++ans;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}