//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_1000_div2_b.rs
//@data      2025/01/22 20:14:55

fn main() {
    // let t = 1;
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, l, r) = cin!(usize, usize, usize);
    let qwq = cin!([i64; n]);
    let mut ans: i64 = qwq[l - 1..r].iter().sum();
    let mut tmp = std::collections::BinaryHeap::new();
    (0..r).for_each(|i| {
        tmp.push(std::cmp::Reverse(qwq[i]));
    });
    let mut res = 0;
    for _ in 0..r - l + 1 {
        res += tmp.pop().unwrap().0;
    }
    ans = ans.min(res);

    tmp = std::collections::BinaryHeap::new();
    (l - 1..n).for_each(|i| {
        tmp.push(std::cmp::Reverse(qwq[i]));
    });
    res = 0;
    for _ in 0..r - l + 1 {
        res += tmp.pop().unwrap().0;
    }
    ans = ans.min(res);

    println!("{ans}")
}

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
