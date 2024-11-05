//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1027.rs
//@data      2024/11/04 18:24:54
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
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, t, a, b) = cin!(f64, i64, i64, i64);

    let mid_find = |a: (f64, f64), b: (f64, f64)| {
        let x = (a.0 + b.0) / 2.0;
        let y = (a.1 + b.1) / 2.0;
        (x, y)
    };

    let find_forth = |c1: (f64, f64), c2: (f64, f64), c3: (f64, f64)| {
        let dis_1 = (c1.0 - c2.0) * (c1.0 - c2.0) + (c1.1 - c2.1) * (c1.1 - c2.1);
        let dis_2 = (c1.0 - c3.0) * (c1.0 - c3.0) + (c1.1 - c3.1) * (c1.1 - c3.1);
        let dis_3 = (c2.0 - c3.0) * (c2.0 - c3.0) + (c2.1 - c3.1) * (c2.1 - c3.1);
        if dis_1 > dis_2 && dis_2 > dis_3 {
            return ;
        }
    };
}
