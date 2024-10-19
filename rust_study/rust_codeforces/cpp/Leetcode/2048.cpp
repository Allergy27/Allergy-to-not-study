/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Leetcode\2048.cpp
 *@data      2023/12/09 20:19:33
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n;
    for(int i = n + 1;;++i) {
        int qwq[10] = { 0 }, ans = i;
        bool flag = false;
        while(ans > 0) {
            if(++qwq[ans % 10] > ans % 10)break;
            ans /= 10;
        }
        for(int j = 0;j < 10;++j) {
            if(qwq[j] != j) {
                flag = true;
                break;
            }
        }
        if(!flag)break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}