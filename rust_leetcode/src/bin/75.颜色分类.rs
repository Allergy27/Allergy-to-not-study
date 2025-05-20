/*
 * @lc app=leetcode.cn id=75 lang=rust
 * @lcpr version=30201
 *
 * [75] 颜色分类
 */

// @lc code=start
impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut w = 0;
        let mut b = 0;
        for i in 0..nums.len() {
            if nums[i] == 1 {
                w += 1;
            } else if nums[i] == 2 {
                b += 1;
            }
            nums[i] = 0;
        }
        for i in (0..nums.len()).rev() {
            if b > 0 {
                nums[i] = 2;
                b -= 1
            } else if w > 0 {
                nums[i] = 1;
                w -= 1
            } else {
                break;
            }
        }
    }
}
// @lc code=end

/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,2]\n
// @lcpr case=end

 */
