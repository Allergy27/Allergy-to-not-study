/*
 * @lc app=leetcode.cn id=2799 lang=rust
 * @lcpr version=30104
 *
 * [2799] 统计完全子数组的数目
 */

// @lc code=start

impl Solution {
    pub fn count_complete_subarrays(nums: Vec<i32>) -> i32 {
        let k = std::collections::HashSet::from_iter(nums.iter()).len();
        let mut cnt = std::collections::HashMap::new();
        let mut ans = 0;
        let mut left = 0;
        for &x in &nums {
            *cnt.entry(x).or_insert(0) += 1;
            while cnt.len() == k {
                let tmp = nums[left];
                let e = cnt.get_mut(&tmp).unwrap();
                *e -= 1;
                if *e == 0 {
                    cnt.remove(&tmp);
                }
                left += 1;
            }
            ans += left;
        }
        ans as _
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,3,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */
