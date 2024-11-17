/*
 * @lc app=leetcode.cn id=825 lang=rust
 * @lcpr version=20003
 *
 * [825] 适龄的朋友
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn num_friend_requests(ages: Vec<i32>) -> i32 {
        let n = ages.len();
        let mut ans = 0;
        for (skip, x) in ages.iter().enumerate() {
            for y in ages.iter().skip(skip + 1) {
                // println!("{:?}", ages.iter().skip(skip + 1).collect::<Vec<_>>());
                if !(2 * y - 14 <= *x || y > x || (*y > 100 && *x < 100)) {
                    ans += 1
                }
                if !(2 * x - 14 <= *y || x > y || (*x > 100 && *y < 100)) {
                    ans += 1
                }
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [16,16]\n
// @lcpr case=end

// @lcpr case=start
// [16,17,18]\n
// @lcpr case=end

// @lcpr case=start
// [20,30,100,110,120]\n
// @lcpr case=end

 */
