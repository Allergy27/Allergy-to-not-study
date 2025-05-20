/*
 * @lc app=leetcode.cn id=2900 lang=rust
 * @lcpr version=30201
 *
 * [2900] 最长相邻不相等子序列 I
 */

// @lc code=start
impl Solution {
    pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        let n = groups.len();
        let mut flag = groups[0];
        let mut ans = vec![words[0].clone()];
        for i in 1..n {
            if flag ^ groups[i] == 1 {
                ans.push(words[i].clone());
                flag ^= 1;
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// ["e","a","b"]\n[0,0,1]\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","c","d"]\n[1,0,1,1]\n
// @lcpr case=end

 */
