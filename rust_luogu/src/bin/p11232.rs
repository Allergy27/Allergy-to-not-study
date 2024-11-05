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
    let (n, m, l, v) = cin!(usize, usize, i64, i64);
    let mut qwq = vec![(0, 0); n];
    let mut dp = vec![0; m + 2];

    for owo in &mut qwq {
        let (d, v0, acc) = cin!(i64, i64, i64);
        if v0 > v {
            if acc >= 0 {
                *owo = (d, l);
            } else {
                *owo = (d, (v * v - v0 * v0 + 1) / (2 * acc) + d.min(l));
            }
        } else if acc <= 0 {
            *owo = (l + 1, l + 1);
        } else {
            *owo = ((v * v - v0 * v0) / (2 * acc) + d + 1.min(l + 1), l);
        }
    }
    let mut p = cin!([i64; m]);
    qwq.sort_by(|x, y| x.1.cmp(&y.1));
    let mut i = 0;
    let mut cnt = 0;
    let mut left = 0;
    p.push(l + 1);
    let mut q = std::collections::VecDeque::new();
    q.push_back(0);

    for j in 0..=m {
        while i < n && qwq[i].1 < p[j] {
            if qwq[i].0 <= p[j - 1] {
                cnt += 1;
                left = left.max(qwq[i].0);
            }
            i += 1;
        }
        while !q.is_empty() && p[*q.front().unwrap()] < left {
            q.pop_front();
        }
        dp[j] = dp[*q.front().unwrap()] + 1;
        while !q.is_empty() && dp[j] <= dp[*q.back().unwrap()] {
            q.pop_back();
        }
        q.push_back(j);
    }
    println!("{:?}", dp);
    println!("{} {}", cnt, m + 1 - dp[m + 1]);
}
