/*
 * @lc app=leetcode.cn id=1154 lang=rust
 *
 * [1154] 一年中的第几天
 */

// @lc code=start
impl Solution {
    pub fn day_of_year(date: String) -> i32 {
        let mut day_count = vec![0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30];
        let (year, month, day) = date
            .split('-')
            .map(|x| x.parse::<usize>().unwrap())
            .collect();
        day_count[2] += if year % 400 == 0 || year % 100 != 0 && year % 4 == 0 {
            1
        } else {
            0
        };
        (0..month).fold(x, |x, y| x + day_count[y]) + day
    }
}
// @lc code=end
