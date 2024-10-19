/*
 * @lc app=leetcode.cn id=1456 lang=rust
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
impl Solution {
    pub fn max_vowels(s: String, k: i32) -> i32 {
        let mut ans: i32;
        let s = s.as_bytes();
        let n = s.len();
        let cot = |x: char| match s[i] {
            'a' | 'e' | 'i' | 'o' | 'u' => 1,
            _ => 0,
        };
        for i in 0..k {
            ans += cot(s[i]);
        }
        let mut now = ans;
        for i in k..n {
            now += cot(s[i]) - cot(s[i - k]);
            ans = ans.max(now);
        }
        ans
    }
}
// @lc code=end
