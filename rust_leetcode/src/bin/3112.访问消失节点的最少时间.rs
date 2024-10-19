/*
 * @lc app=leetcode.cn id=3112 lang=rust
 *
 * [3112] 访问消失节点的最少时间
 */

// @lc code=start
impl Solution {
    pub fn minimum_time(n: i32, edges: Vec<Vec<i32>>, disappear: Vec<i32>) -> Vec<i32> {
        let n = n as usize;
        let mut qwq = vec![vec![]; n];
        for e in edges {
            let (x, y, z) = (e[0] as usize, e[1] as usize, e[2]);
            qwq[x].push((y, z));
            qwq[y].push((x, z));
        }

        let mut dis = vec![i32::MAX; n];
        let mut qaq = std::collections::BinaryHeap::with_capacity(edges.len());
        qaq.push((0, 0));
        dis[0] = 0;
        while let Some((dx, x)) = qaq.pop() {
            if -dx > dis[x] {
                //x已经出栈过
                continue;
            }
            for &(y, d) in &qwq[x] {
                let new_dis = -dx + d;
                if new_dis < disappear[y] && (dis[y] < 0 || new_dis < dis[y]) {
                    dis[y] = new_dis; //更新x的邻居的最短路
                    qaq.push((-new_dis, y))
                }
            }
        }
        dis
    }
}
// @lc code=end
