/*
 * @lc app=leetcode.cn id=3001 lang=rust
 * @lcpr version=20004
 *
 * [3001] 捕获黑皇后需要的最少移动次数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_moves_to_capture_the_queen(a: i32, b: i32, c: i32, d: i32, e: i32, f: i32) -> i32 {
        let check = |l: i32, m: i32, r: i32| l.min(r) < m && m < l.max(r);
        if a == e && (c != e || !check(b, d, f))
            || b == f && (d != f || !check(a, c, e))
            || c + d == e + f && (a + b != e + f || !check(c, a, e))
            || c - d == e - f && (a - b != e - f || !check(c, a, e))
        {
            1
        } else {
            2
        }
    }
}
// @lc code=end

/*
// @lcpr case=start
// 1\n1\n8\n8\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n3\n3\n4\n5\n2\n
// @lcpr case=end

 */
