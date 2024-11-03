//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1601.rs
//@data      2024/11/03 20:45:27
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
    let a = cin!(String).chars().rev().collect::<Vec<_>>();
    let b = cin!(String).chars().rev().collect::<Vec<_>>();
    let mut c = Vec::new();
    let mut carry = 0;
    let mut i = 0;
    let n = a.len().max(b.len());
    while i < n {
        let now = if i < a.len() && i < b.len() {
            a[i] as u8 + b[i] as u8 - 2 * b'0'
        } else if i < a.len() {
            a[i] as u8 - b'0'
        } else {
            b[i] as u8 - b'0'
        } + carry;
        c.push(now % 10);
        carry = now / 10;
        i += 1;
    }
    if carry > 0 {
        c.push(carry);
    }
    c.iter().rev().for_each(|&x| print!("{}", x));
    println!()
}
