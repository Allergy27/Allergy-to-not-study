/*
 * @lc app=leetcode.cn id=3248 lang=rust
 * @lcpr version=20003
 *
 * [3248] 矩阵中的蛇
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn final_position_of_snake(n: i32, commands: Vec<String>) -> i32 {
        commands.into_iter().fold(0, |pos, command| match command.as_str() {
            "UP" => pos - n,
            "DOWN" => pos + n,
            "RIGHT" => pos + 1,
            "LEFT" => pos - 1,
            _ => unreachable!(),
        })
    }
}
//081yz2100wErdT1Bbb1002ewFl0yz21N
// @lc code=end

/*
// @lcpr case=start
// 2\n["RIGHT","DOWN"]\n
// @lcpr case=end

// @lcpr case=start
// 3\n["DOWN","RIGHT","UP"]\n
// @lcpr case=end

 */
