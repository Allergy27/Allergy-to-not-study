//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_2_b.rs
//@data      2024/11/17 12:58:30
#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    }};
    ([$type:ty;$n:expr]) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        let mut arr = Vec::with_capacity($n as usize);
        for _ in 0..$n {
            arr.push((s.next().unwrap()).parse::<$type>().unwrap());
        }
        arr
    }};
    ($type:ty) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        (s.next().unwrap()).parse::<$type>().unwrap()
    }};

    ($($type:ty),*) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        ($(s.next().unwrap().parse::<$type>().unwrap()),*)
    }}
}
fn main() {
    let t = 1;
    //let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
// 复数结构
#[derive(Clone, Copy, Debug)]
struct Complex {
    re: f64,
    im: f64,
}

impl Complex {
    fn new(re: f64, im: f64) -> Self {
        Complex { re, im }
    }

    fn _magnitude(&self) -> f64 {
        self.re.hypot(self.im)
    }

    fn exp(theta: f64) -> Self {
        Complex::new(theta.cos(), theta.sin())
    }

    fn add(self, other: Complex) -> Self {
        Complex::new(self.re + other.re, self.im + other.im)
    }

    fn sub(self, other: Complex) -> Self {
        Complex::new(self.re - other.re, self.im - other.im)
    }

    fn mul(self, other: Complex) -> Self {
        Complex::new(
            self.re * other.re - self.im * other.im,
            self.re * other.im + self.im * other.re,
        )
    }
}

// 快速傅里叶变换
fn fft(a: &mut [Complex], invert: bool) {
    let n = a.len();
    if n == 1 {
        return;
    }

    let mut even = a.iter().step_by(2).cloned().collect::<Vec<_>>();
    let mut odd = a.iter().skip(1).step_by(2).cloned().collect::<Vec<_>>();

    fft(&mut even, invert);
    fft(&mut odd, invert);

    let angle = 2.0 * std::f64::consts::PI / n as f64 * if invert { -1.0 } else { 1.0 };
    let w = Complex::exp(angle);
    let mut wk = Complex::new(1.0, 0.0);

    for i in 0..n / 2 {
        let t = wk.mul(odd[i]);
        a[i] = even[i].add(t);
        a[i + n / 2] = even[i].sub(t);
        if invert {
            a[i] = Complex::new(a[i].re / 2.0, a[i].im / 2.0);
            a[i + n / 2] = Complex::new(a[i + n / 2].re / 2.0, a[i + n / 2].im / 2.0);
        }
        wk = wk.mul(w);
    }
}

// 高精度乘法实现，支持负数
fn solve() {
    let num1 = &cin!();
    let num2 = &cin!();
    // 处理符号位
    let mut sign = 1;
    let num1 = if let Some(stripped) = num1.strip_prefix('-') {
        sign *= -1;
        stripped
    } else {
        num1
    };
    let num2 = if let Some(stripped) = num2.strip_prefix('-') {
        sign *= -1;
        stripped
    } else {
        num2
    };

    // 将字符串数字转换为反序数组
    let mut a = num1.chars().rev().map(|c| c.to_digit(10).unwrap() as f64).collect::<Vec<_>>();
    let mut b = num2.chars().rev().map(|c| c.to_digit(10).unwrap() as f64).collect::<Vec<_>>();

    // 扩展长度到最近的 2 的幂
    let n = a.len() + b.len();
    let size = n.next_power_of_two();
    a.resize(size, 0.0);
    b.resize(size, 0.0);

    let mut fa = a.into_iter().map(|x| Complex::new(x, 0.0)).collect::<Vec<_>>();
    let mut fb = b.into_iter().map(|x| Complex::new(x, 0.0)).collect::<Vec<_>>();

    // 快速傅里叶变换
    fft(&mut fa, false);
    fft(&mut fb, false);

    // 点乘
    let mut fc = fa.iter().zip(fb.iter()).map(|(x, y)| x.mul(*y)).collect::<Vec<_>>();

    // 逆变换
    fft(&mut fc, true);

    // 提取结果并处理进位
    let mut result = vec![0u64; size];
    for (i, x) in fc.iter().enumerate() {
        result[i] = x.re.round() as u64;
    }
    for i in 0..result.len() - 1 {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    // 去掉前导零并反序为字符串
    while result.len() > 1 && result.last() == Some(&0) {
        result.pop();
    }

    let mut ans: String = result.into_iter().rev().map(|x| (x as u8 + b'0') as char).collect();

    // 添加符号位
    if sign == -1 && ans != "0" {
        ans.insert(0, '-');
    }
    println!("{ans}")
}
