//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/codeTon_c22.rs
//@data      2024/11/24 01:22:00
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
    let (x, m) = cin!(i64, i64);
    let mut ans = 0;
    for y in 1..=x.min(m) {
        let tmp = x ^ y;
        if tmp % x >0 && tmp % y == 0 {
            ans += 1
        }
    }
    let cnt = m / x;
    ans += cnt;
    for mul in 2.max(cnt - 2)..=cnt + 1 {
        let tmp = x * mul;
        let y = tmp ^ x;
        if tmp % x == 0 && tmp % y > 0 && y > m {
            ans -= 1;
        }
    }
    if x <= m {
        let y = x;
        let tmp = x ^ y;
        if tmp % x == 0 && tmp % y == 0 {
            ans += 1
        }
    }
    println!("{ans}")
}
