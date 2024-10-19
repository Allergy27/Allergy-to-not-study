/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.16\B.cpp
 *@data      2023/12/17 17:32:25
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    char s1, s2, t1, t2;
    cin >> s1 >> s2;
    cin >> t1 >> t2;
    if(s1 > s2)s2 += 5;
    if(t1 > t2)t2 += 5;
    s1 = s2 - s1 > 2 ? (s2 - s1) % 2 + 1 : s2 - s1;
    t1 = t2 - t1 > 2 ? (t2 - t1) % 2 + 1 : t2 - t1;
    if(s1 == t1)cout << "Yes";
    else cout << "No";
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}