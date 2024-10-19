/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\11.25\D.cpp
 *@data      2023/11/26 17:43:53
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

char qwq[2002][2002];
int rows[2002], ranks[2002];
ll Sum = 0;
void solve() {
    int n, m, i, j;
    cin >> n;
    for(i = 0;i < n;++i) {
        cin >> qwq[i];
        for(j = 0;j < n;++j)if(qwq[i][j] == 'o')++rows[i];
    }
    for(i = 0;i < n;++i) 
        for(j = 0;j < n;++j)if(qwq[j][i] == 'o')++ranks[i];
    for(i = 0;i < n;++i)
        for(j = 0;j < n;++j)
            if(qwq[i][j] == 'o')if(rows[i] > 0 && ranks[j] > 0)Sum += (rows[i] - 1) * (ranks[j] - 1);
    cout << Sum;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}