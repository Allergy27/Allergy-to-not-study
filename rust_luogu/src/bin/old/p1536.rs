//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1536.rs
//@data      2024/01/17 11:19:48
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    loop {
        let mut ans = 0;
        let (a, b) = cin()
            .split_whitespace()
            .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
        if a == 0 {
            return;
        }
        let mut qwq = vec![0; a + 1];
        qwq.iter_mut().enumerate().skip(1).for_each(|(i, x)| *x = i);
        for _ in 1..=b {
            let (x, y) = cin()
                .split_whitespace()
                .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
            unity(x, y, &mut qwq)
        }
        for i in 1..=a {
            if find(i, &mut qwq) == i {
                ans += 1;
            }
        }
        println!("{}", ans - 1)
    }
}
fn find(k: usize, fa: &mut Vec<usize>) -> usize {
    if k != fa[k] {
        fa[k] = find(fa[k], fa);
    }
    fa[k]
}
fn unity(x: usize, y: usize, fa: &mut Vec<usize>) {
    let son_1 = find(x, fa);
    let son_2 = find(y, fa);
    fa[son_1] = son_2;
}
