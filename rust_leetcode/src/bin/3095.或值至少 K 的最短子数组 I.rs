/*
 * @lc app=leetcode.cn id=3095 lang=rust
 * @lcpr version=20004
 *
 * [3095] 或值至少 K 的最短子数组 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn minimum_subarray_length(mut nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut ans = usize::MAX;
        for i in 0..n {
            let x = nums[i];
            if x > k {
                return 1;
            }
            let mut j = i - 1;
            while j < n && (nums[j] | x) != nums[j] {
                nums[j] |= x;
                if nums[j] >= k {
                    ans = ans.min(i - j + 1);
                }
                j -= 1
            }
        }
        if ans == usize::MAX {
            -1
        } else {
            ans as _
        }
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,1,8]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */
