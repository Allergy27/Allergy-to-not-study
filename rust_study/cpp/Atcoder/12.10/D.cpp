/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.10\D.cpp
 *@data      2023/12/10 21:04:12
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a(vector<int> A, vector<int> B) {
    
}

void solve() {
    int n, m, i, j, k;
    cin >> n >> m;
    vector<vector<int>>AV(n, vector<int>(m));
    vector<vector<int>>BV(n, vector<int>(m));

    set<set<int>> Aall, Ball;
    for(i = 0;i < n;++i) {
        set<int> qwq;
        for(j = 0;j < m;++j) {
            cin >> k;
            AV[i][j] = k;
            qwq.emplace(k);
        }
        Aall.emplace(qwq);
    }
    for(i = 0;i < n;++i) {
        set<int> qwq;
        for(j = 0;j < m;++j) {
            cin >> k;
            BV[i][j] = k;
            qwq.emplace(k);
        }
        Ball.emplace(qwq);
    }
    if(Aall != Ball)cout << -1;
    else { //开始求了
        set<int> foundC, foundR;
        int col = 0, row = 0;
        for(i = 0;i < m;++i)foundC.emplace(AV[0][i]);
        for(i = 0;i < n;++i)foundR.emplace(AV[i][0]);
        for(i = 0;i < n;++i) {
            set<int> pvp;
            for(j = 0;j < m;++j)pvpC.emplace(BV[i][j]);
            if(pvpC == foundC) {
                col = i;
                break;
            }
        }
        for(j = 0;j < m;++j) {
            set<int>pvpR;
            for(i = 0;i < n;++i)pvpR.emplace(BV[i][j]);
            if(pvpR == foundR) {
                row = j;
                break;
            }
        }
        vector<int>AR;
        vector<int>BR;
        for(i = 0;i < n;++i) {
            AR.emplace(AV[i][0]);
            BR.emplace(BV[i][row]);
        }


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