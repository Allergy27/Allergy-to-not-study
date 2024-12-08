/*
 * @lc app=leetcode.cn id=1812 lang=rust
 * @lcpr version=20004
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn square_is_white(coordinates: String) -> bool {
        let coord = coordinates.as_bytes();
        (coord[0] - b'a') % 2 != (coord[1] - b'1') % 2
    }
}
// @lc code=end

/*
// @lcpr case=start
// "a1"\n
// @lcpr case=end

// @lcpr case=start
// "h3"\n
// @lcpr case=end

// @lcpr case=start
// "c7"\n
// @lcpr case=end

 */
