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
const INF: usize = 2147483647;
fn solve() {
    let (n, m, s) = cin!(i64, i64, i64);
    let mut qwq = Graph::new(n);
    for _ in 0..m {
        let (u, v, w) = cin!(i64, i64, i64);
        qwq.add(u, v, w);
    }
    let mut dis = vec![INF as i64; n as usize + 1];
    let mut vis = vec![false; n as usize + 1];
    let mut que = std::collections::BinaryHeap::new();
    que.push(Reverse((0, s)));
    dis[s as usize] = 0;
    while let Some(Reverse((d, u))) = que.pop() {
        if vis[u as usize] {
            continue;
        }
        vis[u as usize] = true;
        let mut current = qwq.head[u as usize];
        while current != -1 {
            let (to, w, next) = qwq.edge[current as usize];
            if dis[to as usize] > d + w {
                dis[to as usize] = d + w;
                que.push(Reverse((d + w, to)));
            }
            current = next;
        }
    }
    dis.iter().skip(1).for_each(|x| print!("{} ", x));
    println!()
}

struct Graph {
    edge: Vec<(i64, i64, i64)>,
    head: Vec<i64>,
}

impl Graph {
    fn new(n: i64) -> Self {
        let head = vec![-1; n as usize + 1];
        let edge = Vec::new();
        Self { edge, head }
    }
    fn add(&mut self, u: i64, v: i64, w: i64) {
        self.edge.push((v, w, self.head[u as usize]));
        self.head[u as usize] = (self.edge.len() - 1) as i64;
    }
}
