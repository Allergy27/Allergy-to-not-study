//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_380_c.rs
//@data      2024/11/16 20:07:50
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
    let (_, k) = cin!(usize, usize);
    let s = cin!();
    let mut qwq = Vec::new();
    let res = (s.bytes().next().unwrap() - b'0') as usize;
    let mut tmp = s.bytes().next().unwrap();
    let mut cot = 1;
    for c in s.bytes().skip(1) {
        if c != tmp {
            qwq.push((cot, tmp - b'0'));
            tmp = c;
            cot = 1;
        } else {
            cot += 1;
        }
    }
    qwq.push((cot, tmp - b'0'));
    // println!("{:?}", qwq);
    qwq.swap(2 * k - 1 - res, 2 * k - 2 - res);
    qwq.iter().for_each(|x| {
        for _ in 0..x.0 {
            print!("{}", x.1);
        }
    });
    println!()
}
