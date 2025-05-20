/*
 * @lc app=leetcode.cn id=1550 lang=rust
 * @lcpr version=30201
 *
 * [1550] 存在连续三个奇数的数组
 */

// @lc code=start
impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        arr.windows(3).fold(false, |ans, x| {
            ans | (x[0] % 2 == 1 && x[1] % 2 == 1 && x[2] % 2 == 1)
        })
    }
}
// @lc code=end

/*
// @lcpr case=start
// [2,6,4,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,34,3,4,5,7,23,12]\n
// @lcpr case=end

 */
