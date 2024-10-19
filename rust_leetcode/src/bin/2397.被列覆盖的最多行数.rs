/*
 * @lc app=leetcode.cn id=2397 lang=rust
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
impl Solution {
    pub fn maximum_rows(matrix: Vec<Vec<i32>>, num_select: i32) -> i32 {
        let (m, n) = (matrix.len(), matrix[0].len());
        let mark = matrix.iter().scan(0, |x, y| {
            Some(y.iter().enumerate().fold(0, |s, (i, &r)| s | (r << i)))
        });
        //也可以这么写：
        // let mark = Vec::new();
        // for i in (0..m) {
        //     for j in (0..n) {
        //         mark[i] |= matrix[i][j] << j;
        //     }
        // }
        let mut ans = 0;
        let mut select = (1 << num_select) - 1;
        while select < (1 << n) {
            ans = ans.max(mark.fold(0, |x, y| x + if (y & select) == y { 1 } else { 0 }));
            let lb = select & -select;
            let x = select + lb;
            select = ((select ^ x) / lb >> 2) | x;
        }
        ans
    }
}
// @lc code=end
