/*
 * @lc app=leetcode.cn id=2645 lang=rust
 *
 * [2645] 构造有效字符串的最少插入数
 */

// @lc code=start
impl Solution {
    pub fn add_minimum(word: String) -> i32 {
        let s = word.as_bytes();
        let t = (1..s.len()).fold(0, |x, i| x + if s[i - 1] >= s[i] { 1 } else { 0 });
        return t * 3 - s.len() as i32;
    }
}
// @lc code=end
