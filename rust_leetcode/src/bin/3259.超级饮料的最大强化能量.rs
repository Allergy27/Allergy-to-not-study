/*
 * @lc app=leetcode.cn id=3259 lang=rust
 * @lcpr version=20002
 *
 * [3259] 超级饮料的最大强化能量
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn max_energy_boost(a: Vec<i32>, b: Vec<i32>) -> i64 {
        *a.into_iter()
            .map(|x| x as i64)
            .zip(b.into_iter().map(|y| y as i64))
            .fold([0, 0, 0, 0], |[a, pa, b, pb], (x, y)| {
                [a.max(pb) + x, a, b.max(pa) + y, b]
            })
            .iter()
            .max()
            .unwrap()
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,3,1]\n[3,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,1]\n[1,1,3]\n
// @lcpr case=end

 */
