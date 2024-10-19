/*
 * @lc app=leetcode.cn id=15 lang=rust
 *
 * [15] 三数之和
 */

// @lc code=start
impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut qwq = vec![];
        nums.sort_unstable();
        for i in 0..n - 2 {
            if nums[i] + nums[i + 1] + nums[i + 2] > 0 {
                break;
            }
            if !((i > 0 && nums[i] == nums[i - 1]) || nums[i] + nums[n - 2] + nums[n - 1] < 0) {
                let (mut j, mut k) = (i + 1, n - 1);
                while j < k {
                    let sum = nums[i] + nums[j] + nums[k];
                    if sum > 0 {
                        k -= 1;
                    } else if sum < 0 {
                        j += 1;
                    } else {
                        qwq.push(vec![nums[i], nums[j], nums[k]]);
                        j += 1;
                        while j < k && nums[j] == nums[j - 1] {
                            j += 1
                        }
                        k -= 1;
                        while j < k && nums[k] == nums[k + 1] {
                            k -= 1
                        }
                    }
                }
            }
        }
        qwq
    }
}
// @lc code=end
