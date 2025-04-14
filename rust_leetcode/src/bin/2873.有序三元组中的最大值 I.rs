/*
 * @lc app=leetcode.cn id=2873 lang=rust
 * @lcpr version=30104
 *
 * [2873] 有序三元组中的最大值 I
 */

// @lc code=start
impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut pre_max = 0;
        let mut diff = 0;
        let mut ans = 0;
        for x in nums {
            ans = ans.max(diff as i64 * x as i64);
            diff = diff.max(pre_max - x);
            pre_max = pre_max.max(x);
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [12,6,1,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,3,4,19]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
