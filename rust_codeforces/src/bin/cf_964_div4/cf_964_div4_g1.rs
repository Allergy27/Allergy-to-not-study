//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_964_div4_g.rs
//@data      2024/12/03 08:26:42
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
    (0..t).for_each(|_| solve());
}

fn solve() {
    use std::io::{stdout, Write};
    let ask = |a: i32, b: i32| -> i32 {
        println!("? {a} {b}");
        stdout().flush().unwrap();
        cin!(i32)
    };
    let mut l = 1;
    let mut r = 999;
    while l < r {
        let mid = (l + r) >> 1;
        let tmp = ask(mid, r);
        if tmp == (mid + 1) * (r + 1) {
            r = mid - 1
        } else if tmp == mid * (r + 1) {
            r -= 1;
            l = mid
        } else if tmp == mid * r {
            println!("! {}", r + 1);
            return;
        }
    }
    println!("! {}", r + 1)
}
