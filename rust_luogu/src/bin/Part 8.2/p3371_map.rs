//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p3371.rs
//@data      2024/11/04 10:43:21
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
use std::cmp::Reverse;
fn solve() {
    let (n, m, s) = cin!(i64, i64, i64);
    let mut qwq: Vec<std::collections::HashMap<i64, i64>> =
        vec![std::collections::HashMap::new(); n as usize + 1];
    for _ in 0..m {
        let (u, v, w) = cin!(i64, i64, i64);
        qwq[u as usize].entry(v).and_modify(|x| *x = (*x).min(w)).or_insert(w);
    }
    let mut dis = vec![2147483647; n as usize + 1];
    let mut vis = vec![false; n as usize + 1];
    let mut que = std::collections::BinaryHeap::new();
    que.push(Reverse((0, s)));
    dis[s as usize] = 0;
    while let Some(Reverse((d, u))) = que.pop() {
        if vis[u as usize] {
            continue;
        }
        vis[u as usize] = true;
        for (&v, &w) in qwq[u as usize].iter() {
            if dis[v as usize] > d + w {
                dis[v as usize] = d + w;
                que.push(Reverse((w + d, v)));
            }
        }
    }
    dis.iter().skip(1).for_each(|x| print!("{} ", x));
    println!()
}
