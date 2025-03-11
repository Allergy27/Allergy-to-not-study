/*
 * @lc app=leetcode.cn id=2269 lang=rust
 * @lcpr version=30100
 *
 * [2269] 找到一个数字的 K 美丽值
 */

// @lc code=start
impl Solution {
    pub fn divisor_substrings(num: i32, k: i32) -> i32 {
        let n = num.to_string().len() as i32;
        (0..=n - k).fold(0, |ans, i| {
            let tmp = num / 10_i32.pow((n - k - i) as u32) % 10_i32.pow(k as u32);
            ans + (tmp != 0 && num % tmp == 0) as i32
        })
    }
}
// @lc code=end

/*
// @lcpr case=start
// 240\n2\n
// @lcpr case=end

// @lcpr case=start
// 430043\n2\n
// @lcpr case=end

 */
