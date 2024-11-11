//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_984_div3_e_re.rs
//@data      2024/11/11 05:30:56
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
    // let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, k, q) = cin!(usize, usize, usize);
    let mut qwq = vec![Vec::new(); n];
    for i in 0..n {
        let tmp = cin!([i64; k]);
        qwq[i] = tmp;
        if i > 0 {
            for j in 0..k {
                qwq[i][j] |= qwq[i - 1][j]
            }
        }
    }
    for _ in 0..q {
        let t = cin!(usize);
        let mut l = 0;
        let mut r = n;
        for _ in 0..t {
            let (a, op, b) = cin!(usize, char, i64);
            if op == '<' {
                r = r.min(qwq.partition_point(|x| x[a - 1] < b));
            } else {
                l = l.max(qwq.partition_point(|x| x[a - 1] <= b));
            }
        }
        if l >= r {
            println!("-1")
        } else {
            println!("{}", l + 1)
        }
    }
}
