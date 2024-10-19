/*
 * @lc app=leetcode.cn id=4 lang=rust
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
impl Solution {
    pub fn find_median_sorted_arrays(mut nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mid = nums1.len();
        nums1.extend(nums2);
        Self::merge(&mut nums1, mid);
        let mid = nums1.len();
        let (lm, rm) = (mid-1 >> 1, mid >> 1);
        (nums1[lm] + nums1[rm]) as f64 / 2.0
    }
    fn merge(qwq: &mut Vec<i32>, m: usize) {
        //其实不用函数包装也行，主要合并函数写归并排序也要用到，干脆封装了
        let v = qwq.clone();
        let (mut l, mut r, n) = (0, m, v.len());
        for i in 0..n {
            if l != m && (r == n || v[l] < v[r]) {
                qwq[i] = v[l];
                l += 1;
            } else {
                qwq[i] = v[r];
                r += 1;
            }
        }
    }
}
// @lc code=end
