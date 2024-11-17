//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_1_a.rs
//@data      2024/11/16 11:01:41
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
fn seg(l: i64, r: i64) -> usize {
    assert!(l >= 0 && r >= l, "Invalid range!");

    // Step 1: 普通埃氏筛法筛选出小于 sqrt(r) 的所有素数
    let limit = (r as f64).sqrt().ceil() as i64;
    let mut is_prime = vec![true; (limit + 1) as usize];
    is_prime[0] = false;
    if limit > 1 {
        is_prime[1] = false;
    }

    for i in 2..=limit {
        if is_prime[i as usize] {
            for j in (i * i..=limit).step_by(i as usize) {
                is_prime[j as usize] = false;
            }
        }
    }

    // 获取小范围内的素数
    let primes: Vec<i64> = (2..=limit).filter(|&x| is_prime[x as usize]).collect();

    // Step 2: 初始化区间 [l, r] 的标记
    let size = (r - l + 1) as usize;
    let mut segment = vec![true; size];

    // Step 3: 标记区间内的非素数
    for &prime in &primes {
        let mut start = if l % prime == 0 { l } else { l + (prime - l % prime) };

        if start == prime && start >= l {
            start += prime; // 避免将 prime 本身标记为非素数
        }

        for j in (start..=r).step_by(prime as usize) {
            segment[(j - l) as usize] = false;
        }
    }

    // Step 4: 收集区间内的素数
    (l..=r).filter(|&x| segment[(x - l) as usize] && x > 1).count()
}
fn solve() {
    let n = cin!(i64);
    println!("{}", seg(n * n, n * n + n));
}
