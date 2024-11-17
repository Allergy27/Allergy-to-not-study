//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p2010.rs
//@data      2024/11/13 20:08:20
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
    // let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let nrev = |x: usize| {
        let mut tmp = 0;
        let mut cot = x;
        while cot > 0 {
            tmp = tmp * 10 + cot % 10;
            cot /= 10;
        }
        tmp
    };
    let check = |year: usize, res: usize| {
        let mut day_limit = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
        day_limit[1] += if year % 400 == 0 || year % 100 != 0 && year % 4 == 0 { 1 } else { 0 };
        0 < res / 100 && res / 100 <= 12 && res % 100 <= day_limit[res / 100 - 1]
    };

    assert_eq!(4201, nrev(1024));
    let a = cin!(usize);
    let b = cin!(usize);
    let ay = a / 10000;
    let by = b / 10000;
    let ans = (ay..=by).fold(0, |ans, x| {
        ans + (check(x, nrev(x)) && x * 10000 + nrev(x) >= a && x * 10000 + nrev(x) <= b) as usize
    });
    println!("{ans}");
}
