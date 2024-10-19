/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.7\FF.cpp
 *@date      2024/03/07 20:27:40
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void qw(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}

void solve() {
    int x = 1, y = 2;
    qw(x, y);
    cout << x << y;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}