/*
 * @lc app=leetcode.cn id=3175 lang=rust
 * @lcpr version=20002
 *
 * [3175] 找到连续赢 K 场比赛的第一位玩家
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_winning_player(skills: Vec<i32>, k: i32) -> i32 {
        let mut ans = 0;
        let mut cnt = 0;

        for (i, &x) in skills.iter().enumerate().skip(1) {
            if skills[ans] > x {
                cnt += 1;
            } else {
                cnt = 1;
                ans = i;
            }
            if cnt == k {
                break;
            }
        }

        ans as i32
    }
}
// @lc code=end

/*
// @lcpr case=start
// [4,2,6,3,9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,5,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [8,9,7,19,11]\n3\n
// @lcpr case=end
 */
