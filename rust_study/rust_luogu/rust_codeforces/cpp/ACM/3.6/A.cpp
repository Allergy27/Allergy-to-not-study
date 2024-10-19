/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.6\A.cpp
 *@data      2024/03/06 18:18:25
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    for(char i = 10;i < 100;++i)
        for(char j = 1;j < 27;++j)
            for(char k = 1;k < 27;++k)
                if((i * 26 * 26 + j * 26 + k) == 2019) {
                    cout << (char) ('@' + i) << (char) ('@' + j) << (char) ('@' + k);
                    break;
                }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}