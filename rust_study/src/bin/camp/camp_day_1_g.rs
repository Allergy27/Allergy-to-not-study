//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/camp_day_1_g.rs
//@data      2024/11/16 12:27:53
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

fn solve() {
    let n = cin!(usize);
    // Step 1: Compute Möbius function (μ) using sieve
    let mut mu = vec![1; n + 1];
    let mut is_prime = vec![true; n + 1];
    for i in 2..=n {
        if is_prime[i] {
            for j in (i..=n).step_by(i) {
                is_prime[j] = false;
                mu[j] *= -1;
            }
            let ii = i * i;
            if ii <= n {
                for j in (ii..=n).step_by(ii) {
                    mu[j] = 0;
                }
            }
        }
    }
    // Step 2: Compute G
    let mut g = 0;
    for d in 1..=n {
        let mut term = 0;
        for (i, elem) in mu.iter().enumerate().take(n / d + 1).skip(1) {
            let tmp = (n / (d * i)) as i64;
            term += elem * tmp * tmp;
        }
        g += d as i64 * term;
    }
    println!("{g}")
}
