/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Leetcode\11.cpp
 *@data      2023/12/25 14:43:46
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1, ans = min(height[0], height[height.size() - 1]) * (height.size() - 1);
    while(l < r) {
        if(height[l] < height[r])ans = max(ans, min(height[++l], height[r]) * (r - l));
        else ans=max(ans, min(height[l], height[--r]) * (r - l));
    }
    return ans;
}

void solve() {
    int n, m, i, j;
    vector<int>qwq = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(qwq);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}