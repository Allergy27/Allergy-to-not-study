//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_383_e.rs
//@data      2024/12/07 21:04:40
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
    // let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m, k) = cin!(usize, usize, usize);
    let mut edges = Vec::with_capacity(m);
    for _ in 0..m {
        let (u, v, w) = cin!(usize, usize, i64);
        edges.push((w, u - 1, v - 1));
    }
    let a = cin!([usize; k]);
    let b = cin!([usize; k]);
    let mut cot_a = vec![0; n];
    let mut cot_b = vec![0; n];

    for &a in &a {
        cot_a[a - 1] += 1;
    }

    for &b in &b {
        cot_b[b - 1] += 1;
    }

    edges.sort();

    let mut fa: Vec<usize> = (0..n).collect();

    fn find(fa: &mut Vec<usize>, x: usize) -> usize {
        if fa[x] != x {
            fa[x] = find(fa, fa[x]);
        }
        fa[x]
    }

    let mut ans = 0;

    for &(w, u, v) in &edges {
        let ru = find(&mut fa, u);
        let rv = find(&mut fa, v);

        if ru != rv {
            let ta = cot_a[ru] + cot_a[rv];
            let tb = cot_b[ru] + cot_b[rv];
            let mi = ta.min(tb);
            let pu = cot_a[ru].min(cot_b[ru]);
            let pv = cot_a[rv].min(cot_b[rv]);
            let tmp = mi - pu - pv;

            if tmp > 0 {
                ans += tmp * w;
            }

            fa[rv] = ru;
            cot_a[ru] += cot_a[rv];
            cot_b[ru] += cot_b[rv];
        }
    }

    println!("{}", ans);
}
