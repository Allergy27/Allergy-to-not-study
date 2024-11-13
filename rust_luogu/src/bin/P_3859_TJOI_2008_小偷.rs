//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace bin/P_3859_TJOI_2008_小偷.rs
//@data      2024/11/12 21:27:27
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
    let t = 20000;
    //let t = cin!(i64);
    (0..t).for_each(|_| solve());
}

use std::time::{SystemTime, UNIX_EPOCH};

struct Lcg {
    a: u64,    // 乘数
    c: u64,    // 增量
    m: u64,    // 模数
    seed: u64, // 当前的种子
}

impl Lcg {
    // 创建新的 LCG 生成器，仅需输入种子
    fn new() -> Self {
        let seed = || -> u64 {
            let start = SystemTime::now();
            let duration = start.duration_since(UNIX_EPOCH).unwrap();
            duration.as_secs() // 返回从1970年到现在的秒数，作为伪随机种子
        };

        // 默认的 LCG 参数

        Lcg {
            a: 1664525,
            c: 1013904223,
            m: 2u64.pow(32),
            seed: seed(),
        }
    }

    // 生成下一个伪随机数
    fn nxt(&mut self) -> usize {
        self.seed = (self.a * self.seed + self.c) % self.m;
        self.seed as usize
    }

    // 生成一个指定范围的随机数
    fn next(&mut self, range: usize) -> usize {
        self.nxt() % range
    }
}

fn solve() {
    let mut random = Lcg::new();
    // let (n, m) = cin!(usize, usize);
    let (n, m) = (random.next(10), random.next(15));
    // let mut qwq = cin!([usize; n]);
    let mut qwq = (0..n).map(|_| random.next(1000)).collect::<Vec<_>>();
    for i in 1..n {
        qwq[i] = qwq[i].min(qwq[i - 1])
    }
    let mut st = Vec::new();
    for _ in 0..m {
        st.push((random.next(n), random.next(1000) as i64, random.next(1000)));
        // st.push(cin!(usize, i64, usize))
    }

    let sov1 = |qwq: &Vec<_>, st: &Vec<(usize, i64, usize)>| {
        let st = st.clone();
        // st.sort_unstable_by(|a, b| b.0.cmp(&a.0));
        let lim = qwq[0];
        let mut dp = vec![0; lim];
        for (j, w, t) in st {
            for i in t..qwq[j].min(qwq[0]) {
                dp[i] = dp[i].max(dp[i - t] + w)
            }
        }
        dp.into_iter().max().unwrap()
    };
    let lim = qwq[0];
    let mut dp = vec![0; lim];
    for i in 1..qwq[0] {
        dp[i] = dp[i - 1];
        for (s, w, t) in &st {
            if qwq[*s] <= i || *t > i {
                continue;
            }
            dp[i] = dp[i].max(dp[i - t] + w);
        }
    }
    let ans1 = sov1(&qwq, &st);
    if dp[qwq[0] - 1] != ans1 {
        println!("{} {}", dp[qwq[0] - 1], ans1);
        println!("arr :{:?}", (n, m, qwq, st));
    }
}
