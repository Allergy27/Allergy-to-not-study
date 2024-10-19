/*
 * @lc app=leetcode.cn id=53 lang=rust
 *
 * [53] 最大子数组和
 */

// @lc code=start
impl Solution {
    pub fn max_sub_array(mut nums: Vec<i32>) -> i32 {
        nums.into_iter()
            .enumerate()
            .fold(0, |ans, (i,x)| x + nums[i - 1].max(0))
    }
}
// @lc code=end
