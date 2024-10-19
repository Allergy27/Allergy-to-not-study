/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1059.cpp
 *@data      2024/01/17 19:58:44
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    vector<bool>bucket(1001);
    int n;
    cin >> n;
    int ans = n, i;
    for(int _ = 0;_ < n;++_) {
        cin >> i;
        if(!bucket[i])bucket[i] = true;
        else --ans;
    }
    cout << ans << '\n';
    for(i = 1;i <= 1000;++i)if(bucket[i])cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}