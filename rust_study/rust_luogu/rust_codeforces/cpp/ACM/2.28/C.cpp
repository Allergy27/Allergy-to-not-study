/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.28\C.cpp
 *@data      2024/02/28 18:52:58
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, h, m;
    cin >> n;
    h = n / 60;
    m = n % 60;
    cout << h + 21 << ":";
    if(m < 10)cout << 0;
    cout << m;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}