/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\4.20\d.cpp
 *@date      2024/04/20 19:15:24
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j, x;
    cin >> n;
    vector<vector<int>>grid(5);
    grid[0] = { 1, 2, 3, 4, 5 };
    grid[1] = { 6, 7, 8, 9, 10 };
    grid[2] = { 11, 12, 13, 14, 15 };
    grid[3] = { 16, 17, 18, 19, 20 };
    grid[4] = { 21, 22, 23, 24, 25 };
    auto qwq = [&](int x) {
        if(x <= 5) {
            int t = grid[x - 1][4];
            for(int i = 4;i > 0;--i) {
                grid[x - 1][i] = grid[x - 1][i - 1];
            }
            grid[x - 1][0] = t;
        }
        else {
            int t = grid[4][x - 6];
            for(int i = 4;i > 0;--i) {
                grid[i][x - 6] = grid[i - 1][x - 6];
            }
            grid[0][x - 6] = t;
        }
        };
    for(int i = 0;i < n;++i) {
        cin >> x;
        qwq(x);
    }
    for(auto x : grid) {
        for(auto y : x)printf("%2d ", y);
        cout << "\n";
    }

}

int main() {
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}