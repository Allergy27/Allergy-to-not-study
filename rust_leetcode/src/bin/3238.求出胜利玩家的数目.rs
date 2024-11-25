/*
 * @lc app=leetcode.cn id=3238 lang=rust
 * @lcpr version=20003
 *
 * [3238] 求出胜利玩家的数目
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn winning_player_count(n: i32, pick: Vec<Vec<i32>>) -> i32 {
        let mut qwq = vec![([0; 11], false); n as usize];
        pick.into_iter().fold(0, |ans, pi| {
            let (x, y) = (pi[0] as usize, pi[1] as usize);
            qwq[x].0[y] += 1;
            ans + if !qwq[x].1 && qwq[x].0[y] == x + 1 {
                qwq[x].1 = true;
                1
            } else {
                0
            }
        })
    }
}
// @lc code=end

/*
// @lcpr case=start
// 4\n[[0,0],[1,0],[1,0],[2,1],[2,1],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,1],[1,2],[1,3],[1,4]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,1],[2,4],[2,4],[2,4]]\n
// @lcpr case=end

 */
