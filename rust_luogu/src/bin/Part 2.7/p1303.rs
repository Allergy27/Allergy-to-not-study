//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1303.rs
//@data      2024/11/03 20:50:14
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
    let a = cin!().chars().rev().collect::<Vec<_>>();
    let b = cin!().chars().rev().collect::<Vec<_>>();
    let mut carry = 0;
    let lena = a.len();
    let lenb = b.len();
    let mut c = vec![0; lena + lenb];
    for i in 0..lena {
        for j in 0..lenb {
            c[i + j] += (a[i] as u32 - 48) * (b[j] as u32 - 48);
        }
    }
    for elem in &mut c {
        *elem += carry;
        carry = *elem / 10;
        *elem %= 10;
    }
    let x = c.iter().rev().skip_while(|&&x| x == 0).map(|&x| (x as u8 + b'0') as char);
    let mut s = String::new();
    for p in x {
        s.push(p);
    }
    println!("{}", if s.is_empty() { "0" } else { &s });
}
