/*
 * @lc app=leetcode.cn id=643 lang=rust
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let k = k as usize;
        let mut sum_num = nums[0..k].iter().sum::<i32>();
        nums.windows(k).fold(sum_num, |ans, x| {
            sum_num += x[k - 1] - x[0];
            ans.max(sum_num)
        }) as f64
            / k as f64
    }
}
// @lc code=end
