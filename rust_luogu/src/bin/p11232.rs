//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p11232.rs
//@data      2024/11/05 20:18:56
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
    let (n, m, lim, v) = cin!(usize, usize, i64, i64);
    let mut qwq = Vec::with_capacity(n);
    for _ in 0..n {
        let (d, v0, a) = cin!(i64, i64, i64);
        match (a >= 0, v0 > v) {
            (true, true) => qwq.push((d, lim)),
            (false, true) => qwq.push((d, lim.min((v * v - v0 * v0 + 1) / (2 * a) + d))),
            (true, false) => {
                if a != 0 {
                    qwq.push(((lim + 1).min((v * v - v0 * v0) / (2 * a) + d + 1), lim))
                }
            }
            _ => (),
        }
    }
    qwq.sort_unstable_by(|(a, _), (b, _)| a.cmp(b));
    let find = cin!([i64; m]);
    let mut ans = 0;
    let mut pre = m + 1;
    let mut cot = 0;
    while let Some((l, r)) = qwq.pop() {
        let fl = find.partition_point(|&x| x < l);
        let fr = find.partition_point(|&x| x <= r);
        if fl + 1 > fr || fr == 0 {
            continue;
        }
        ans += 1;
        if fl > pre || pre > fr - 1 {
            cot += 1;
            pre = fl;
        }
    }
    println!("{} {}", ans, m - cot);
}
