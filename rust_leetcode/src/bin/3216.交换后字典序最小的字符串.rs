/*
 * @lc app=leetcode.cn id=3216 lang=rust
 * @lcpr version=20002
 *
 * [3216] 交换后字典序最小的字符串
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn get_smallest_string(s: String) -> String {
        let mut s = s.into_bytes();
        let n = s.len();
        for i in 1..n {
            if ((s[i] & 1) ^ (1 & s[i - 1])) == 0 && s[i] < s[i - 1] {
                s.swap(i, i - 1);
                break;
            }
        }
        s.into_iter().map(|x| x as char).collect()
    }
}
// @lc code=end

/*
// @lcpr case=start
// "20"\n
// @lcpr case=end

// @lcpr case=start
// "001"\n
// @lcpr case=end

 */
