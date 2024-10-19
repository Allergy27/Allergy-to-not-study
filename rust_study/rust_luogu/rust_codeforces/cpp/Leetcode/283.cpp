/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Leetcode\283.cpp
 *@data      2023/12/25 14:26:52
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void moveZeroes(vector<int> &nums) {
    int pos = 0;
    for(auto &x : nums)if(x)nums[pos++] = x;
    for(int i = pos;i < nums.size();++i)nums[i] = 0;
}


void solve() {
    int n, m, i, j;
    vector<int>qwq = { 1, 0, 2, 0, 3, 0, 4, 0 };
    moveZeroes(qwq);
    for(auto &x : qwq)cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}