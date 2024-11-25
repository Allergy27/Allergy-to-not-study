//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_381_d.rs
//@data      2024/11/22 20:25:53
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
    let n = cin!(usize);
    let qwq = cin!([i64; n]);
    let mut mp = std::collections::HashMap::new();
    let mut l = 0;
    let mut r = 0;
    let mut ans = 0;
    while r + 1 < n {
        if qwq[r] != qwq[r + 1] {
            if r > 0 && qwq[r] == qwq[r - 1] {
                mp.clear();
                ans = ans.max(2);
                r -= 1;
                l = r;
            } else {
                ans = ans.max(r - l);
                mp.clear();
                r += 1;
                l = r;
            }
        } else {
            while let Some(&x) = mp.get(&qwq[r]) {
                if x == 0 {
                    break;
                }
                *mp.entry(qwq[l]).or_insert(0) -= 2;
                l += 2;
                if l >= r {
                    break;
                }
            }
            *mp.entry(qwq[r]).or_insert(0) += 2;
            r += 2;
            ans = ans.max(r - l);
        }
    }
    println!("{ans}");
}
