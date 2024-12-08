/*
 * @lc app=leetcode.cn id=688 lang=rust
 * @lcpr version=20004
 *
 * [688] 骑士在棋盘上的概率
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn knight_probability(n: i32, k: i32, row: i32, column: i32) -> f64 {
        let mut dp = vec![vec![vec![0f64; n as usize]; n as usize]; k as usize + 1];
        for x in &mut dp[0] {
            for y in x {
                *y = 1f64;
            }
        }
        let way = [
            (-2, -1),
            (-1, -2),
            (1, -2),
            (2, -1),
            (-2, 1),
            (-1, 2),
            (2, 1),
            (1, 2),
        ];
        for t in 1..=k {
            for i in 0..n {
                for j in 0..n {
                    for (x, y) in &way {
                        if 0 <= i + x && i + x < n && 0 <= j + y && j + y < n {
                            dp[t as usize][i as usize][j as usize] +=
                                dp[t as usize - 1][(i + x) as usize][(j + y) as usize];
                        }
                    }
                    dp[t as usize][i as usize][j as usize] /= 8f64;
                }
            }
        }
        dp[k as usize][row as usize][column as usize]
    }
}
// @lc code=end

/*
// @lcpr case=start
// 8\n30\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// 1\n0\n0\n0\n
// @lcpr case=end

 */
