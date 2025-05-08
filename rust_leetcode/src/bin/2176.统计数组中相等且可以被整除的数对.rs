/*
 * @lc app=leetcode.cn id=2176 lang=rust
 * @lcpr version=30104
 *
 * [2176] 统计数组中相等且可以被整除的数对
 */

// @lc code=start
impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        for i in 0..n {
            for j in i + 1..n {
                if nums[i] == nums[j] && i as i32 * j as i32 % k == 0 {
                    ans += 1;
                }
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [3,1,2,2,2,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n1\n
// @lcpr case=end

 */
