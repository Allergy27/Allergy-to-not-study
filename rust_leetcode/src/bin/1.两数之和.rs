/*
 * @lc app=leetcode.cn id=1 lang=rust
 *
 * [1] 两数之和
 */

// @lc code=start
impl Solution {
    pub fn max_score(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut ans = 0;
        for k in 0..n {
            let mut tmp = 0;
            let mut i = 0;
            while i < n {
                if (i == k) {
                    i += 1;
                    continue;
                }
                let mut j = (i + 1).gcd(tmp);
            }
        }
    }
}
// @lc code=end
