/*
 * @lc app=leetcode.cn id=3249 lang=rust
 * @lcpr version=20003
 *
 * [3249] 统计好节点的数目
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn count_good_nodes(edges: Vec<Vec<i32>>) -> i32 {
        let n = edges.len() + 1;
        let mut qwq = vec![Vec::new(); n];
        for edge in edges {
            let (x, y) = (edge[0] as usize, edge[1] as usize);
            qwq[x].push(y);
            qwq[y].push(x);
        }
        let mut ans = 0;
        // println!("{:?}",qwq);
        Self::dfs(0, 0, &qwq, &mut ans);
        ans
    }
    fn dfs(i: usize, fa: usize, qwq: &Vec<Vec<usize>>, ans: &mut i32) -> i32 {
        //叶子节点
        if i != 0 && qwq[i].len() == 1 {
            return 1;
        }
        let mut sz = 0;
        let mut tmp = -1;
        let mut ck = 1;
        for u in &qwq[i] {
            if *u != fa {
                sz += Self::dfs(*u, i, qwq, qaq);
                if tmp == -1 {
                    tmp = qaq[*u];
                }
                qaq[i] += qaq[*u];
                if tmp != qaq[*u] {
                    ck = 0;
                }
            }
        }
        ans + ck
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]\n
// @lcpr case=end

 */
