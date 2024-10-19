//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/1599.rs
//@data      2024/01/01 14:03:02
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let qwq = vec![10, 10, 1, 0, 0];
    let b = 4;
    let r = 4;
    println!("{}", min_operations_max_profit(qwq, b, r));
}
fn min_operations_max_profit(customers: Vec<i32>, boarding_cost: i32, running_cost: i32) -> i32 {
    let mut qwq = (-1, 0);
    let mut res = (0, 0); //准备登机的 登机了的
    let n = customers.len();
    for (i, &x) in customers.iter().enumerate() {
        res.0 += if i < n { x } else { 0 };
        res = (res.0 - 4.min(res.0), res.1 + 4.min(res.0));
        let k = res.1 * boarding_cost - (i as i32 + 1) * running_cost;
        if qwq.1 < k {
            qwq = (i as i32 + 1, k)
        }
    }
    if res.0 > 0 {
        let k = n as i32 + res.0 / 4;
        res = (res.0 % 4, res.1 + res.0 - res.0 % 4);
        if qwq.1 < res.1 * boarding_cost - k * running_cost {
            qwq = (k, res.1 * boarding_cost - k * running_cost);
        }
        if res.0 > 0 && qwq.1 < (res.1 + res.0) * boarding_cost - (k + 1) * running_cost {
            qwq = (
                k + 1,
                (res.1 + res.0) * boarding_cost - (k + 1) * running_cost,
            )
        }
    }
    qwq.0
}
