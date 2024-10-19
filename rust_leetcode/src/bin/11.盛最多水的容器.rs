/*
 * @lc app=leetcode.cn id=11 lang=rust
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut l,mut r) =(0,height.len()-1);
        let mut ans=height[l].min(height[r])*(r-l) as i32;
        while l<r{
            if height[l]<height[r]{
                l+=1
            }else {
                r-=1
            }
            ans=ans.max(height[l].min(height[r])*(r-l) as i32);
        }
        ans
    }
}
// @lc code=end

