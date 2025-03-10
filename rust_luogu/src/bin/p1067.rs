//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p1067.rs
//@data      2025/01/13 18:37:55
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
    //let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin!(usize);
    let qwq = cin!([i32; n + 1]);
    for i in (0..=n).rev() {
        let x = qwq[n - i];
        if x != 0 {
            if i != n && x > 0 {
                print!("+");
            }
            if x.abs() > 1 || i == 0 {
                print!("{}", x);
            }
            if x == -1 && i != 0 {
                print!("-");
            }
            match i.cmp(&1) {
                std::cmp::Ordering::Greater => print!("x^{}", i),
                std::cmp::Ordering::Equal => print!("x"),
                std::cmp::Ordering::Less => (),
            }
        }
    }
    println!()
}
