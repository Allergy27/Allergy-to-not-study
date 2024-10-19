/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1021(WA.cpp
 *@data      2023/12/21 14:25:33
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 51;
const int INF = 2147483647;
int n, k, f[maxn], b[maxn], ans, dp[maxn * 100];
void dfs(int x) {
    if(x == k + 1) {

        int i = 0;
        while(dp[i] <= n) {
            i++;
            dp[i] = INF;
            for(int j = 1;j <= k && i - f[j] >= 0;j++) {
                dp[i] = min(dp[i], dp[i - f[j]] + 1);
            }
        }
        if(i - 1 > ans) {
            for(int j = 1;j <= k;j++) {
                b[j] = f[j];
                ans = i - 1;
            }
        }
        return;
    }
    for(int i = f[x - 1] + 1;i <= f[x - 1] * n + 1;i++) {
        f[x] = i;
        dfs(x + 1);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    f[1] = 1;
    dfs(2);
    for(int i = 1;i <= k;i++)cout << b[i] << ' ';
    cout << "\n";
    cout << "max=" << ans;
    //cin >> t;
    cin >> n;
    return 0;
}
