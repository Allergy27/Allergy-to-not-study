//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/class_high.rs
//@data      2024/06/27 12:23:52

use std::{
    cmp::Ordering::{self, Equal, Greater, Less},
    ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Sub, SubAssign},
    vec,
};

// 自定义 Result 类型
pub type Result<T> = std::result::Result<T, CompError>;

// 自定义错误类型
#[derive(Debug, Clone)]
pub enum CompError {
    Parse(String),
}

impl std::error::Error for CompError {}

impl std::fmt::Display for CompError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::Parse(s) => write!(f, "{}", s),
        }
    }
}

#[derive(Clone)]
pub struct BigInt {
    len: usize,
    num: Vec<i32>,
    neg: bool,
}

impl BigInt {
    pub fn new(src: &str) -> Self {
        let src = src.trim(); //去掉前导空格
        let sim = &src[0..1] == "-";
        //去空格并转换成数字
        let mut qwq: Vec<i32> = src
            .chars()
            .rev()
            .filter_map(|x| {
                if x.is_numeric() {
                    Some(x as i32 - 48)
                } else {
                    None
                }
            })
            .collect();
        qwq.push(0);
        BigInt {
            len: qwq.len() - 1,
            num: qwq,
            neg: sim,
        }
    }
    pub fn show(self) {
        print!("{}", if self.neg { "-" } else { "" });
        self.num
            .iter()
            .rev()
            .skip_while(|&&x| x == 0)
            .for_each(|x| print!("{x}"));
        println!()
    }
    pub fn pow(self, n: usize) -> Self {
        (0..n).fold(self.clone(), |ans, _| ans.clone() * ans.clone())
    }
    //变号
    fn change_sim(mut self) -> Self {
        self.neg = !self.neg;
        self
    }
}

//为 BigInt型 添加显示
impl std::fmt::Debug for BigInt {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}{}",
            if self.neg { "-" } else { "" },
            self.num
                .iter()
                .rev()
                .skip(1)
                .map(|x| x.to_string())
                .collect::<String>()
        )
    }
}

impl PartialEq for BigInt {
    fn eq(&self, other: &Self) -> bool {
        self.neg == other.neg && self.num == other.num
    }
}

impl PartialOrd for BigInt {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        if self == other {
            return Some(Equal);
        }
        if self.neg != other.neg {
            if self.neg && !other.neg {
                return Some(Less);
            } else {
                return Some(Greater);
            }
        }
        let ans = match self.len.cmp(&other.len) {
            Less => false ^ self.neg,
            Equal => {
                let mut check = false;
                for i in (0..self.len).rev() {
                    if self.num[i] != other.num[i] {
                        check = self.num[i] > other.num[i];
                        break;
                    }
                }
                check
            }
            Greater => true ^ self.neg,
        };
        if ans {
            Some(Greater)
        } else {
            Some(Less)
        }
    }
}

impl AddAssign for BigInt {
    fn add_assign(&mut self, rhs: Self) {
        *self = self.clone() + rhs;
    }
}

impl Add for BigInt {
    type Output = BigInt;
    fn add(self, others: Self) -> BigInt {
        if self.neg && !others.neg {
            return others - self.change_sim();
        } else if !self.neg && others.neg {
            return self - others.change_sim();
        }
        let (bigger, mut smaller) = if self >= others {
            (self.num, others.num)
        } else {
            (others.num, self.num)
        };
        smaller.resize(bigger.len(), 0);
        let mut res = 0;
        let mut ans: Vec<i32> = bigger
            .iter()
            .zip(smaller.iter())
            .map(|(&x, &y)| {
                let pre = res;
                res = (x + y + res) / 10;
                (x + y + pre) % 10
            })
            .collect();

        if *ans.last().unwrap() != 0 {
            ans.push(0);
        }
        BigInt {
            len: ans.len() - 1,
            num: ans,
            neg: self.neg,
        }
    }
}

impl SubAssign for BigInt {
    fn sub_assign(&mut self, rhs: Self) {
        *self = self.clone() - rhs;
    }
}

impl Sub for BigInt {
    type Output = BigInt;
    fn sub(self, others: Self) -> BigInt {
        if self.neg != others.neg {
            return self + others.change_sim();
        }
        let sim = matches!(self.partial_cmp(&others), Some(Ordering::Less));
        let (bigger, mut smaller) = if self >= others {
            (self.num, others.num)
        } else {
            (others.num, self.num)
        };
        smaller.resize(bigger.len(), 0);
        let mut res = 0;
        let mut ans: Vec<i32> = bigger
            .iter()
            .zip(smaller.iter())
            .map(|(&x, &y)| {
                let pre = res;
                res = if x - res < y { 1 } else { 0 };
                x + 10 * res - y - pre
            })
            .collect();

        let mut new_len = ans.len();
        while new_len > 1 && ans[new_len - 1] == 0 {
            new_len -= 1;
            ans.pop();
        }
        ans.push(0);
        BigInt {
            len: new_len,
            num: ans,
            neg: sim,
        }
    }
}

impl MulAssign for BigInt {
    fn mul_assign(&mut self, rhs: Self) {
        *self = self.clone() * rhs;
    }
}

impl Mul for BigInt {
    type Output = BigInt;
    fn mul(self, others: Self) -> BigInt {
        let sim = self.neg != others.neg;
        let mut new_len = self.len + others.len;
        let mut res = 0;
        let mut mid = vec![0; new_len];
        for i in 0..self.len {
            for j in 0..others.len {
                mid[i + j] += self.num[i] * others.num[j];
            }
        }
        let mut ans: Vec<i32> = mid
            .iter()
            .map(|&x| {
                let pre = res;
                res = (res + x) / 10;
                (pre + x) % 10
            })
            .collect();
        if ans[new_len - 1] != 0 {
            new_len += 1;
            ans.push(0);
        }
        BigInt {
            len: new_len - 1,
            num: ans,
            neg: sim,
        }
    }
}

impl DivAssign for BigInt {
    fn div_assign(&mut self, rhs: Self) {
        *self = if let Ok(n) = self.clone() / rhs {
            n
        } else {
            BigInt::new("")
        };
    }
}

impl Div for BigInt {
    type Output = Result<BigInt>;
    fn div(self, others: Self) -> Result<BigInt> {
        if others == BigInt::new("0") {
            return Err(CompError::Parse("Can't divided by zero".into()));
        }
        let mut ans = BigInt::new("0");
        let mut dived = self.clone();
        let mut len = if dived.len > others.clone().len {
            (dived.len - others.clone().len) as u32
        } else {
            0
        };
        while len > 0 {
            let div = others.clone() * BigInt::new(&format!("{}", 10i32.pow(len)));
            if dived >= div {
                dived -= div;
                ans += BigInt::new("1");
            } else {
                if len == 0 {
                    break;
                }
                len -= 1;
                ans *= BigInt::new("10");
            }
        }
        Ok(ans)
    }
}

fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    let (a, b) = cin()
        .split_whitespace()
        .fold((BigInt::new("0"), BigInt::new("0")), |x, y| {
            (x.1, BigInt::new(y))
        });
    (a.clone() + b.clone()).show();
    println!("resault = {:?}", a.clone() - b.clone());
    println!("resault = {:?}", a.clone() * b.clone());
    println!("resault = {:?}", a.pow(3))
}
