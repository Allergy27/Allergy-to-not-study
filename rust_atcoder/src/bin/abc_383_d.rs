//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_383_d.rs
//@data      2024/12/07 20:31:11
#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    }};
    ([char]) => {{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().chars().collect::<Vec<char>>()
    }};
    ([u8]) =>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().bytes().collect::<Vec<u8>>()
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
    let n = cin!(u128);
    let lim = 4000000000000f64.sqrt() as usize;
    let mut is_prime = vec![true; lim + 1];
    let mut primes = Vec::new();

    for i in 2..=lim {
        if is_prime[i] {
            primes.push(i);
        }
        for &p in &primes {
            if i * p > lim {
                break;
            }
            is_prime[i * p] = false;
            if i % p == 0 {
                break;
            }
        }
    }
    let mut result = Vec::new();
    for &p in primes.iter() {
        let p = p as u128;
        if p > n
            || p * p > n
            || p * p * p > n
            || p * p * p * p > n
            || p * p * p * p * p > n
            || p * p * p * p * p * p > n
            || p * p * p * p * p * p * p > n
            || p * p * p * p * p * p * p * p > n
        {
            break;
        }
        let p8 = p.pow(8);
        result.push(p8);
    }
    for i in 0..primes.len() {
        let p = (primes[i] as u128).pow(2);
        if p > n {
            break;
        }
        for &prime_j in primes.iter().skip(i + 1) {
            let r = (prime_j as u128).pow(2);
            if r > n {
                break;
            }
            if p * r > n {
                break;
            }
            let p2r2 = p * r;
            result.push(p2r2);
        }
    }

    result.sort_unstable();
    println!("{}", result.partition_point(|x| *x <= n));
}
