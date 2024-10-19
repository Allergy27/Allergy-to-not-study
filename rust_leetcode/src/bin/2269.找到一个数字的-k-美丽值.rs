/*
 * @lc app=leetcode.cn id=2269 lang=rust
 *
 * [2269] 找到一个数字的 K 美丽值
 */

// @lc code=start
impl Solution {
    pub fn divisor_substrings(num: i32, k: i32) -> i32 {
        let n = num.to_string().len() as u32;
        let t_pow = |x: u32| 10u32.pow(x);
        (0..n - k).fold(0, |ans, i| {
            let check = ((num % t_pow(k + i + 1)) / t_pow(i)) as i32;
            ans + if check != 0 && num % check == 0 { 1 } else { 0 }
        })
    }
}
// @lc code=end
