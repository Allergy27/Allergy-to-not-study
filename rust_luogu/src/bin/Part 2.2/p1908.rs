//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1908.rs
//@data      2024/10/24 16:08:54
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    cin();
    let qwq = cin().split_whitespace().map(|s| vec![s.parse::<i32>().unwrap()]).collect::<Vec<_>>();
    let mut qwq = std::collections::VecDeque::from(qwq);
    let mut ans = 0i64;
    //判断逆序对
    let mut merge_sort = |x: Vec<i32>, y: Vec<i32>| -> Vec<i32> {
        let mut next = Vec::with_capacity(x.len() + y.len()); // 提前分配容量
        let (mut l, mut r) = (0, 0);
        while l < x.len() && r < y.len() {
            if x[l] > y[r] {
                ans += (x.len() - l) as i64;
                next.push(y[r]);
                r += 1;
            } else {
                next.push(x[l]);
                l += 1;
            }
        }
        next.extend_from_slice(&x[l..]);
        next.extend_from_slice(&y[r..]);
        next
    };
    let mut cnt = qwq.len();
    while qwq.len() != 1 {
        let x = if cnt != 1 { qwq.pop_front() } else { qwq.pop_back() }.unwrap();
        let y = qwq.pop_front().unwrap();
        cnt = if cnt < 2 { qwq.len() + cnt } else { cnt - 2 };
        qwq.push_back(merge_sort(x, y));
    }
    println!("{}", ans);
}
