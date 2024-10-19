/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.4\A.cpp
 *@data      2024/03/04 18:35:48
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    double a, b, c, x;
    cin >> a >> b >> c >> x;
    if(x > b)cout << 0.000000000000;
    else if(x < a)cout << 1.000000000000;
    else printf("%.12lf", c / (b - a));
}

int main() {
    //ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}