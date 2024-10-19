/*
 * @lc app=leetcode.cn id=72 lang=rust
 *
 * [72] 编辑距离
 */

// @lc code=start
impl Solution {
    pub fn min_distance(s: String, t: String) -> i32 {
        let n = s.len();
        let m = t.len();
        let mut f = (0..=m).collect::<Vec<_>>();
        for (i, x) in s.chars().enumerate() {
            let mut pre = i+1;
            for (j, y) in t.chars().enumerate() {
                let mut tmp = f[j + 1];
                f[j + 1] = if x == y {
                    pre + 1
                } else {
                    pre.min(f[j]).min(f[j + 1])
                };
                pre = tmp;
            }
        }
        f[m]
    }
}
// @lc code=end
