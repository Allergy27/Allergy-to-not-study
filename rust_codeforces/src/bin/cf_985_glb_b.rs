//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_985_glb_b.rs
//@data      2024/11/09 23:01:21
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
    let _ = cin!(i64);
    let a = cin!().chars().collect::<Vec<_>>();
    let b = cin!().chars().collect::<Vec<_>>();
    let mut one = 0;
    let mut zero = 0;

    for i in a {
        if i == '0' {
            one += 1;
        } else {
            zero += 1;
        }
    }

    if zero == 0 || one == 0 {
        println!("NO");
        return;
    }

    for i in b {
        if i == '1' {
            if one == 0 || zero == 0 {
                println!("NO");
                return;
            }
            one -= 1;
        } else {
            if one == 0 || zero == 0 {
                println!("NO");
                return;
            }
            zero -= 1;
        }
    }
    // let mut zz = 0;
    // let mut oz = 0;
    // let mut zl = 0;
    // let mut ol = 0;
    // for i in 0..n {
    //     if a[i as usize] == '0' {
    //         zl += 1;
    //         oz = oz.max(ol);
    //         ol = 0;
    //     } else {
    //         ol += 1;
    //         zl = zl.max(zz);
    //         zz = 0;
    //     }
    // }
    // for i in b {
    //     if i == '0' {
    //         if zz == 0 {
    //             println!("NO");
    //             return;
    //         }
    //         zz -= 1;
    //     } else if oz == 0 {
    //         println!("NO");
    //         return;
    //     } else {
    //         oz -= 1;
    //     }
    // }
    println!("YES");
}
