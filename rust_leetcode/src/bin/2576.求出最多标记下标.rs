/*
 * @lc app=leetcode.cn id=2576 lang=rust
 *
 * [2576] 求出最多标记下标
 */

// @lc code=start
impl Solution {
    pub fn max_num_of_marked_indices(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let n = nums.len();
        let mut check = vec![true; n];
        for i in (0..n).rev() {
            if check[i] {
                continue;
            }
            for j in (0..i).rev() {
                if check[j] {
                    continue;
                }
                if nums[j] * 2 <= nums[i] {
                    check[i] = false;
                    check[j] = false;
                }
            }
        }
        check.iter().fold(0, |ans, &x| ans + if x { 1 } else { 0 })
    }
}
// @lc code=end
