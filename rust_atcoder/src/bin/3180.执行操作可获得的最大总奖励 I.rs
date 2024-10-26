/*
 * @lc app=leetcode.cn id=3180 lang=rust
 * @lcpr version=20002
 *
 * [3180] 执行操作可获得的最大总奖励 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
use std::ops::{BitOrAssign, Shl, Shr};
impl Solution {
    pub fn max_total_reward(reward_values: Vec<i32>) -> i32 {
        // 排序并去重
        let reward_values = std::collections::BTreeSet::from_iter(reward_values.into_iter());
        // 使用一个Vec<u64>来模拟一个足够大的bitset
        let bitset_size = 100000;
        let mut f = BitSet::new(bitset_size);
        f.set(0); // 初始化第0位为1
        for &v in &reward_values {
            let mut shift = bitset_size - v as usize;
            f |= (f.clone() << shift) >> (shift - v as usize);
        }
        // 查找最后一个为1的比特位，即f中最大的索引
        let len = (*reward_values.iter().next_back().unwrap() * 2) as usize;
        for i in (0..len).rev() {
            if f.is_set(i) {
                return i as i32;
            }
        }

        0 // 找不到时返回0
    }
}

#[derive(Clone, Debug)]
pub struct BitSet {
    bits: Vec<bool>,
}

impl BitSet {
    /// 创建一个新的 BitSet，指定容量（位数）
    pub fn new(size: usize) -> Self {
        BitSet {
            bits: vec![false; size],
        }
    }

    /// 设置指定位置的位为1
    pub fn set(&mut self, pos: usize) {
        if pos < self.bits.len() {
            self.bits[pos] = true;
        }
    }

    /// 检查指定位置的位是否为1
    pub fn is_set(&self, pos: usize) -> bool {
        if pos < self.bits.len() {
            self.bits[pos]
        } else {
            false
        }
    }
}

// 实现按位或赋值运算符 |=
impl BitOrAssign for BitSet {
    fn bitor_assign(&mut self, rhs: Self) {
        let len = self.bits.len().min(rhs.bits.len());
        for i in 0..len {
            self.bits[i] |= rhs.bits[i];
        }
    }
}

// 实现左移运算符 <<
impl Shl<usize> for BitSet {
    type Output = Self;

    fn shl(mut self, shift: usize) -> Self::Output {
        let len = self.bits.len();
        if shift >= len {
            self.bits.fill(false);
        } else {
            // 左移操作，填充低位
            for i in (shift..len).rev() {
                self.bits[i] = self.bits[i - shift];
            }
            for i in 0..shift {
                self.bits[i] = false;
            }
        }
        self
    }
}

// 实现右移运算符 >>
impl Shr<usize> for BitSet {
    type Output = Self;

    fn shr(mut self, shift: usize) -> Self::Output {
        let len = self.bits.len();
        if shift >= len {
            self.bits.fill(false);
        } else {
            // 右移操作，填充高位
            for i in 0..(len - shift) {
                self.bits[i] = self.bits[i + shift];
            }
            for i in (len - shift)..len {
                self.bits[i] = false;
            }
        }
        self
    }
}

// @lc code=end

/*
// @lcpr case=start
// [12,19]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,3,20]\n
// @lcpr case=end

 */
