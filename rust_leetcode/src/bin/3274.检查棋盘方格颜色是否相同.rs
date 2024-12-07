/*
 * @lc app=leetcode.cn id=3274 lang=rust
 * @lcpr version=20004
 *
 * [3274] 检查棋盘方格颜色是否相同
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn check_two_chessboards(coordinate1: String, coordinate2: String) -> bool {
        let a = coordinate1.as_bytes();
        let b = coordinate2.as_bytes();
        (a[0] - b'a' + a[1] - b'1') % 2 == (b[0] - b'a' + b[1] - b'1') % 2
    }
}
// @lc code=end

/*
// @lcpr case=start
// "a1"\n"c3"\n
// @lcpr case=end

// @lcpr case=start
// "a1"\n"h3"\n
// @lcpr case=end

 */
