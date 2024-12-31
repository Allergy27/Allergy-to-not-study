/*
 * @lc app=leetcode.cn id=1366 lang=rust
 * @lcpr version=20004
 *
 * [1366] 通过投票对团队排名
 */

// @lcpr-template-start

use std::fmt::format;

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn rank_teams(votes: Vec<String>) -> String {
        let mut team: std::collections::BTreeMap<char, std::collections::BTreeMap<usize, i32>> =
            std::collections::BTreeMap::new();
        let mut point = votes[0].len();
        for str in votes {
            for (i, x) in str.chars().enumerate() {
                *team.entry(x).entry(i) += 1;
            }
        }
        team.keys().collect::<String>()
    }
}
// @lc code=end

/*
// @lcpr case=start
// ["ABC","ACB","ABC","ACB","ACB"]\n
// @lcpr case=end

// @lcpr case=start
// ["WXYZ","XYZW"]\n
// @lcpr case=end

// @lcpr case=start
// ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]\n
// @lcpr case=end

 */
