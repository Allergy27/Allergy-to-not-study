/*
 * @lc app=leetcode.cn id=2179 lang=rust
 * @lcpr version=30104
 *
 * [2179] 统计数组中好三元组数目
 */

// @lc code=start
impl Solution {
    pub fn good_triplets(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let n = nums2.len();
        let mut qwq = vec![0; n];
        for i in 0..n {
            qwq[nums2[i] as usize] = i as i64;
        }
        let mut qvq = vec![0i64; n + 1];
        let mut update = |qvq: &mut Vec<i64>, i: i64, x: i64| {
            let mut r = i;
            while (r as usize) < n {
                qvq[r as usize] += x;
                r += r & (-r);
            }
        };
        let query = |qvq: &Vec<i64>, i: i64| {
            let mut ans = 0;
            let mut r = i;
            while r > 0 {
                ans += qvq[r as usize];
                r -= r & (-r);
            }
            ans
        };
        let mut ans = 0i64;
        for i in 0..n {
            let mut y = qwq[nums1[i] as usize];
            let low = query(&qvq, y);
            ans += low * (n as i64 - 1 - y - (i as i64 - low));
            update(&mut qvq, y + 1, 1);
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [2,0,1,3]\n[0,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,0,1,3,2]\n[4,1,0,2,3]\n
// @lcpr case=end

 */
