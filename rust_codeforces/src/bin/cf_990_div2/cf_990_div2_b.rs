//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_990_div2_b.rs
//@data      2024/12/03 14:33:08
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
    let mut s = cin!().bytes().collect::<Vec<_>>();
    let mut qwq = vec![0; 26];
    for x in &s {
        qwq[(x - b'a') as usize] += 1;
    }
    let mut mx = 0;
    let mut mx_id = 0;
    let mut mi = 1_000_000;
    let mut mi_id = 0;
    for (i, x) in qwq.iter().enumerate() {
        if *x >= mx {
            mx = *x;
            mx_id = i;
        }
        if *x < mi && *x != 0 {
            mi = *x;
            mi_id = i;
        }
    }
    for i in 0..n {
        if s[i] == b'a' + mi_id as u8 {
            s[i] = b'a' + mx_id as u8;
            break;
        }
    }
    s.iter().for_each(|x| print!("{}", *x as char));
    println!()
}
