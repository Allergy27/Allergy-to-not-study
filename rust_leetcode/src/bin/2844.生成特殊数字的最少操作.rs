/*
 * @lc app=leetcode.cn id=2844 lang=rust
 *
 * [2844] 生成特殊数字的最少操作
 */

// @lc code=start
impl Solution {
    pub fn minimum_operations(num: String) -> i32 {
        let n = num.len() as i32;
        let (mut find_zero, mut find_five) = (false, false);
        for (i, x) in num.bytes().enumerate().rev() {
            if find_five && (x == b'2' || x == b'7') || find_zero && (x == b'0' || x == b'5') {
                return n - i as i32 - 2;
            }
            if x == b'0' {
                find_zero = true;
            }
            if x == b'5' {
                find_five = true;
            }
        }
        return if find_zero { n - 1 } else { n };
    }
}
// @lc code=end
