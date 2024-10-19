/*
 * @lc app=leetcode.cn id=2660 lang=rust
 *
 * [2660] 保龄球游戏的获胜者
 */

// @lc code=start
impl Solution {
    pub fn is_winner(player1: Vec<i32>, player2: Vec<i32>) -> i32 {
        let sore_sum = |player: &Vec<i32>| -> i32 {
            (0..player.len()).fold(0, |x, i| {
                (x + player[i] * (if i > 0 && player[i - 1] == 10 || i > 1 && player[i - 2] == 10 { 2 } else { 1 }))
            })
        };
        match sore_sum(&player1).cmp(&sore_sum(&player2)) {
            std::cmp::Ordering::Equal => 0,
            std::cmp::Ordering::Greater => 1,
            std::cmp::Ordering::Less => 2,
        }
    }
}
// @lc code=end
