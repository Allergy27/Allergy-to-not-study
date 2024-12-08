//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p3372.rs
//@data      2024/12/07 17:48:32
#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    }};
    ([char]) => {{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().chars().collect::<Vec<char>>()
    }};
    ([u8]) =>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().bytes().collect::<Vec<u8>>()
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
#[derive(Clone, Copy)]
enum Operation {
    Sum,
}

struct SegmentTree {
    n: usize,
    data: Vec<i64>,
    lazy_add: Vec<i64>,
    lazy_mul: Vec<i64>,
    operation: Operation,
    p: i64, // 模数
}

impl SegmentTree {
    fn new(n: usize, operation: Operation, p: i64) -> Self {
        SegmentTree {
            n,
            data: vec![0; 4 * n],
            lazy_add: vec![0; 4 * n],
            lazy_mul: vec![1; 4 * n], // 初始化为1，因为乘法的单位元是1
            operation,
            p,
        }
    }

    fn build(&mut self, arr: &[i64]) {
        self.build_rec(0, 0, self.n - 1, arr);
    }

    fn build_rec(&mut self, node: usize, start: usize, end: usize, arr: &[i64]) {
        if start == end {
            self.data[node] = arr[start] % self.p;
        } else {
            let mid = (start + end) / 2;
            self.build_rec(2 * node + 1, start, mid, arr);
            self.build_rec(2 * node + 2, mid + 1, end, arr);
            self.data[node] = self.combine(self.data[2 * node + 1], self.data[2 * node + 2]);
        }
    }

    fn combine(&self, left: i64, right: i64) -> i64 {
        match self.operation {
            Operation::Sum => (left + right) % self.p,
        }
    }

    fn query(&mut self, l: usize, r: usize) -> i64 {
        self.query_rec(0, 0, self.n - 1, l, r)
    }

    fn query_rec(&mut self, node: usize, start: usize, end: usize, l: usize, r: usize) -> i64 {
        self.propagate(node, start, end);
        if r < start || end < l {
            return 0;
        }
        if l <= start && end <= r {
            return self.data[node];
        }
        let mid = (start + end) / 2;
        let left_result = self.query_rec(2 * node + 1, start, mid, l, r);
        let right_result = self.query_rec(2 * node + 2, mid + 1, end, l, r);
        self.combine(left_result, right_result)
    }

    fn update_range_add(&mut self, l: usize, r: usize, value: i64) {
        self.update_range_add_rec(0, 0, self.n - 1, l, r, value);
    }

    fn update_range_add_rec(
        &mut self,
        node: usize,
        start: usize,
        end: usize,
        l: usize,
        r: usize,
        value: i64,
    ) {
        self.propagate(node, start, end);
        if r < start || end < l {
            return;
        }
        if l <= start && end <= r {
            self.data[node] =
                (self.data[node] + (end - start + 1) as i64 * value % self.p) % self.p;
            if start != end {
                self.lazy_add[2 * node + 1] = (self.lazy_add[2 * node + 1] + value) % self.p;
                self.lazy_add[2 * node + 2] = (self.lazy_add[2 * node + 2] + value) % self.p;
            }
            return;
        }
        let mid = (start + end) / 2;
        self.update_range_add_rec(2 * node + 1, start, mid, l, r, value);
        self.update_range_add_rec(2 * node + 2, mid + 1, end, l, r, value);
        self.data[node] = self.combine(self.data[2 * node + 1], self.data[2 * node + 2]);
    }

    fn update_range_mul(&mut self, l: usize, r: usize, value: i64) {
        self.update_range_mul_rec(0, 0, self.n - 1, l, r, value);
    }

    fn update_range_mul_rec(
        &mut self,
        node: usize,
        start: usize,
        end: usize,
        l: usize,
        r: usize,
        value: i64,
    ) {
        self.propagate(node, start, end);
        if r < start || end < l {
            return;
        }
        if l <= start && end <= r {
            self.data[node] = (self.data[node] * value % self.p) % self.p;
            if start != end {
                self.lazy_mul[2 * node + 1] = (self.lazy_mul[2 * node + 1] * value) % self.p;
                self.lazy_mul[2 * node + 2] = (self.lazy_mul[2 * node + 2] * value) % self.p;
            }
            return;
        }
        let mid = (start + end) / 2;
        self.update_range_mul_rec(2 * node + 1, start, mid, l, r, value);
        self.update_range_mul_rec(2 * node + 2, mid + 1, end, l, r, value);
        self.data[node] = self.combine(self.data[2 * node + 1], self.data[2 * node + 2]);
    }

    fn propagate(&mut self, node: usize, start: usize, end: usize) {
        if self.lazy_add[node] != 0 || self.lazy_mul[node] != 1 {
            self.data[node] = (self.data[node] * self.lazy_mul[node] % self.p
                + (end - start + 1) as i64 * self.lazy_add[node] % self.p)
                % self.p;
            if start != end {
                self.lazy_mul[2 * node + 1] =
                    (self.lazy_mul[2 * node + 1] * self.lazy_mul[node]) % self.p;
                self.lazy_mul[2 * node + 2] =
                    (self.lazy_mul[2 * node + 2] * self.lazy_mul[node]) % self.p;
                self.lazy_add[2 * node + 1] = (self.lazy_add[2 * node + 1] * self.lazy_mul[node]
                    % self.p
                    + self.lazy_add[node])
                    % self.p;
                self.lazy_add[2 * node + 2] = (self.lazy_add[2 * node + 2] * self.lazy_mul[node]
                    % self.p
                    + self.lazy_add[node])
                    % self.p;
            }
            self.lazy_add[node] = 0;
            self.lazy_mul[node] = 1;
        }
    }
}

fn solve() {
    let (n, m, p) = cin!(usize, usize, i64);
    let arr = cin!([i64; n]);
    let mut qwq = SegmentTree::new(n, Operation::Sum, p);
    qwq.build(&arr);
    for _ in 0..m {
        let tmp = cin!();
        let mut input = tmp.split_whitespace();
        let t = input.next().unwrap().parse::<i64>().unwrap();
        if t == 1 {
            let l = input.next().unwrap().parse::<usize>().unwrap() - 1;
            let r = input.next().unwrap().parse::<usize>().unwrap() - 1;
            let k = input.next().unwrap().parse::<i64>().unwrap();
            qwq.update_range_mul(l, r, k);
        } else if t == 2 {
            let l = input.next().unwrap().parse::<usize>().unwrap() - 1;
            let r = input.next().unwrap().parse::<usize>().unwrap() - 1;
            let k = input.next().unwrap().parse::<i64>().unwrap();
            qwq.update_range_add(l, r, k);
        } else if t == 3 {
            let l = input.next().unwrap().parse::<usize>().unwrap() - 1;
            let r = input.next().unwrap().parse::<usize>().unwrap() - 1;
            println!("{}", qwq.query(l, r) % p)
        }
    }
}
