//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_992_div2_c.rs
//@data      2024/12/08 23:00:38
#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    }};
    ([char]) => {{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().chars().collect::<Vec<char>>()
    }};
    ([u8]) =>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().bytes().collect::<Vec<u8>>()
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
    let t = cin!(usize);
    let mut pow2 = [0u64; 41];
    pow2[0] = 1;
    for i in 1..=40 {
        pow2[i] = pow2[i - 1] << 1;
    }
    for _ in 0..t {
        let (n, mut k) = cin!(usize, u64);
        if n == 1 {
            if k > 1 {
                println!("-1")
            } else {
                println!("1")
            }
            continue;
        }
        let mx_cot = if n - 1 <= 40 { pow2[n - 1] } else { u64::MAX };
        if k > mx_cot {
            println!("-1");
            continue;
        }
        let mut op = vec![false; n + 1];
        for i in (2..=n).rev() {
            let half = if i - 2 <= 40 { pow2[i - 2] } else { u64::MAX };
            if k <= half {
                op[i] = true;
            } else {
                op[i] = false;
                k -= half;
            }
        }
        let mut dq = std::collections::VecDeque::new();
        dq.push_back(1);
        for i in 2..=n {
            if op[i] {
                dq.push_front(i);
            } else {
                dq.push_back(i);
            }
        }
        // println!("{:?}", dq);
        let mut ans = Vec::with_capacity(n);
        for &x in &dq {
            let val = n as u64 - x as u64 + 1;
            ans.push(val);
        }
        for (i, &val) in ans.iter().enumerate() {
            if i == n - 1 {
                println!("{}", val);
            } else {
                print!("{} ", val);
            }
        }
    }
}
