/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.3\D.cpp
 *@data      2024/03/03 18:39:27
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n >> m;
    if(n > m && n - m <= 3 || m > n && m - n <= 2)cout << "Yes";
    else cout << "No";
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}