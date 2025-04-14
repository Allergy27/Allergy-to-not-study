// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Leetcode\239.cpp
 * @date      2025/04/09 15:38:46
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

using namespace std;  // NOLINT
class Solution {
 public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        deque<int> q;
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(nums[i]);
            if (i - q.front() >= k) q.pop_front();
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> qwq(n);
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
