/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.7\A.cpp
 *@data      2024/03/07 18:33:52
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    unordered_map<int, int>qwq;
    for(i = 1;i < 2021;++i) {
        int k = i;
        while(k != 0) {
            ++qwq[k % 10];
            k /= 10;
        }
    }
    cout << qwq[2];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}