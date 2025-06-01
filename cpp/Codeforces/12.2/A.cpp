/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\12.2\A.cpp
 *@data      2023/12/03 12:37:23
 */
#include<bits/stdc++.h>
#define ll long long

char qwq[5][5];
bool qvq[5][5];
int len = 0;
int ppt = 0,Min=333;
using namespace std;

void dfs(int x, int y) {
    if(!qvq[x][y]&&qwq[x][y]) {
        qvq[x][y] = true;
        ppt = ppt * 10 + qwq[x][y];
        ++len;
        if(len < 3) {
            int Min[3] = { 0, 0, 4 };
            for(int i = -1;i < 2;++i)
                for(int j = -1;j < 2;++j)
                    dfs(x + i, y + j);
        }
        if(ppt > 100&&ppt < Min)Min = ppt;
        ppt /= 10;
        qvq[x][y] = false;
        --len;
    }
}

void solve() {
    int n, m, i, j;
    for(i = 1;i <= 3;++i) {
        cin >> qwq[i][1] >> qwq[i][2] >> qwq[i][3];
        for(j = 1;j <= 3;++j)qwq[i][j] -= 'A'-1;
    }
    for(i = 1;i <= 3;++i)
        for(j = 1;j <= 3;++j) {
            ppt = 0;
            dfs(i, j);
        }
    int res = Min;
    cout << (char) ('A' + res / 100 - 1) << (char) ('A' + res % 100 / 10 - 1) << (char) ('A' + res % 10 - 1);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}