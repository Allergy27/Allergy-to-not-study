//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_984_div3_f.rs
//@data      2024/11/06 00:06:30
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
fn solve() {
    let xor = |x: i64| match x % 4 {
        0 => x,
        1 => 1,
        2 => x + 1,
        3 => 0,
        _ => unreachable!(),
    };
    let find = |l: i64, r: i64| xor(r) ^ xor(if l > 0 { l - 1 } else { 0 });
    let (l, r, i, k) = cin!(i64, i64, i64, i64);
    let qwq = find(l, r);
    let stt = (l - k + ((1 << i) - 1)) >> i;
    let end = (r - k) >> i;
    if stt > end {
        println!("{}", qwq);
        return;
    }
    let n = end - stt + 1;
    let res = (find(stt, end) << i) | if n % 2 == 1 { k } else { 0 };
    println!("{}", qwq ^ res);
}
