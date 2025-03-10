/*
 * @lc app=leetcode.cn id=3297 lang=rust
 * @lcpr version=20004
 *
 * [3297] 统计重新排列后包含另一个字符串的子字符串数目 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn valid_substring_count(word1: String, word2: String) -> i64 {
        let n = word1.len();
        let mut l = 0;
        let s = word1.as_bytes();
        let mut diff = [0; 26];
        word2.bytes().for_each(|x| diff[(x - b'a') as usize] += 1);
        let mut m = diff.iter().filter(|x| **x > 0).count() as i32;
        let mut ans = 0;
        for r in s {
            let c = (*r - b'a') as usize;
            diff[c] -= 1;
            if diff[c] == 0 {
                m -= 1
            }
            while m == 0 {
                let tmp = (*s[l] - b'a') as usize;
                if diff[tmp] == 0 {
                    m += 1
                }
                diff[tmp] += 1;
                l += 1;
            }
            ans += l
        }
        ans as _
    }
}
// @lc code=end

/*
// @lcpr case=start
// "bcca"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"aaabc"\n
// @lcpr case=end

 */
