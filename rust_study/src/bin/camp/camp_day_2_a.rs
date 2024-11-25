//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_2_a.rs
//@data      2024/11/17 13:07:05
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
fn solve() {
    let (n, m) = cin!(usize, usize);
    let a = cin!([i64; n]);
    let b = cin!([i64; m]);
    let size = n + m - 1;
    let size_fft = size.next_power_of_two();

    // 将输入扩展到 2 的幂
    let mut fa: Vec<Complex> = a.into_iter().map(|x| Complex::new(x as f64, 0.0)).collect();
    fa.resize(size_fft, Complex::new(0.0, 0.0));

    let mut fb: Vec<Complex> = b.into_iter().map(|x| Complex::new(x as f64, 0.0)).collect();
    fb.resize(size_fft, Complex::new(0.0, 0.0));

    // 快速傅里叶变换
    fft(&mut fa, false);
    fft(&mut fb, false);

    // 点乘
    let mut fc: Vec<Complex> = fa.into_iter().zip(fb).map(|(x, y)| x.mul(y)).collect();

    // 逆变换
    fft(&mut fc, true);

    // 提取实部作为结果，并处理浮点误差
    let mut result = vec![0i64; size];
    for (i, x) in fc.iter().enumerate().take(size) {
        result[i] = (x.re.round()) as i64;
    }

    // 返回卷积的总和
    println!("{}", result.iter().sum::<i64>())
}
