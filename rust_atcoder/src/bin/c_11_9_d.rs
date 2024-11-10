//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/c_11_9_d.rs
//@data      2024/11/09 20:40:14
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
    //`let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
struct TreeList {
    tree: Vec<i64>,
    n: usize,
}

impl TreeList {
    fn new(n: usize) -> Self {
        TreeList {
            tree: vec![0; n + 1],
            n,
        }
    }

    fn add(&mut self, mut i: usize, x: i64) {
        while i <= self.n {
            self.tree[i] += x;
            i += i & i.wrapping_neg();
        }
    }

    fn sum(&self, mut i: usize) -> i64 {
        let mut s = 0;
        while i > 0 {
            s += self.tree[i];
            i -= i & i.wrapping_neg();
        }
        s
    }

    fn range_add(&mut self, l: usize, r: usize, x: i64) {
        self.add(l, x);
        self.add(r + 1, -x);
    }

    fn point_query(&self, i: usize) -> i64 {
        self.sum(i)
    }
}

fn solve() {
    let q = cin!(i64);
    let mut tree = vec![0; q as usize];
    let mut r = 0;
    let mut l = 0;
    let mut sum = 0;
    for _ in 0..q {
        //QWQ
        let input = cin!();
        let mut input = input.split_whitespace();
        let a = input.next().unwrap().parse::<i64>().unwrap();
        if a == 1 {
            r += 1;
            continue;
        }
        let x = input.next().unwrap().parse::<i64>().unwrap();
        if a == 2 {
            tree[r + 1] = -x;
            tree[l] += x;
        } else if a == 3 {
            let mut tmp = 0;
            while l <= r {
                if sum > x {
                    break;
                }
                tmp += 1;
                l += 1;
                sum += tree[l];
            }
            println!("{}", tmp);
            println!("{:?}", tree);
        }
    }
}
