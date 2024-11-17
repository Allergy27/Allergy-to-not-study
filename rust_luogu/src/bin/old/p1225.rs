//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p1225.rs
//@data      2024/11/13 10:57:56
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
    let mut num_a = vec![1, 0];
    let mut num_b = vec![1, 0];
    let add = |a: &Vec<i32>, b: &Vec<i32>, l: usize| {
        let n = l + (a[l - 2] + b[l - 2]) as usize / 10;
        let mut tmp = 0;
        let mut ans = vec![0; n + 1];
        for i in 0..n {
            ans[i] = (a[i] + b[i] + tmp) % 10;
            tmp = (a[i] + b[i] + tmp) / 10;
        }
        (ans, n)
    };
    let mut l = 2;
    let n = cin!(usize);
    for _ in 2..=n {
        let tmp = num_b.clone();
        (num_b, l) = add(&num_a, &num_b, l);
        num_a = tmp;
    }
    num_b.into_iter().rev().skip_while(|x| *x == 0).for_each(|x| print!("{x}"));
    println!();
}
