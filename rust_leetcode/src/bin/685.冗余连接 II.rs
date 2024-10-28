/*
 * @lc app=leetcode.cn id=685 lang=rust
 * @lcpr version=20002
 *
 * [685] 冗余连接 II
 *
 * https://leetcode.cn/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (42.30%)
 * Likes:    426
 * Dislikes: 0
 * Total Accepted:    40K
 * Total Submissions: 93.6K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 在本问题中，有根树指满足以下条件的 有向
 * 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。
 *
 * 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n
 * 中的两个不同顶点间，这条附加的边不属于树中已存在的边。
 *
 * 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是
 * vi 的一个父节点。
 *
 * 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：edges = [[1,2],[1,3],[2,3]]
 * 输出：[2,3]
 *
 *
 * 示例 2：
 *
 * 输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * 输出：[4,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ui, vi <= n
 *
 *
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
struct UFset {
    fa: Vec<i32>,
    sz: Vec<i32>,
}
impl UFset {
    fn new(n: usize) -> Self {
        UFset {
            fa: (0..=(n as i32)).collect(),
            sz: vec![1; n + 1],
        }
    }
    fn find(&mut self, x: i32) -> i32 {
        if self.fa[x as usize] != x {
            self.fa[x as usize] = self.find(self.fa[x as usize]);
        }
        self.fa[x as usize]
    }
    fn merge(&mut self, x: i32, y: i32) {
        let fx = self.find(x);
        let fy = self.find(y);
        if fx == fy {
            return;
        }
        self.fa[fy as usize] = fx;
        self.sz[fx as usize] += self.sz[fy as usize];
    }
}

impl Solution {
    pub fn find_redundant_directed_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let n = edges.len();
        let mut uf = UFset::new(n);
        let mut conflict = None;
        let mut cycle = None;
        let defaul = edges[0].clone();
        let mut parent = (0..=n as i32).collect::<Vec<_>>();
        for arr in edges {
            let (u, v) = (arr[0], arr[1]);
            if parent[v as usize] != v {
                conflict = Some(arr);
            } else {
                parent[v as usize] = u;
                if uf.find(u) == uf.find(v) {
                    cycle = Some(arr);
                } else {
                    uf.merge(u, v);
                }
            }
        }
        if conflict.is_none() {
            cycle.unwrap_or(defaul)
        } else if cycle.is_some() {
            let v = conflict.unwrap()[1];
            vec![parent[v as usize], v]
        } else {
            conflict.unwrap()
        }
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[2,1],[3,1],[1,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,1],[1,5]]\n
// @lcpr case=end

 */
