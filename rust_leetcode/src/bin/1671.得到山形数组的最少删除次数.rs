/*
 * @lc app=leetcode.cn id=1671 lang=rust
 *
 * [1671] 得到山形数组的最少删除次数
 */

// @lc code=start
impl Solution {
    pub fn minimum_mountain_removals(nums: Vec<i32>) -> i32 {
        let l = Self::f_find(&nums);
        let r = Self::f_find(&nums.iter().rev().map(|x| *x).collect::<Vec<i32>>());
        nums.len() as i32 + 1
            - l.iter().zip(r.iter().rev()).fold(0, |x, (&y, &z)| {
                if y > 1 && z > 1 {
                    x.max((y + z) as i32)
                } else {
                    x
                }
            })
    }
    fn f_find(nums: &Vec<i32>) -> Vec<usize> {
        nums.iter()
            .fold((vec![], vec![]), |mut x, &y| {
                if x.0.is_empty() || x.0[x.0.len() - 1] < y {
                    x.0.push(y)
                } else {
                    let i = x.0.partition_point(|&v| v < y) as usize;
                    x.0[i] = y
                }
                x.1.push(x.0.len());
                x
            })
            .1
    }
}

// @lc code=end
