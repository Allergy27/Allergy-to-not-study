//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_985_glb_f.rs
//@data      2024/11/10 00:58:10
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
    //线性筛
    const N: usize = 400_027;
    let mut primes = Vec::new();
    let mut pf = vec![0; N + 1];
    pf[1] = 1;
    for i in 2..=N {
        if pf[i] == 0 {
            primes.push(i);
        }
        for &p in &primes {
            if i * p > N {
                break;
            }
            pf[i * p] = p;
            if i % p == 0 {
                break;
            }
        }
    }

    (0..t).for_each(|_| solve(&pf));
}
fn solve(pf: &[usize]) {
    let n = cin!(usize);
    let qwq = cin!([usize; n]);
    let mut p = 0;
    for &x in &qwq {
        if pf[x] == 0 {
            p = x
        }
    }
    if p == 0 {
        println!("2");
        return;
    }
    for &x in &qwq {
        if x == p {
            continue;
        }
        if pf[x] == 0 {
            println!("-1");
            return;
        }
        if (x & 1) == 1 {
            if x - pf[x] < 2 * p {
                println!("-1");
                return;
            }
        } else if x < 2 * p {
            println!("-1");
            return;
        }
    }
    println!("{}", p);
}
