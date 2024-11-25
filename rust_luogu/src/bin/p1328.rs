//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p1328.rs
//@data      2024/11/18 14:33:16
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
    let (n, p, q) = cin!(usize, usize, usize);
    let check = |x: usize, y: usize| match (x, y) {
        (0, 2) | (1, 0) | (2, 1) | (0, 3) | (1, 3) | (2, 4) => 1,
        (3, 4) | (3, 2) | (4, 0) | (4, 1) => 1,
        _ => 0,
    };
    let mut a = 0;
    let mut b = 0;
    let qwq = cin!([usize; p]);
    let qaq = cin!([usize; q]);
    let mut ans = (0, 0);
    for _ in 0..n {
        ans.0 += check(qwq[a], qaq[b]);
        ans.1 += check(qaq[b], qwq[a]);
        a = (a + 1) % p;
        b = (b + 1) % q;
    }
    println!("{} {}", ans.0, ans.1)
}
