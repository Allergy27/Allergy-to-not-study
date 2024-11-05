/*
 * @lc app=leetcode.cn id=3222 lang=rust
 * @lcpr version=20002
 *
 * [3222] 求出硬币游戏的赢家
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn losing_player(x: i32, y: i32) -> String {
        if x.min(y / 4) % 2 == 1 { String::from("Alice") } else { String::from("Bob") }
    }
}
// @lc code=end

/*
// @lcpr case=start
// 1\n4\n
// @lcpr case=end

// @lcpr case=start
// 1\n5\n
// @lcpr case=end

 */
