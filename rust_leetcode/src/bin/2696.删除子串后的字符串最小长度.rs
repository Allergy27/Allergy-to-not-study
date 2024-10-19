/*
 * @lc app=leetcode.cn id=2696 lang=rust
 *
 * [2696] 删除子串后的字符串最小长度
 */

// @lc code=start
impl Solution {
    pub fn min_length(s: String) -> i32 {
        let mut stack = vec!['V'];
        for i in s.chars() {
            if i == 'B' && stack.last() == Some(&'A') {
                stack.pop()
            } else if i == 'D' && stack.last() == Some(&'C') {
                stack.pop()
            } else {
                stack.push(i)
            }
        }
        stack.len() as i32 - 1
    }
}
// @lc code=end
