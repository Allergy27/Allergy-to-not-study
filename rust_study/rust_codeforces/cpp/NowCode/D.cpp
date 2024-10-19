/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace NowCode\D.cpp
 *@date      2024/03/10 15:06:14
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a / 2 > b + c)cout << "Yes\n" << (b + c) * 2 + 1;
    else cout << "No";

}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}