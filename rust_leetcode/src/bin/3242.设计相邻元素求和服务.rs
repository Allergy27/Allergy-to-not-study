/*
 * @lc app=leetcode.cn id=3242 lang=rust
 * @lcpr version=20003
 *
 * [3242] 设计相邻元素求和服务
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
struct NeighborSum {
    adj_sum: Vec<i32>,
    dia_sum: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NeighborSum {
    fn new(grid: Vec<Vec<i32>>) -> Self {
        let n = grid.len();
        let mut adj_sum = vec![0; n * n];
        let mut dia_sum = vec![0; n * n];
        const WAY_WH: [(i32, i32); 4] = [(0, 1), (0, -1), (-1, 0), (1, 0)];
        const WAY_XY: [(i32, i32); 4] = [(1, 1), (1, -1), (-1, 1), (-1, -1)];
        for i in 0..n {
            for j in 0..n {
                adj_sum[grid[i][j] as usize] = WAY_WH.iter().fold(0, |sum, (dx, dy)| {
                    let nx = i as i32 + dx;
                    let ny = j as i32 + dy;
                    if nx >= 0 && nx < n as i32 && ny >= 0 && ny < n as i32 {
                        sum + grid[nx as usize][ny as usize]
                    } else {
                        sum
                    }
                });
                dia_sum[grid[i][j] as usize] = WAY_XY.iter().fold(0, |sum, (dx, dy)| {
                    let nx = i as i32 + dx;
                    let ny = j as i32 + dy;
                    if nx >= 0 && nx < n as i32 && ny >= 0 && ny < n as i32 {
                        sum + grid[nx as usize][ny as usize]
                    } else {
                        sum
                    }
                });
            }
        }
        NeighborSum { adj_sum, dia_sum }
    }

    fn adjacent_sum(&self, value: i32) -> i32 {
        self.adj_sum[value]
    }

    fn diagonal_sum(&self, value: i32) -> i32 {
        self.dia_sum[value]
    }
}

// Your NeighborSum object will be instantiated and called as such:
// let obj = NeighborSum::new(grid);
// let ret_1: i32 = obj.adjacent_sum(value);
// let ret_2: i32 = obj.diagonal_sum(value);
// @lc code=end

/*
// @lcpr case=start
// ["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"][[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]\n
// @lcpr case=end

// @lcpr case=start
// ["neighborSum", "adjacentSum", "diagonalSum"][[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]]], [15], [9]]\n
// @lcpr case=end

 */
