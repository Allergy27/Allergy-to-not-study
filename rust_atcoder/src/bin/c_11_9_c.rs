//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/c_11_9_c.rs
//@data      2024/11/09 20:16:12
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
    let (n, m) = cin!(i64, i64);
    let x = cin!([i64; m]);
    let a = cin!([i64; m]);
    let mut ans = 0;
    for &value in &a {
        ans += value;
    }
    let mut qwq = x.into_iter().zip(a).collect::<Vec<_>>();
    qwq.sort_by(|a, b| b.0.cmp(&a.0));
    if ans != n {
        println!("-1");
        return;
    }
    let mut ri = n;
    let mut ans = 0;
    for (x, a) in qwq {
        if ri - a + 1 < x {
            println!("-1");
            return;
        }
        ri -= a;
        ans += (ri - x) * a + (a) * (a + 1) / 2;
    }
    println!("{}", ans);
}
