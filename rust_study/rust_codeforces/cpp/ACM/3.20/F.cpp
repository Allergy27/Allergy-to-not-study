/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.20\F.cpp
 *@date      2024/03/29 06:53:59
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a + 1 != c) {
        cout << "-1\n";
        return;
    }
    if(a + b + c == 1) {
        cout << "0\n";
        return;
    }
    int now = 1, nex = 0, ans = 1;
    for(int i = 0; i < a + b;++i) {
        if(!now) {
            swap(now, nex);
            ++ans;
        }
        --now, nex+=(i<a? 2:1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}