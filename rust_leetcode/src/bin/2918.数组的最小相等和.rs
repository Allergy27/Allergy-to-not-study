/*
 * @lc app=leetcode.cn id=2918 lang=rust
 * @lcpr version=30201
 *
 * [2918] 数组的最小相等和
 */

// @lc code=start
impl Solution {
    pub fn min_sum(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let mut flag1 = false;
        let mut flag2 = false;
        let mut ans1 = nums1.iter().fold(0i64, |tmp, &x| {
            tmp + if x == 0 {
                flag1 = true;
                1
            } else {
                x as i64
            }
        });
        let mut ans2 = nums2.iter().fold(0i64, |tmp, &x| {
            tmp + if x == 0 {
                flag2 = true;
                1
            } else {
                x as i64
            }
        });
        let mut ans = 0;
        if ((ans1 > ans2) && !flag2) || (ans1 < ans2 && !flag1) {
            -1
        } else {
            ans1.max(ans2)
        }
    }
}
// @lc code=end

/*
// @lcpr case=start
// [3,2,0,1,0]\n[6,5,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,2,0]\n[1,4]\n
// @lcpr case=end

 */
