/*
 * @lc app=leetcode.cn id=1 lang=rust
 *
 * [1] 两数之和
 */

// @lc code=start
impl Solution {
    pub fn distribute_candies(n: i32, limit: i32) -> i64 {
        let c = |n| if n > 1 {n as i64 * (n as i64 - 1) / 2} else {0};
        c(n + 2) - 3  * c(n - limit + 1) + 3 * c(n - 2 * limit) - c(n - 3 * limit - 1)
    }
}
// @lc code=end
