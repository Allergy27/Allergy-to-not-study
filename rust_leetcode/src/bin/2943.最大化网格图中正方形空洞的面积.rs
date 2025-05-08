/*
 * @lc app=leetcode.cn id=2943 lang=rust
 * @lcpr version=30104
 *
 * [2943] 最大化网格图中正方形空洞的面积
 */

// @lc code=start
impl Solution {
    pub fn maximize_square_hole_area(
        n: i32,
        m: i32,
        mut h_bars: Vec<i32>,
        mut v_bars: Vec<i32>,
    ) -> i32 {
        let f = |a: &mut Vec<i32>| {
            a.sort();
            let n = a.len();
            let mut i = 0;
            let mut ans = 0;
            while i < n {
                let mut tmp = i;
                i += 1;
                while i < n && a[i] - a[i - 1] == 1 {
                    i += 1
                }
                ans = ans.max(i - tmp)
            }
            ans as i32
        };
        let len = f(&mut h_bars).min(f(&mut v_bars));
        len * len
    }
}
// @lc code=end

/*
// @lcpr case=start
// 2\n1\n[2,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n[2]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n[2,3]\n[2,3,4]\n
// @lcpr case=end

 */
