/*
 * @lc app=leetcode.cn id=1984 lang=rust
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();
        let n = nums.len();
        (k..n).fold(nums[k - 1] - nums[0], |ans, i| {
            ans.min(nums[i] - nums[i - k + 1])
        })
    }
}
// @lc code=end
