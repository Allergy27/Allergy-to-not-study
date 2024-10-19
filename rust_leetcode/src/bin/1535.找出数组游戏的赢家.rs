/*
 * @lc app=leetcode.cn id=1535 lang=rust
 *
 * [1535] 找出数组游戏的赢家
 */

// @lc code=start
impl Solution {
    pub fn get_winner(arr: Vec<i32>, k: i32) -> i32 {
        arr.iter()
            .fold((0, 0), |ans, &x| {
                if ans.1 == k {
                    ans
                } else {
                    if x > ans.0 {
                        (x, 1)
                    } else {
                        (ans.0, ans.1 + 1)
                    }
                }
            })
            .0
    }
}
// @lc code=end
