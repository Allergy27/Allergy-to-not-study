//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_985_glb_e_re.rs
//@data      2024/11/11 04:02:22
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
    // let t = 1;
    let t = cin!(i64);
    const MAX_N: usize = 500_027;
    let mut pr = vec![0; MAX_N + 1];
    let mut primes = Vec::new();
    pr[1] = 1;
    for i in 2..=MAX_N {
        if pr[i] == 0 {
            primes.push(i);
        }
        for p in &primes {
            if p * i > MAX_N {
                break;
            }
            //维护最小公因子
            pr[i * p] = *p;
            if i % p == 0 {
                break;
            }
        }
    }

    (0..t).for_each(|_| solve(&pr));
}
fn solve(pr: &[usize]) {
    let n = cin!(usize);
    let qwq = cin!([usize; n]);

    let mut pf = 0;

    for i in &qwq {
        if pr[*i] == 0 {
            pf = *i;
        }
    }
    if pf == 0 {
        println!("2");
    } else {
        for i in qwq {
            if i == pf {
                continue;
            }
            if pr[i] == 0 {
                println!("-1");
                return;
            } else if (i & 1) == 1 {
                if i - pr[i] < 2 * pf {
                    println!("-1");
                    return;
                }
            } else if i < 2 * pf {
                println!("-1");
                return;
            }
        }
        println!("{}", pf)
    }
}
