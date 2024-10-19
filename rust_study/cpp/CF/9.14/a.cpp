/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\9.14\a.cpp
 *@date      2024/09/14 22:35:33
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    char  qwq[] = { 'a', 'e', 'i', 'o', 'u' };
    int cnt = n / 5, res = n % 5;
    for(int i = 0;i < 5;++i) {
        if(res-- > 0)cout << qwq[i];
        for(int j = 0;j < cnt;++j)cout << qwq[i];
    }

    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}