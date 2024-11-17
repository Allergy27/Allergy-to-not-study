//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1955.rs
//@data      2024/11/01 22:29:14
use std::collections::{hash_map::Entry::Vacant, HashMap};

#[macro_export]
macro_rules! cin {
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
        let mut arr = [$n;$n];
        for i in 0..$n {
            arr[i] = (s.next().unwrap()).parse::<$type>().unwrap();
        }
        arr
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
    let n = cin!(i64);
    let mut uf = UFset::new(n << 1);
    let mut map = HashMap::new();
    let mut idx = 0;
    let mut arr = (0..n).map(|_| cin!(i64, i64, i32)).collect::<Vec<(i64, i64, i32)>>();
    arr.sort_unstable_by(|a, b| b.2.cmp(&a.2));
    for (x, y, e) in arr {
        if let Vacant(v) = map.entry(x) {
            v.insert(idx);
            idx += 1;
        }
        if let Vacant(v) = map.entry(y) {
            v.insert(idx);
            idx += 1;
        }
        let f = |x| map.get(&x).unwrap_or(&0);
        let p = f(x);
        let q = f(y);
        if e == 1 && uf.find(*p) != uf.find(*q) {
            uf.merge(*p, *q);
        } else if e == 0 && uf.find(*p) == uf.find(*q) {
            println!("NO");
            return;
        }
    }
    println!("YES");
}

struct UFset {
    fa: Vec<i64>,
}

impl UFset {
    fn new(n: i64) -> Self {
        UFset {
            fa: (0..n).collect(),
        }
    }
    fn find(&mut self, x: i64) -> i64 {
        if self.fa[x as usize] != x {
            self.fa[x as usize] = self.find(self.fa[x as usize]);
        }
        self.fa[x as usize]
    }
    fn merge(&mut self, x: i64, y: i64) {
        let x = self.find(x);
        let y = self.find(y);
        if x != y {
            self.fa[x as usize] = y;
        }
    }
}
