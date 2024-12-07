/*
 * @lc app=leetcode.cn id=3208 lang=rust
 * @lcpr version=20003
 *
 * [3208] 交替组 II
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn number_of_alternating_groups(colors: Vec<i32>, k: i32) -> i32 {
        let (n, k) = (colors.len(), k as usize);
        let mut tmp = 0;
        for i in 1..k {
            tmp += colors[i % n] ^ colors[(i - 1) % n]
        }
        let mut ans = (tmp == k as i32 - 1) as i32;
        for i in k..(n + k - 1) {
            tmp -= colors[(i - k + 1) % n] ^ colors[(i - k) % n];
            tmp += colors[i % n] ^ colors[(i - 1) % n];
            ans += (tmp == k as i32 - 1) as i32
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,1,0]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,0,1,0,1]\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,1]\n4\n
// @lcpr case=end

 */
