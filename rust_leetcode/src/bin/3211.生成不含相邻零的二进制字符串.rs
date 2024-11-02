/*
 * @lc app=leetcode.cn id=3211 lang=rust
 * @lcpr version=20002
 *
 * [3211] 生成不含相邻零的二进制字符串
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn valid_strings(n: i32) -> Vec<String> {
        let mut mask = (1 << n) - 1;
        (0..=1 << n)
            .filter(|&x| (x ^ mask) & ((x ^ mask) >> 1) == 0)
            .map(|x| format!("{:0width$b}", x, width = n as usize))
            .collect()
    }
}
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
