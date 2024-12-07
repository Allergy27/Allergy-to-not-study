//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/edu_172_div2_d.rs
//@data      2024/12/03 00:08:05
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
    let n = cin!(usize);
    let mut qwq = Vec::with_capacity(n);
    let mut lb = vec![-1; n];
    let mut rb = vec![-1; n];
    for i in 0..n {
        let (x, y) = cin!(i64, i64);
        qwq.push((x, y, i));
    }

    qwq.sort_unstable_by(
        |a, b| {
            if a.0 != b.0 {
                a.0.cmp(&b.0)
            } else {
                b.1.cmp(&a.1)
            }
        },
    );
    let mut s = std::collections::BTreeSet::new();
    for j in 0..n {
        let (l, r, i) = qwq[j];
        if let Some(tmp) = s.range(r..).next() {
            rb[i] = *tmp;
        }
        s.insert(r);
        if j + 1 < n && l == qwq[j + 1].0 && r == qwq[j + 1].1 {
            rb[i] = r;
        }
    }
    qwq.sort_unstable_by(
        |a, b| {
            if a.1 != b.1 {
                b.1.cmp(&a.1)
            } else {
                a.0.cmp(&b.0)
            }
        },
    );
    s.clear();
    for j in 0..n {
        let (l, r, i) = qwq[j];
        if let Some(tmp) = s.range(..=l).next_back() {
            lb[i] = *tmp;
        }
        s.insert(l);
        if j + 1 < n && l == qwq[j + 1].0 && r == qwq[j + 1].1 {
            lb[i] = l;
        }
    }
    qwq.sort_unstable_by(|a, b| a.2.cmp(&b.2));
    for i in 0..n {
        let ans = if lb[i] == -1 { 0 } else { rb[i] - lb[i] - (qwq[i].1 - qwq[i].0) };
        println!("{ans}")
    }
}
