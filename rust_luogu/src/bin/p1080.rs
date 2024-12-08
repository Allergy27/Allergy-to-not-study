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
    let mut a = vec![cin!(i64)];
    let mut ans: Vec<Vec<i64>> = Vec::new();
    for _ in 0..n {
        let row = cin!([i64; 2]);
        ans.push(row);
    }

    ans.sort_by(|x, y| (x[0] * x[1]).cmp(&(y[0] * y[1])));

    let mut s = vec![0];
    (0..n).for_each(|i| {
        let div = divide(&a, ans[i][1]);
        s = max_vec(&s, &div);
        a = multiply(&a, ans[i][0]);
    });

    println!("{}", vec_to_string(&s));
}

fn multiply(a: &[i64], b: i64) -> Vec<i64> {
    let mut result = vec![0; a.len() + 1];
    let mut carry = 0;
    for (i, &val) in a.iter().enumerate() {
        let prod = val * b + carry;
        result[i] = prod % 1_000_000_000;
        carry = prod / 1_000_000_000;
    }
    if carry > 0 {
        result[a.len()] = carry;
    } else {
        result.pop();
    }
    result
}

fn divide(a: &[i64], b: i64) -> Vec<i64> {
    let mut result = vec![0; a.len()];
    let mut remainder = 0;
    for (i, &val) in a.iter().rev().enumerate() {
        let current = remainder * 1_000_000_000 + val;
        result[a.len() - 1 - i] = current / b;
        remainder = current % b;
    }
    while result.len() > 1 && result.last() == Some(&0) {
        result.pop();
    }
    result
}

fn max_vec(a: &[i64], b: &[i64]) -> Vec<i64> {
    match a.len().cmp(&b.len()) {
        std::cmp::Ordering::Greater => return a.to_owned(),
        std::cmp::Ordering::Less => return b.to_owned(),
        std::cmp::Ordering::Equal => (),
    }
    for (x, y) in a.iter().rev().zip(b.iter().rev()) {
        match x.cmp(y) {
            std::cmp::Ordering::Greater => return a.to_owned(),
            std::cmp::Ordering::Less => return b.to_owned(),
            std::cmp::Ordering::Equal => (),
        }
    }
    a.to_owned()
}

fn vec_to_string(a: &[i64]) -> String {
    let mut result = a.iter().rev().map(|x| format!("{:09}", x)).collect::<Vec<_>>().join("");
    while result.len() > 1 && result.starts_with('0') {
        result.remove(0);
    }
    result
}
