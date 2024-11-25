//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/codeTon_b.rs
//@data      2024/11/23 22:43:39
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
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let s = cin!().chars().collect::<Vec<_>>();
    // let s = cin!().bytes().collect::<Vec<_>>();
    // let mut qwq = [0; 26];
    // for (i, x) in s.iter().enumerate() {
    //     if qwq[(*x - b'a') as usize] > 0 {
    //         s.iter().take(i).skip(qwq[(*x - b'a') as usize]).for_each(|x| print!("{}", *x as char));
    //         println!("{}", *x as char);
    //         return;
    //     }
    //     qwq[(*x - b'a') as usize] = i;
    // }
    let n = s.len();
    for i in 0..n {
        if i + 1 < n && s[i] == s[i + 1] {
            println!("{}{}", s[i], s[i]);
            return;
        } else if i + 2 < n && s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2] {
            println!("{}{}{}", s[i], s[i + 1], s[i + 2]);
            return;
        }
    }
    println!("-1");
}
