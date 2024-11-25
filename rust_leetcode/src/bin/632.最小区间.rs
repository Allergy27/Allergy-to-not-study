/*
 * @lc app=leetcode.cn id=632 lang=rust
 * @lcpr version=20003
 *
 * [632] 最小区间
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn smallest_range(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut qwq = Vec::new();
        for (i, elem) in nums.iter().enumerate() {
            for x in elem {
                qwq.push((*x, i));
            }
        }
        qwq.sort_unstable_by(|x, y| x.0.cmp(&y.0));
        // println!("{:?}", qwq);
        let mut r = 0;
        let mut l = 0;
        let n = qwq.len();
        let m = nums.len();
        let mut cnt = std::collections::HashMap::new();
        cnt.insert(qwq[0].1, 1);
        let mut ans = (0, i32::MAX);
        while r < n {
            while cnt.len() < m {
                r += 1;
                if r == n {
                    break;
                }
                *cnt.entry(qwq[r].1).or_insert(0) += 1;
            }
            if cnt.len() != m {
                break;
            }
            while cnt.len() == m {
                if ans.1 - ans.0 > qwq[r].0 - qwq[l].0 {
                    ans.0 = qwq[l].0;
                    ans.1 = qwq[r].0;
                }
                *cnt.entry(qwq[l].1).or_insert(0) -= 1;
                if cnt[&qwq[l].1] == 0 {
                    cnt.remove(&qwq[l].1);
                }
                l += 1;
            }
        }
        vec![ans.0, ans.1]
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[1,2,3],[1,2,3]]\n
// @lcpr case=end

 */
