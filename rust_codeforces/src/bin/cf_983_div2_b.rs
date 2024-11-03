//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_983_div2_b.rs
//@data      2024/11/04 00:11:56
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
    let (n, k) = cin!(usize, usize);
    if (k == 1) ^ (k == n) {
        println!("-1");
    } else {
        let rd = (n - k).min(k - 1);
        println!("{}", 2 * rd + 1);
        match (k - 1).cmp(&(n - k)) {
            std::cmp::Ordering::Equal => {
                (1..=n).for_each(|x| print!("{} ", x));
            }
            std::cmp::Ordering::Greater => {
                print!("1 ");
                (k - rd + 1..=n).for_each(|x| print!("{} ", x));
            }
            std::cmp::Ordering::Less => {
                (k - rd..=k + rd).for_each(|x| print!("{} ", x));
            }
        }
        println!()
    }
}
