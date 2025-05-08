/*
 * @lc app=leetcode.cn id=2364 lang=rust
 * @lcpr version=30104
 *
 * [2364] 统计坏数对的数目
 */

// @lc code=start
impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut qwq: std::collections::HashMap<i64, i64> = std::collections::HashMap::new();
        let n = nums.len();
        let mut ans = n as i64 * (n as i64 - 1) / 2;
        for i in 0..n {
            let t = nums[i] as i64 - i as i64;
            ans -= qwq[&t];
            *qwq.entry(t).or_insert(0) += 1;
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [4,1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */
