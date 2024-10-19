/*
 * @lc app=leetcode.cn id=2956 lang=rust
 *
 * [2956] 找到两个数组中的公共元素
 */

// @lc code=start
impl Solution {
    pub fn find_intersection_values(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut ans_1 = std::collections::HashSet::<i32>::new();
        let mut ans_2 = std::collections::HashSet::<i32>::new();
        nums1.iter().for_each(|&x| {
            ans_1.insert(x);
        });
        nums2.iter().for_each(|&x| {
            ans_2.insert(x);
        });
        vec![
            nums1
                .iter()
                .fold(0, |ans, x| ans + ans_2.contains(x) as i32),
            nums2
                .iter()
                .fold(0, |ans, x| ans + ans_1.contains(x) as i32),
        ]
    }
}
// @lc code=end
