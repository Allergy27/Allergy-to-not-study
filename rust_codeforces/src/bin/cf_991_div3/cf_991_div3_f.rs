//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_991_div3_f.rs
//@data      2024/12/05 23:50:37
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
struct SegmentTree {
    data: Vec<i64>,
    size: usize,
}

impl SegmentTree {
    fn new(arr: &[i64]) -> Self {
        let size = arr.len();
        let data = vec![0; size * 4];
        let mut st = SegmentTree { data, size };
        st.build(arr, 1, 0, size - 1);
        st
    }

    fn build(&mut self, arr: &[i64], node: usize, start: usize, end: usize) {
        if start == end {
            self.data[node] = arr[start];
        } else {
            let mid = (start + end) / 2;
            self.build(arr, node * 2, start, mid);
            self.build(arr, node * 2 + 1, mid + 1, end);
            self.data[node] = gcd(self.data[node * 2], self.data[node * 2 + 1]);
        }
    }

    fn query(&self, l: usize, r: usize) -> i64 { self.query_rec(1, 0, self.size - 1, l, r) }

    fn query_rec(&self, node: usize, start: usize, end: usize, l: usize, r: usize) -> i64 {
        if r < start || end < l {
            return 0;
        }
        if l <= start && end <= r {
            return self.data[node];
        }
        let mid = (start + end) / 2;
        let left_gcd = self.query_rec(node * 2, start, mid, l, r);
        let right_gcd = self.query_rec(node * 2 + 1, mid + 1, end, l, r);
        gcd(left_gcd, right_gcd)
    }
}
fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}
fn solve() {
    let (n, q) = cin!(usize, usize);
    let a = cin!([i64; n]);
    let mut diff = vec![0];
    for i in 1..n {
        diff.push((a[i] - a[i - 1]).abs());
    }
    let st = SegmentTree::new(&diff);
    let mut res = Vec::with_capacity(q);

    for _ in 0..q {
        let (l, r) = cin!(usize, usize);
        if l == r {
            res.push(0);
        } else {
            res.push(st.query(l, r - 1));
        }
    }
    println!(
        "{}",
        res.iter().map(|x| x.to_string()).collect::<Vec<_>>().join(" ")
    );
}
