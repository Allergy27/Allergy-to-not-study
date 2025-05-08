/*
 * @lc app=leetcode.cn id=2563 lang=rust
 * @lcpr version=30104
 *
 * [2563] 统计公平数对的数目
 */

// @lc code=start
impl Solution {
    pub fn count_fair_pairs(nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        let mut nums = nums;
        let n = nums.len();
        nums.sort_unstable();
        let mut ans = 0;
        let mut l = 0;
        let mut r = n - 1;
        let mut k = n - 1;
        while l < r {
            while r > l && nums[l] + nums[r] > upper {
                r -= 1;
            }
            k = k.max(l + 1);
            while k > l && nums[l] + nums[k] >= lower {
                k -= 1;
            }
            ans += (r - k) as i64;
            l += 1;
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [0,0,0,0,0,0]\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,7,9,2,5]\n11\n11\n
// @lcpr case=end

 */
