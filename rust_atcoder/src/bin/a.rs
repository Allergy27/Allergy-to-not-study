//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/a.rs
//@data      2024/10/25 19:01:50
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
use std::ops::{BitOrAssign, Shl, Shr};
#[derive(Clone, Debug)]
pub struct BitSet {
    bits: Vec<u64>,
}

impl BitSet {
    /// 创建一个新的 BitSet，指定容量（位数）
    pub fn new(size: usize) -> Self {
        let num_words = (size + 63) / 64;
        BitSet {
            bits: vec![0; num_words],
        }
    }

    /// 设置指定位置的位为1
    pub fn set(&mut self, pos: usize) {
        let (word, bit) = (pos / 64, pos % 64);
        self.bits[word] |= 1 << bit;
    }

    /// 检查指定位置的位是否为1
    pub fn is_set(&self, pos: usize) -> bool {
        let (word, bit) = (pos / 64, pos % 64);
        (self.bits[word] & (1 << bit)) != 0
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
        let word_shift = shift / 64;
        let bit_shift = shift % 64;

        // 整个块的左移
        if word_shift > 0 {
            for i in (word_shift..self.bits.len()).rev() {
                self.bits[i] = self.bits[i - word_shift];
            }
            for i in 0..word_shift {
                self.bits[i] = 0;
            }
        }

        // 位内的左移
        if bit_shift > 0 {
            for i in (1..self.bits.len()).rev() {
                self.bits[i] = (self.bits[i] << bit_shift) | (self.bits[i - 1] >> (64 - bit_shift));
            }
            self.bits[0] <<= bit_shift;
        }

        // 清除超出范围的部分
        let total_bits = self.bits.len() * 64;
        if shift < total_bits {
            let valid_bits = total_bits - shift;
            for i in valid_bits..total_bits {
                self.bits[i / 64] &= !(1 << (i % 64));
            }
        }

        self
    }
}

// 实现右移运算符 >>
impl Shr<usize> for BitSet {
    type Output = Self;

    fn shr(mut self, shift: usize) -> Self::Output {
        let word_shift = shift / 64;
        let bit_shift = shift % 64;
        let len = self.bits.len();
        if word_shift > 0 {
            for i in 0..(len - word_shift) {
                self.bits[i] = self.bits[i + word_shift];
            }
            for i in (len - word_shift)..len {
                self.bits[i] = 0;
            }
        }
        if bit_shift > 0 {
            for i in 0..(len - 1) {
                self.bits[i] = (self.bits[i] >> bit_shift) | (self.bits[i + 1] << (64 - bit_shift));
            }
            self.bits[len - 1] >>= bit_shift;
        }
        self
    }
}
fn solve() {
    let mut test = BitSet::new(3);
    test.set(0);
    test.set(1);
    test |= (test.clone() << 2) >> 1;
    println!("{:?}", test);
    let k = cin().parse::<usize>().unwrap();
}
