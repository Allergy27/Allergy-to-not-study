/*
 * @lc app=leetcode.cn id=2766 lang=rust
 *
 * [2766] 重新放置石块
 */

// @lc code=start
impl Solution {
    pub fn relocate_marbles(nums: Vec<i32>, move_from: Vec<i32>, move_to: Vec<i32>) -> Vec<i32> {
        let mut qwq = nums.into_iter().collect::<std::collections::HashSet<i32>>();
        move_from.iter().zip(move_to.iter()).for_each(|(x, y)| {
            qwq.remove(x);
            qwq.insert(y);
        });
        let mut ans = qwq.into_iter().collect::<Vec<i32>>();
        ans.sort_unstable();
        ans
    }
}
// @lc code=end
