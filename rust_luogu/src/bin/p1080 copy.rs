//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p1080.rs
//@data      2024/11/24 17:06:31
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
fn solve() {
    let n = cin!(usize);
    let mut qwq = vec![];
    for _ in 0..=n {
        let (x, y) = cin!(i128, i128);
        qwq.push((x, y));
    }
    qwq.sort_unstable_by(|x, y| (x.0 * x.1).cmp(&(y.0 * y.1)));

    let mut mul = |mut num: Vec<i128>, x: i128| -> Vec<i128> {
        let mut carry = 0;
        for y in &mut num {
            let tmp = *y * x + carry;
            *y = tmp % 10;
            carry = tmp / 10;
        }
        while carry > 0 {
            num.push(carry % 10);
            carry /= 10;
        }
        num
    };
    let div = |qwq: Vec<i128>, y: i128| -> Vec<i128> {
        let mut res = Vec::new();
        let mut carry = 0;
        for &x in &qwq {
            let cur = carry * 10 + x;
            res.push(cur / y);
            carry = cur % y;
        }
        while res.len() > 1 && res[0] == 0 {
            res.remove(0);
        }
        res
    };
    let cmp = |a: &Vec<i128>, b: &Vec<i128>| -> std::cmp::Ordering {
        if a.len() != b.len() {
            return a.len().cmp(&b.len());
        }
        for (x, y) in a.iter().zip(b.iter()) {
            if x != y {
                return x.cmp(y);
            }
        }
        std::cmp::Ordering::Equal
    };

    let max = |a: Vec<i128>, b: Vec<i128>| -> Vec<i128> {
        if cmp(&a, &b) == std::cmp::Ordering::Greater {
            a
        } else {
            b
        }
    };
    let mut ans = vec![0];
    let mut tmp = vec![1];
    for i in 0..=n {
        if i > 0 {
            ans = max(ans, div(tmp.clone(), qwq[i].1));
        }
        tmp = mul(tmp, qwq[i].0);
    }
    ans.iter().rev().for_each(|x| print!("{}", x));
    println!();
}
