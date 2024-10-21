//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_20_b.rs
//@data      2024/10/20 17:14:09
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (_, k) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<i64>().unwrap()));
    let mut qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i64>>();
    qwq.sort_unstable();
    let mut l = 0;
    let mut r = *qwq.iter().max().unwrap();
    let check = |x: i64| -> _ {
        let mut ans = 0;
        for &t in &qwq {
            if t >= x {
                ans += x;
            } else {
                ans += t;
            }
        }
        ans
    };
    let _ans = 0;
    while l < r {
        let mid = (l + r) / 2;
        if check(mid) >= k {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    let mut qvq = 0;
    let mut ans = 0;
    for &i in &qwq {
        if i < r {
            ans += i;
            qvq += i + 1;
            if ans >= k {
                qvq -= ans - k;
                break;
            }
        } else {
            ans += r;
            qvq += r;
            if ans >= k {
                qvq -= ans - k;
                break;
            }
        }
    }
    println!("{}", qvq);
}
