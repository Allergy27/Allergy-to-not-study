/*
 * @lc app=leetcode.cn id=3184 lang=rust
 * @lcpr version=20002
 *
 * [3184] 构成整天的下标对数目 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn count_complete_day_pairs(hours: Vec<i32>) -> i32 {
        let mut qwq = [0; 24];
        let mut ans = 0;
        hours.into_iter().for_each(|x| {
            ans += qwq[((24 - x % 24) % 24) as usize];
            qwq[(x % 24) as usize] += 1;
        });
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [12,12,30,24,24]\n
// @lcpr case=end

// @lcpr case=start
// [72,48,24,3]\n
// @lcpr case=end

 */
