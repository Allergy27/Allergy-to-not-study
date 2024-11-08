//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1039.rs
//@data      2024/11/07 16:47:53
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
    let (m, n, p) = cin!(usize, usize, usize);
    let mut say = std::collections::HashMap::new();
    let mut name = Vec::new();
    for i in 0..m {
        let na = cin!();
        name.push(na.clone());
        say.insert(na, i);
    }

    const WEEK: [&str; 7] = [
        "Today is Sunday.",
        "Today is Monday.",
        "Today is Tuesday.",
        "Today is Wednesday.",
        "Today is Thursday.",
        "Today is Friday.",
        "Today is Saturday.",
    ];
    //话
    let mut talk = Vec::with_capacity(p);
    for _ in 0..p {
        let input = cin!();
        let mut tmp = input.split(":");
        let a = tmp.next().unwrap().to_string();
        let b = tmp.next().unwrap().trim().to_string();
        let a = say.get(&a).unwrap();
        talk.push((*a, b));
    }
    // println!("{:?}", talk);

    let find = |bg: usize, day: usize| {
        //是否说真话
        let mut ck = vec![-1; m];
        //真话人数，假话人数
        let (mut tnum, mut fnum) = (0, 0);
        //是否冲突
        let mut check = |id: usize, flag: bool| {
            if ck[id] == -1 {
                ck[id] = flag as i32;
                if flag {
                    tnum += 1;
                } else {
                    fnum += 1;
                }
            } else {
                return ck[id] != flag as i32;
            }
            tnum > m - n || fnum > n
        };

        //检查p句话
        for (a, b) in &talk {
            if WEEK.contains(&b.as_str()) {
                if check(*a, WEEK[day] == b) {
                    return -1;
                }
            } else if b == "I am guilty." {
                if check(*a, bg == *a) {
                    return -1;
                }
            } else if b == "I am not guilty." {
                if check(*a, bg != *a) {
                    return -1;
                }
            } else if b.contains("is guilty.") {
                let tmp = b.split_whitespace().next().unwrap();
                let tmp = say.get(tmp).unwrap();
                if check(*a, bg == *tmp) {
                    return -1;
                }
            } else if b.contains("is not guilty.") {
                let tmp = b.split_whitespace().next().unwrap();
                let tmp = say.get(tmp).unwrap();
                if check(*a, bg != *tmp) {
                    return -1;
                }
            }
        }
        bg as i32
    };

    let mut ans = -1;

    //罪犯
    for i in 0..m {
        //星期几
        for j in 0..7 {
            let res = find(i, j);
            if ans == -1 {
                ans = res;
            } else if res != -1 && ans != res {
                //多个罪犯
                println!("Cannot Determine");
                return;
            }
        }
    }
    if ans == -1 {
        println!("Impossible");
    } else {
        println!("{}", name[ans as usize]);
    }
}
