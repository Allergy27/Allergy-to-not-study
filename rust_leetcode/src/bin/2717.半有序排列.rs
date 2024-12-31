/*
 * @lc app=leetcode.cn id=2717 lang=rust
 * @lcpr version=20004
 *
 * [2717] 半有序排列
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn semi_ordered_permutation(nums: Vec<i32>) -> i32 {
        let mut mx = 0;
        let mut mx_idx = 0;
        let mut idx = 0;
        let mut cnt = 0;
        for (i, x) in nums.iter().enumerate() {
            if *x > mx {
                mx = *x;
                mx_idx = i;
                if cnt == 1 {
                    cnt = 0;
                }
            }
            if *x == 1 {
                idx = i;
                cnt = 1;
            }
        }
        mx - 1 + (idx - mx_idx - cnt) as i32
    }
}
// @lc code=end

/*
// @lcpr case=start
// [2,1,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,4,2,5]\n
// @lcpr case=end

 */
