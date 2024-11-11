//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_986_div2_b.rs
//@data      2024/11/10 23:51:22
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
    let t = cin!(usize);
    for _ in 0..t {
        solve();
    }
}

fn solve() {
    let (n, b, c) = cin!(i64, i64, i64);

    if b == 0 {
        if c >= n {
            println!("{}", n - 2);
        } else if c >= n - 2 {
            println!("{}", n - 1);
        } else {
            println!("-1");
        }
    } else if c >= n {
        println!("{}", n);
    } else {
        println!("{}", n - 0.max(1 + (n - c - 1) / b));
    }
}
