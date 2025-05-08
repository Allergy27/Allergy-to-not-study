/*
 * @lc app=leetcode.cn id=2537 lang=rust
 * @lcpr version=30104
 *
 * [2537] 统计好子数组的数目
 */

// @lc code=start
impl Solution {
    pub fn count_good(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let (mut l, mut r) = (0, 0);
        let mut qwq = std::collections::HashMap::new();
        let mut tmp = 0;
        let mut ans = 0;
        while r < n {
            while r < n && tmp < k {
                *qwq.entry(nums[r]).or_insert(0) += 1;
                tmp += qwq[nums[r]] - 1;
                r += 1;
            }
            ans += n - r;
            while l < r && tmp >= k {
                *qwq.entry(nums[l]).or_insert(0) -= 1;
                tmp -= qwq[nums[r]] - 1;
                ans += 1;
                l += 1;
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,1,1]\n10\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,3,2,2,4]\n2\n
// @lcpr case=end

 */
