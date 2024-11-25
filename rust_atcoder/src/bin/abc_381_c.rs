//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_381_c.rs
//@data      2024/11/22 20:12:10
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
    let _ = cin!();
    let s = cin!().bytes().collect::<Vec<_>>();
    let mut stk = Vec::new();
    let mut tmp = Vec::new();
    let mut flag = 0;
    let mut ans = 0;
    let mut res = 0;
    for i in s {
        match flag {
            0 => {
                if i == b'1' {
                    stk.push(1);
                } else if i == b'/' {
                    tmp = stk.clone();
                    stk.clear();
                    flag = 1;
                } else {
                    stk.clear();
                }
            }
            1 => {
                if i == b'1' {
                    stk.push(1);
                    ans = ans.max(res);
                    res = 0;
                    flag = 0;
                } else if i == b'/' {
                    stk.clear();
                    ans = ans.max(res);
                    res = 0;
                    flag = 0;
                } else if i == b'2' && tmp.pop().is_some() {
                    res += 1;
                } else {
                    ans = ans.max(res);
                    res = 0;
                    flag = 0;
                }
            }
            _ => {}
        }
        // println!("{:?} || {:?} !! {} {}", stk, tmp, res, ans);
    }
    println!("{}", ans.max(res) * 2 + 1);
}
