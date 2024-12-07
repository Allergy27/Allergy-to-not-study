//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_991_div3_a.rs
//@data      2024/12/05 22:33:59
#[macro_export]
macro_rules! read {
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
    let t = read!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m) = read!(usize, usize);
    let mut ans = 0;
    let mut res = 0;
    let mut flag = 0;
    for _ in 0..n {
        let tmp = read!().len();
        if res + tmp > m {
            flag = 1;
        }
        if flag == 0 {
            ans += 1;
            res += tmp;
        }
    }
    println!("{ans}")
}
