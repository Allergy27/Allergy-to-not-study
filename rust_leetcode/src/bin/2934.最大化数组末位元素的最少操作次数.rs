/*
 * @lc app=leetcode.cn id=2934 lang=rust
 * @lcpr version=20004
 *
 * [2934] 最大化数组末位元素的最少操作次数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_operations(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let n = nums1.len();
        let a = nums1[n - 1];
        let b = nums2[n - 1];
        let mut ans = 1e9 as i32;
        let mut tmp1 = 0;
        let mut tmp2 = 1;
        for i in (0..n - 1).rev() {
            if nums1[i] > a && nums1[i] > b
                || nums2[i] > a && nums2[i] > b
                || nums1[i] > a && nums2[i] > a
                || nums1[i] > b && nums2[i] > b
            {
                return -1;
            }
            if nums1[i] > a && nums2[i] > a {
                tmp1 = ans;
            } else if nums1[i] > a && nums2[i] <= a || nums2[i] > b && nums1[i] <= b {
                tmp1 += 1;
            }
            if nums1[i] > b && nums2[i] > b {
                tmp2 = ans;
            } else if nums1[i] > b && nums2[i] <= b || nums2[i] > a && nums1[i] <= a {
                tmp2 += 1;
            }
        }
        ans = ans.min(tmp1).min(tmp2);
        return if ans >= 1e9 as i32 { -1 } else { ans };
    }
}
// @lc code=end
