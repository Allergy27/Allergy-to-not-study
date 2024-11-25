/*
 * @lc app=leetcode.cn id=3243 lang=rust
 * @lcpr version=20003
 *
 * [3243] 新增道路查询后的最短距离 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let mut qwq = vec![Vec::new(); n];
        for i in 0..n - 1 {
            qwq[i].push((0, i + 1));
        }
        let mut ans = vec![n as i32; queries.len()];
        let lim = queries.len();
        for (i, query) in queries.into_iter().enumerate() {
            qwq[query[0] as usize].push((i, query[1] as usize));
        }
        let mut que = std::collections::VecDeque::new();
        que.push_back((0, 0, 0));

        let mut tmp = n;

        while let Some((x, w, t)) = que.pop_front() {
            if x == n - 1 {
                for p in t..lim {
                    ans[t] = w;
                }
                if t == 0 {
                    break;
                }
                tmp = t;
            } else {
                for (i, y) in &qwq[x] {
                    if *y > x {
                        //该道路出现时间更早就无脑选
                        if *i <= t {
                            que.push_back((*y, w + 1, t));
                        }
                        //tmp代表已经更新出最大值的
                        if *i > t && *i <= tmp {
                            que.push_back((*y, w + 1, *i));
                        }
                    }
                }
            }
        }

        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// 5\n[[2, 4], [0, 2], [0, 4]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0, 3], [0, 2]]\n
// @lcpr case=end

 */
