//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/edu_171_div2_d.rs
//@data      2024/10/29 07:25:04
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<i64>().unwrap();
    let qwq = cin().split_whitespace().map(|s| s.parse::<i64>().unwrap()).collect::<Vec<_>>();
    //Step 1: O(n)预处理
    let mut qaq1 = vec![0; n as usize + 1]; //前缀和
    for i in 0..n {
        qaq1[i as usize + 1] = qwq[i as usize] + qaq1[i as usize];
    }
    let s = |l: i64, r: i64| qaq1[r as usize] - qaq1[l as usize - 1];
    let mut all = 0;
    for i in 0..n {
        all += s(1, i + 1) * (n - i);
    }
    let mut qaq2 = vec![0; n as usize + 1]; //前缀和的前缀和
    let mut w = vec![all; n as usize + 1]; //b的前缀和 横向
    let mut h = vec![0; n as usize + 1]; //(n-i+1)*a_i的和 纵向
    for i in 1..=n {
        qaq2[i as usize] = qaq1[i as usize] + qaq2[i as usize - 1];
    }
    for i in (0..n).rev() {
        w[i as usize] = w[i as usize + 1] - qaq2[i as usize + 1];
    }
    for i in 0..n {
        h[i as usize + 1] = h[i as usize] + qaq1[i as usize + 1] * (n - i)
    }
    let t = |l: i64, r: i64| w[r as usize] - h[l as usize - 1] + (n - r - 1) * qaq2[l as usize - 1];
    // println!("{:?}", qaq1);
    // println!("{:?}", qaq2);
    // println!("{:?}", w);
    // println!("{:?}", h);
    println!("{:?}", t(1, 2));
    //Step 2: O(logn)分区间，O(1)求区间和，共q次，总复杂度O(n+qlogn)
    // let q = cin().parse::<i64>().unwrap();
    // let num = (0..=n).map(|i| (n + n - i + 1) * i / 2).collect::<Vec<_>>();
    // let fd = |x: i64| {
    //     if x != 0 {
    //         num[x as usize] - num[x as usize - 1]
    //     } else {
    //         0
    //     }
    // };
    // for _ in 0..q {
    //     let mut ans = 0;
    //     let (l, r) = cin()
    //         .split_whitespace()
    //         .fold((0, 0), |x, y| (x.1, y.parse::<i64>().unwrap()));
    //     let nl = num.partition_point(|&x| x < l) as i64;
    //     let nr = num.partition_point(|&x| x < r) as i64;
    //     let (fnl, fnr) = (fd(nl), fd(nr));
    //     println!("{} {}", nl, nr);
    //     if nl == nr {
    //         println!("{}", t(nl, r + 1) - t(nl, l));
    //         ans += t(nl, r) - t(nl, l);
    //     } else {
    //         ans += t(fnr - l, fnl);
    //         for i in nl..nr - 1 {
    //             ans += t(i, n);
    //         }
    //         ans += t(nr, r);
    //     }
    //     println!("{}", ans);
    // }
}
