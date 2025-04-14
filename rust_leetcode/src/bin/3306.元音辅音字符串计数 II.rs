/*
 * @lc app=leetcode.cn id=3306 lang=rust
 * @lcpr version=30101
 *
 * [3306] 元音辅音字符串计数 II
 */

// @lc code=start
impl Solution {
    pub fn count_of_substrings(word: String, k: i32) -> i64 {
        let word = word.chars().collect::<Vec<_>>();
        let (mut l, mut r) = (0usize, 1);
        let mut mp =
            std::collections::HashMap::from([('a', 0), ('e', 0), ('i', 0), ('o', 0), ('u', 0)]);
        let mut vow = 0;
        let mut con = 0;
        let mut change = |p: usize, f: i32, vow: &mut i32, con: &mut i32| {
            if let Some(x) = mp.get_mut(&word[p]) {
                if f == 1 && *x == 0 || f == -1 && *x == 1 {
                    *vow += f
                }
                *x += f
            } else {
                *con += f
            }
        };
        change(l, 1, &mut vow, &mut con);
        // println!("{m}");
        let n = word.len();
        let mut ans = 0;
        while r < n {
            change(r, 1, &mut vow, &mut con);
            while l < r && con > k {
                change(l, -1, &mut vow, &mut con);
                l += 1
            }
            if vow == 5 && con == k {
                ans += 1
            }
            r += 1
        }
        while l < r {
            change(l, -1, &mut vow, &mut con);
            l += 1;
            if vow == 5 && con == k {
                ans += 1
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// "aeioqq"\n1\n
// @lcpr case=end

// @lcpr case=start
// "aeiou"\n0\n
// @lcpr case=end

// @lcpr case=start
// "ieaouqqieaouqq"\n1\n
// @lcpr case=end

 */
