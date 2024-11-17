//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_988_div3_d.rs
//@data      2024/11/17 22:59:31
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
    let (l, m, n) = cin!(usize, usize, usize);
    let mut qwq = Vec::with_capacity(l);
    for _ in 0..l {
        qwq.push(cin!(usize, usize));
    }
    let mut qaq = Vec::with_capacity(m);
    for _ in 0..m {
        qaq.push(cin!(usize, usize));
    }

    // 合并事件: 增益 障碍 结束 终点
    let mut events = Vec::new();
    for &(l, r) in &qwq {
        events.push((l, 1, r - l + 1));
    }
    for &(x, v) in &qaq {
        events.push((x, 0, v));
    }
    events.push((n, 2, 0)); // 终点
    events.sort_unstable_by(|a, b| a.0.cmp(&b.0));
    let mut k = 1;
    let mut heap = std::collections::BinaryHeap::new();
    let mut ans = 0;
    for (_, t, v) in events {
        if t == 0 {
            heap.push(v);
        } else if t == 1 {
            while k <= v {
                if let Some(top) = heap.pop() {
                    k += top;
                    ans += 1;
                } else {
                    println!("-1");
                    return;
                }
            }
        } else {
            println!("{ans}");
        }
    }
}
