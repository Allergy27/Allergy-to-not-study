fn main(){

}
struct Solution;
impl Solution {
    pub fn max_increasing_subarrays(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![1; n];
        for i in 1..n {
            if nums[i] > nums[i - 1] {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }

        let mut ans = *dp.iter().max().unwrap() / 2;
        let mut res = Vec::new();
        for i in 0..n {
            if i == n - 1 || dp[i] > dp[i + 1] {
                res.push(dp[i]);
            }
        }
        for i in 1..res.len() {
            ans = ans.max(res[i].min(res[i - 1]))
        }
        ans
    }
}

