//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_984_div3_g.rs
//@data      2024/11/06 09:17:02
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
use std::io::{stdout, Write};
fn main() {
    // let t = 1;
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin!(i64);
    let ask = |l: i64, r: i64| -> i64 {
        let l = l.max(1);
        let r = n.min(r - 1);
        if l > r {
            return 0;
        }
        println!("xor {} {}", l, r);
        stdout().flush().unwrap();
        cin!(i64)
    };
    let mut ans = Vec::with_capacity(3);
    let mut l = 0i64;
    let mut r = 1i64 << 60;
    let mut d = 60;
    loop {
        let mid = (l + r) / 2;
        let a = ask(l, mid);
        let b = ask(mid, r);
        d -= 1;
        if b == 0 {
            r = mid;
        } else if a == 0 {
            l = mid;
        } else if (b >> d & 1) == 1 {
            ans.push(b);
            r = mid;
            break;
        } else {
            ans.push(a);
            l = mid;
            break;
        }
    }
    loop {
        let mid = (l + r) / 2;
        let a = ask(l, mid);
        let b = ask(mid, r);
        d -= 1;
        if b == 0 {
            r = mid;
        } else if a == 0 {
            l = mid;
        } else {
            ans.push(b);
            ans.push(a);
            break;
        }
    }
    print!("ans");
    for i in ans {
        print!(" {}", i);
    }
    println!();
    stdout().flush().unwrap();
}
