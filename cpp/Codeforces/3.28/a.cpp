/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\3.28\a.cpp
 *@date      2024/03/28 22:47:29
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    string ans = "NONE";
    if(a<b && b>c)ans = "PEAK";
    if(a < b && b < c)ans = "STAIR";
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