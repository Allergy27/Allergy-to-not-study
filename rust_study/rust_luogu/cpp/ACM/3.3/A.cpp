/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.3\A.cpp
 *@data      2024/03/03 18:35:36
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << "AGC0" //开头一定是这个
        << (n < 10 ? "0" : "") //如果是个位数补0
        << (n >= 42 ? n + 1 : n); //如果大于等于42要添1
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}