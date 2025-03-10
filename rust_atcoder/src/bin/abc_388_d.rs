//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_388_d.rs
//@data      2025/01/11 20:38:54
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
    //let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
struct Fenwick {
    size: usize,
    data: Vec<i64>,
}

impl Fenwick {
    fn new(size: usize) -> Self {
        Fenwick {
            size,
            data: vec![0; size + 1],
        }
    }

    fn add(&mut self, mut idx: usize, val: i64) {
        while idx <= self.size {
            self.data[idx] += val;
            idx += idx & (!idx + 1);
        }
    }

    fn prefix_sum(&self, mut idx: usize) -> i64 {
        let mut s = 0i64;
        while idx > 0 {
            s += self.data[idx];
            idx &= idx - 1;
        }
        s
    }

    fn range_sum(&self, l: usize, r: usize) -> i64 {
        if l > r {
            0
        } else {
            self.prefix_sum(r) - self.prefix_sum(l - 1)
        }
    }
}

fn solve() {
    // 读入

    let n = cin!(usize);
    let tmp = cin!([i64; n]);
    let mut qwq = vec![0; n + 1];
    (0..n).for_each(|i| {
        qwq[i + 1] = tmp[i];
    });

    let max_n = n + 500000 + 10;
    let mut fenw = Fenwick::new(max_n);

    let mut qvq = vec![0i64; n + 1];
    let mut shift = 0i64;

    for i in 1..=n {
        let l = (shift + 1) as usize;
        let pool = if l <= max_n { fenw.range_sum(l, max_n) } else { 0 };
        let tmp = qwq[i] + pool;

        shift += 1;
        let c = if shift as usize <= max_n {
            fenw.range_sum(shift as usize, shift as usize)
        } else {
            0
        };
        if c > 0 {
            fenw.add(shift as usize, -c);
        }

        let idx = tmp + shift;
        let mut iu = idx as usize;
        if iu > max_n {
            iu = max_n;
        }
        if iu > 0 {
            fenw.add(iu, 1);
        }
        qvq[i] = idx;
    }

    (1..=n).for_each(|i| {
        let ans = (qvq[i] - shift).max(0);
        print!("{} ", ans);
    });
}
