//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_984_div3_e.rs
//@data      2024/11/05 23:59:15
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
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m, q) = cin!(usize, usize, i64);
    let mut qwq = Vec::with_capacity(n);
    for _ in 0..n {
        qwq.push(cin!([i64; m]));
    }
    for i in 1..n {
        for j in 0..m {
            qwq[i][j] |= qwq[i - 1][j]
        }
    }
    for _ in 0..q {
        let p = cin!(i64);
        let (mut l, mut r) = (0, n as i64);
        for _ in 0..p {
            let (t, o, c) = cin!(usize, char, i64);
            if o == '>' {
                l = l.max(qwq.partition_point(|x| x[t - 1] <= c) as i64);
            } else {
                r = r.min(qwq.partition_point(|x| x[t - 1] < c) as i64)
            }
        }
        if l >= r {
            println!("-1");
        } else {
            println!("{}", l + 1);
        }
    }
}
