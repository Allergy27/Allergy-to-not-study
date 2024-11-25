/*
 * @lc app=leetcode.cn id=661 lang=rust
 * @lcpr version=20003
 *
 * [661] 图片平滑器
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = img.len();
        let m = img.first().unwrap().len();
        let mut ans = vec![vec![0; m]; n];
        const WAY: [i32; 9] = [-1, -1, 0, 1, 1, 0, -1, 1, -1];
        for i in 0..n {
            for j in 0..m {
                let mut tmp = 0;
                let mut cot = 1;
                for k in 0..8 {
                    let x = i as i32 + WAY[k];
                    let y = j as i32 + WAY[k + 1];
                    if x < 0 || x == n as i32 || y < 0 || y == m as i32 {
                        continue;
                    }
                    tmp += img[x as usize][y as usize];
                    cot += 1;
                }
                ans[i][j] = (tmp + img[i][j]) / cot;
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3,4],[5,6,7],[8,9,10],[11,12,13],[14,15,16]]\n
// @lcpr case=end

 */
