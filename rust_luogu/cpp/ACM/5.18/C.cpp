/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\5.18\C.cpp
 *@date      2024/05/18 20:19:31
 */
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int N = 2e7 + 5, lN = 2e7, Mod = 1e9 + 7;
int n, f[N], Ans, cnt; char ch[N];
signed main() {
    cin >> (ch + 1);
    n = strlen(ch + 1), f[1] = f[2] = 1;
    for(int i = 3; i <= lN; ++ i) f[i] = (f[i - 1] + f[i - 2]) % Mod;
    for(int i = 1; i <= n; ++ i) {
        if(ch[i] == '0') continue;
        Ans = (Ans + f[2 * (n - i) + cnt]) % Mod;
        ++ cnt;
    }
    Ans = (Ans + f[cnt]) % Mod;

    cout << Ans << '\n';

    return 0;
}