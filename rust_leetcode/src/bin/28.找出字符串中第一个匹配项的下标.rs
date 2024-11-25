/*
 * @lc app=leetcode.cn id=28 lang=rust
 * @lcpr version=20003
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn str_str(main: String, patten: String) -> i32 {
        let (n, m) = (main.len(), patten.len());
        let s = (patten + "#" + &main).chars().collect::<Vec<_>>();
        let lim = s.len();
        let mut pi = vec![0; lim];
        for i in 1..lim {
            let mut len = pi[i - 1];
            while len > 0 && s[i] != s[len] {
                len = pi[len - 1];
            }
            if s[i] == s[len] {
                pi[i] = len + 1;
                if pi[i] == m {
                    return (i - m * 2) as i32;
                }
            }
        }
        -1
    }
}
// @lc code=end

/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */
