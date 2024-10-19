// @lc code=start
impl Solution {
    pub fn count_ways(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        nums.iter()
            .enumerate()
            .fold((0, nums[0]), |ans, (i, &x)| {
                (ans.0 + if ans.0 < i as i32 + 1 && i as i32 + 1 < x { 1 } else { 0 }, x)
            })
            .0
    }
}
// @lc code=end
