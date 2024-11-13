/*
 * @lc app=leetcode.cn id=3258 lang=rust
 * @lcpr version=20003
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn count_k_constraint_substrings(s: String, k: i32) -> i32 {
        let s = s.chars().collect::<Vec<_>>();
        let n = s.len();
        let mut ans = 0;
        for i in 0..n {
            let mut p = [0, 0];
            for j in i..n {
                p[s[j] as usize - '0' as usize] += 1;
                if p[0] <= k && p[1] <= k {
                    ans += 1;
                }
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// "10101"\n1\n
// @lcpr case=end

// @lcpr case=start
// "1010101"\n2\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n1\n
// @lcpr case=end

 */
