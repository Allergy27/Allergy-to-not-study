/*
 * @lc app=leetcode.cn id=3127 lang=rust
 *
 * [3127] 构造相同颜色的正方形
 */

// @lc code=start
impl Solution {
    pub fn can_make_square(grid: Vec<Vec<char>>) -> bool {
        [(1, 1), (1, -1), (-1, -1), (-1, 1)]
            .iter()
            .fold(false, |ans, &(x, y)| {
                ans || ((grid[(1 + x) as usize][(1 + y) as usize] == 'W') as i32
                    + (grid[(1 + x) as usize][1] == 'W') as i32
                    + (grid[1][(1 + y) as usize] == 'W') as i32
                    + (grid[1][1] == 'W') as i32)
                    != 2
            })
    }
}
// @lc code=end
