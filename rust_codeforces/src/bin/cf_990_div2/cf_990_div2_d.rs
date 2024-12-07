//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_990_div2_d.rs
//@data      2024/12/03 15:22:27
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
    let n = cin!(usize);
    let qwq = cin!([i64; n]);
    let mut stk = Vec::new();
    let mut b = Vec::new();
    for x in qwq {
        while !stk.is_empty() && x < *stk.last().unwrap() {
            b.push(stk.pop().unwrap() + 1);
        }
        stk.push(x);
    }
    b.sort_unstable();
    while !b.is_empty() && stk.last() > b.first() {
        b.push(stk.pop().unwrap() + 1);
    }
    b.sort_unstable();
    let mut qwq = stk;
    for x in b {
        qwq.push(x)
    }
    qwq.iter().for_each(|x| print!("{x} "));
    println!()
}
