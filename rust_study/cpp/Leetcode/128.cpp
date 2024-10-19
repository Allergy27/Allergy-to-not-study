/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Leetcode\128.cpp
 *@data      2023/12/25 13:39:22
 */
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define ll long long

using namespace std;

int longestConsecutive(vector<int> &nums) {
    unordered_set<int> num_set;
    for(auto &x : nums)num_set.insert(x);
    int ans = 0;
    for(auto &x : num_set) {
        if(!num_set.count(x - 1)) {
            int now = x, len = 1;
            while(num_set.count(++now))++len;
            ans = max(ans, len);
        }
    }
    return ans;
}
void solve() {
    int n, m, i, j;
    vector<int> qwq = { 1, 2, 3, 4, 5, 6, 7 };
    cout << longestConsecutive(qwq);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}