/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Leetcode\1671.cpp
 *@data      2023/12/22 18:00:53
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int minimumMountainRemovals(vector<int> &nums) {
    int n = nums.size();
    vector<int> qwq, qaq(n);
    for(int i = 0;i < n;++i) {
        int x = nums[i];
        if(qwq.size() == 0 || qwq[qwq.size() - 1] < x)qwq.push_back(x);
        else *lower_bound(qwq.begin(), qwq.end(), x) = x;
        qaq[i] = qwq.size();
    }
    qwq.clear();
    int ans = 0;
    for(int i = n - 1;i >= 0;--i) {
        int x = nums[i];
        if(qwq.size() == 0 || qwq[qwq.size() - 1] < x)qwq.push_back(x);
        else *lower_bound(qwq.begin(), qwq.end(), x) = x;
        int c = qwq[qwq.size() - 1];
        if(c > 1 && qaq[i] > 1)ans = max(ans, c + qaq[i] - 1);
    }
    return n - ans;
}
void solve() {
    int n, m, i, j;
    vector<int>qwq = { 1, 6, 3, 1 };
    minimumMountainRemovals(qwq);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}

