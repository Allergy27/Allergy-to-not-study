/*
 * @lc app=leetcode.cn id=743 lang=rust
 * @lcpr version=20003
 *
 * [743] 网络延迟时间
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn network_delay_time(times: Vec<Vec<i32>>, n: i32, k: i32) -> i32 {
        let mut qwq = vec![Vec::new(); n as usize];
        for edge in times {
            let (u, v, w) = (edge[0] as usize - 1, edge[1] as usize - 1, edge[2]);
            qwq[u].push((v, w));
        }
        let bfs = || {
            let mut que = std::collections::VecDeque::new();
            que.push_back((k as usize - 1, 0));
            let mut ck = vec![i32::MAX; n as usize];
            ck[k as usize - 1] = 0;
            while let Some((fa, t)) = que.pop_front() {
                for (x, y) in &qwq[fa] {
                    if ck[*x] > t + y {
                        ck[*x] = t + y;
                        que.push_back((*x, t + y))
                    }
                }
            }
            for x in &ck {
                if *x == i32::MAX {
                    return -1;
                }
            }
            return ck.into_iter().max().unwrap();
        };
        bfs()
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[2,1,1],[2,3,1],[3,4,1]]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n2\n
// @lcpr case=end

 */
