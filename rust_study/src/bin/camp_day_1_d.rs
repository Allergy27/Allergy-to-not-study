//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_1_c.rs
//@data      2024/11/16 11:55:20
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
    // let t = cin!(i64);
    (0..t).for_each(|_| solve());
}

fn solve() {
    let (x, y) = cin!(i64, i64);
    let max_n = (y as f64).sqrt() as i64 + 1;
    let mut mu = vec![1; (max_n + 1) as usize]; // 初始化莫比乌斯函数
    let mut is_prime = vec![true; (max_n + 1) as usize]; // 标记素数
    for i in 2..=max_n {
        if is_prime[i as usize] {
            for j in (i..=max_n).step_by(i as usize) {
                mu[j as usize] *= -1; // 素数因子影响
                is_prime[j as usize] = false;
            }
            for j in (i * i..=max_n).step_by((i * i) as usize) {
                mu[j as usize] = 0; // 平方因子置为 0
            }
        }
    }

    let get_factors = |y: i64| {
        let mut factors = Vec::new();
        let sqrt_y = (y as f64).sqrt() as i64;
        for i in 1..=sqrt_y {
            if y % i == 0 {
                factors.push(i);
                if i != y / i {
                    factors.push(y / i);
                }
            }
        }
        factors
    };
    let factors = get_factors(y); // 获取 y 的所有因子
    let mut ans = 0;
    for &d in &factors {
        if d as usize <= max_n as usize {
            ans += mu[d as usize] * (x / d); // 计算莫比乌斯函数的贡献
        } else {
            // 对于超过预处理范围的 d，需要手动计算 mu(d)
            let mut d_value = d;
            let mut mu = 1; // 初始值为 1
            let mut p = 2;
            while p * p <= d_value {
                if d_value % p == 0 {
                    d_value /= p;
                    if d_value % p == 0 {
                        mu = 0; // 存在平方因子
                        break;
                    }
                    mu = -mu; // 乘以 -1
                }
                p += 1;
            }
            if d_value > 1 {
                mu = -mu; // 如果剩余部分是质数
            }
            ans += mu * (x / d); // 加入手动计算的贡献
        }
    }
    println!("{ans}")
}
