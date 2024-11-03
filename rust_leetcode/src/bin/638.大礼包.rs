/*
 * @lc app=leetcode.cn id=638 lang=rust
 * @lcpr version=20002
 *
 * [638] 大礼包
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn shopping_offers(price: Vec<i32>, special: Vec<Vec<i32>>, needs: Vec<i32>) -> i32 {
        let m = special.len();
        let n = needs.len();
        let special = special
            .into_iter()
            .filter(|qwq| {
                qwq[0..n].iter().enumerate().map(|(i, &x)| price[i] * x).sum::<i32>() > qwq[n]
            })
            .collect::<Vec<Vec<i32>>>();
        let bfs = || -> i32 {
            let mut ans = (0..n).map(|i| price[i] * needs[i]).sum::<i32>();
            let mut que = std::collections::VecDeque::new();
            que.push_back(vec![0; n + 1]);
            while let Some(tmp) = que.pop_front() {
                for s in special.iter() {
                    let now: Vec<i32> = (0..=n).map(|i| tmp[i] + s[i]).collect();
                    if (0..n).all(|i| now[i] <= needs[i]) {
                        ans = ans.min(
                            (0..n).map(|i| price[i] * (needs[i] - now[i])).sum::<i32>() + now[n],
                        );
                        que.push_back(now);
                    }
                }
            }
            ans
        };
        bfs()
    }
}
// @lc code=end

/*
// @lcpr case=start
// [2,5]\n[[3,0,5],[1,2,10]]\n[3,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[[1,1,0,4],[2,2,1,9]]\n[1,2,1]\n
// @lcpr case=end

 */
