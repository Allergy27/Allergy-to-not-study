//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/bisect_left.rs
//@data      2024/03/07 19:47:18
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
    let (_, _) = cin().split_whitespace().fold((0, 0), |x, y| (x.1,y.parse::<usize>().unwrap()));

    let qwq = cin().split_whitespace().map(|s| s.parse().unwrap()).collect::<Vec<i32>>();
    let qvq = cin().split_whitespace().map(|s| s.parse().unwrap()).collect::<Vec<i32>>();
    qvq.iter().for_each(|&x|print!("{} ",bisect_left(qwq.clone(), x)));
}
fn bisect_left<T: Ord>(nums: Vec<T>, x: T) -> usize {
    let (mut l, mut r) = (0, nums.len());
    while l < r {
        let m = (l + r) >> 1;
        if nums[m] > x {
            r = m;
        } else {
            l = m + 1;
        }
    }
    l
}
