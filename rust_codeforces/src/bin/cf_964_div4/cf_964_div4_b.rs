//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_964_div4_b.rs
//@data      2024/12/03 06:12:35
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
    let (a, b, x, y) = cin!(i64, i64, i64, i64);
    let qwq = [(a, x), (a, y), (b, x), (b, y)];
    let mut ans = 0;
    for (p, q) in qwq {
        let mut ta = 0;
        let mut tb = 0;
        ta += (p > q) as i64;
        tb += (p < q) as i64;
        ta += (a + b - p > x + y - q) as i64;
        tb += (a + b - p < x + y - q) as i64;

        if ta > tb {
            ans += 1;
        }
    }
    println!("{ans}")
}
