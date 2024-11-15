/*
 * @lc app=leetcode.cn id=3239 lang=rust
 * @lcpr version=20003
 *
 * [3239] 最少翻转次数使二进制矩阵回文 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_flips(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid.first().unwrap().len();
        let mut res_row = 0;
        for row in &grid {
            for j in 0..m / 2 {
                res_row += row[j] ^ row[m - 1 - j];
            }
        }
        let mut res_col = 0;
        for i in 0..m {
            for j in 0..n / 2 {
                res_col += grid[j][i] ^ grid[n - 1 - j][i];
            }
        }
        res_col.min(res_row)
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[1,0,0],[0,0,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,0],[1,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[0]]\n
// @lcpr case=end

 */
