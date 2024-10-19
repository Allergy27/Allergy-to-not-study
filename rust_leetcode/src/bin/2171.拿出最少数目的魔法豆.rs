/*
 * @lc app=leetcode.cn id=2171 lang=rust
 *
 * [2171] 拿出最少数目的魔法豆
 */

// @lc code=start
impl Solution {
    pub fn minimum_removal(mut beans: Vec<i32>) -> i64 {
        let n = beans.len();
        beans.sort_unstable();
        let tot = beans.iter().sum();
        beans.iter().enumerate().fold(tot, |ans, (i, &x)|ans.min(tot - beans[i] as i64 * (n - i) as i64))
    }
}
// @lc code=end
