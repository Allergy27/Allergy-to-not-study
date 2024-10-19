/*
 * @lc app=leetcode.cn id=724 lang=rust
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let sum = nums.iter().fold(0, |ans, x| ans + x);
        let mut left_sum = 0;
        nums.iter().enumerate().fold(-1, |ans, (i, &x)| {
            left_sum += x;
            if ans != -1 || sum + x == left_sum << 1 {
                i as i32
            } else {
                -1
            }
        })
    }
}
// @lc code=end
