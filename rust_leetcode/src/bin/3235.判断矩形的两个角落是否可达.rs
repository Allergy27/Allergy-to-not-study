/*
 * @lc app=leetcode.cn id=3235 lang=rust
 * @lcpr version=20003
 *
 * [3235] 判断矩形的两个角落是否可达
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

// 判断点 (x, y) 是否在圆 (ox, oy, r) 内
fn in_circle(ox: i64, oy: i64, r: i64, x: i64, y: i64) -> bool {
    (ox - x) * (ox - x) + (oy - y) * (oy - y) <= r * r
}

// 计算点到线段的最小距离平方
fn distance_squared_point_to_segment(px: i64, py: i64, x0: i64, y0: i64, x1: i64, y1: i64) -> i64 {
    let dx = x1 - x0;
    let dy = y1 - y0;
    if dx == 0 && dy == 0 {
        // 线段退化成点
        return (px - x0).pow(2) + (py - y0).pow(2);
    }
    let t = ((px - x0) * dx + (py - y0) * dy) as f64 / (dx * dx + dy * dy) as f64;
    let t = t.max(0.0).min(1.0);
    let proj_x = x0 as f64 + t * dx as f64;
    let proj_y = y0 as f64 + t * dy as f64;
    ((px as f64 - proj_x).powi(2) + (py as f64 - proj_y).powi(2)) as i64
}

// 判断圆是否与矩形的某个边界相交
fn circle_intersects_rectangle(
    cx: i64,
    cy: i64,
    r: i64,
    width: i64,
    height: i64,
) -> [bool; 4] {
    let circle_inside = cx >= 0 && cx <= width && cy >= 0 && cy <= height;
    let r_squared = r * r;

    let mut intersects = [false; 4];

    // 左边界 (0, 0) 到 (0, height)
    let dist_sq = distance_squared_point_to_segment(cx, cy, 0, 0, 0, height);
    if (circle_inside && dist_sq <= r_squared) || (!circle_inside && dist_sq < r_squared) {
        intersects[0] = true;
    }

    // 右边界 (width, 0) 到 (width, height)
    let dist_sq = distance_squared_point_to_segment(cx, cy, width, 0, width, height);
    if (circle_inside && dist_sq <= r_squared) || (!circle_inside && dist_sq < r_squared) {
        intersects[1] = true;
    }

    // 下边界 (0, 0) 到 (width, 0)
    let dist_sq = distance_squared_point_to_segment(cx, cy, 0, 0, width, 0);
    if (circle_inside && dist_sq <= r_squared) || (!circle_inside && dist_sq < r_squared) {
        intersects[2] = true;
    }

    // 上边界 (0, height) 到 (width, height)
    let dist_sq = distance_squared_point_to_segment(cx, cy, 0, height, width, height);
    if (circle_inside && dist_sq <= r_squared) || (!circle_inside && dist_sq < r_squared) {
        intersects[3] = true;
    }

    intersects
}

struct UFset {
    fa: Vec<usize>,
}

impl UFset {
    fn new(n: usize) -> Self {
        UFset {
            fa: (0..=n).collect(),
        }
    }

    fn union(&mut self, n: usize, m: usize) {
        let x = self.find(n);
        let y = self.find(m);
        if x != y {
            self.fa[x] = y;
        }
    }

    fn find(&mut self, n: usize) -> usize {
        if self.fa[n] != n {
            self.fa[n] = self.find(self.fa[n]);
        }
        self.fa[n]
    }
}

impl Solution {
    pub fn can_reach_corner(width: i32, height: i32, circles: Vec<Vec<i32>>) -> bool {
        let mut uf = UFset::new(circles.len() + 4); // 添加4个虚拟节点用于矩形的四个边界
        let width = width as i64;
        let height = height as i64;

        for (i, circle) in circles.iter().enumerate() {
            let (cx, cy, cr) = (circle[0] as i64, circle[1] as i64, circle[2] as i64);

            // 检查圆是否与矩形的各个边界相交
            let intersects = circle_intersects_rectangle(cx, cy, cr, width, height);
            if intersects[0] {
                uf.union(i, circles.len()); // 左边界
            }
            if intersects[1] {
                uf.union(i, circles.len() + 1); // 右边界
            }
            if intersects[2] {
                uf.union(i, circles.len() + 2); // 下边界
            }
            if intersects[3] {
                uf.union(i, circles.len() + 3); // 上边界
            }

            // 检查圆与其他圆是否相交
            for j in 0..i {
                let (jx, jy, jr) = (
                    circles[j][0] as i64,
                    circles[j][1] as i64,
                    circles[j][2] as i64,
                );

                let circles_intersect = (cx - jx).pow(2) + (cy - jy).pow(2) <= (cr + jr).pow(2);

                if circles_intersect {
                    uf.union(i, j);
                } else {
                    let ci_inside_rect = cx >= 0 && cx <= width && cy >= 0 && cy <= height;
                    let cj_inside_rect = jx >= 0 && jx <= width && jy >= 0 && jy <= height;

                    // 如果两个圆的圆心都在矩形外，检查矩形的顶点是否在两个圆内
                    if !ci_inside_rect && !cj_inside_rect {
                        let rectangle_vertices = vec![(0, 0), (0, height), (width, 0), (width, height)];

                        for &(x, y) in &rectangle_vertices {
                            if in_circle(cx, cy, cr, x, y) && in_circle(jx, jy, jr, x, y) {
                                uf.union(i, j);
                                break;
                            }
                        }
                    }
                }
            }
        }

        // 检查是否满足阻碍条件
        if uf.find(circles.len()) == uf.find(circles.len() + 3) // 左下角和右上角连通
            || uf.find(circles.len() + 1) == uf.find(circles.len() + 2) // 右下角和左上角连通
        {
            return false;
        }

        true
    }
}

// @lc code=end

/*
// @lcpr case=start
// 5\n4\n[[5,6,4],[6,4,2],[2,5,4],[3,5,3]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n[[1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n4\n[[2,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n4\n[[5,5,1]]\n
// @lcpr case=end

 */
