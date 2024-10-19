/*
 * @lc app=leetcode.cn id=2974 lang=rust
 *
 * [2974] 最小数字游戏
 */

// @lc code=start
impl Solution {
    pub fn number_game(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort_unstable();
        let n = nums.len();
        (0..n).step_by(2).for_each(|i| nums.swap(i, i + 1));
        nums
    }
}
// @lc code=end
