//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/lis.rs
//@data      2023/12/22 17:26:17
fn _cin() -> String {
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

}
fn _prtl_lis<T: Ord + Copy>(nums: Vec<T>) -> Vec<usize> {
    nums.iter()
        .fold((vec![], vec![]), |mut x, &y| {
            if x.0.is_empty() || x.0[x.0.len() - 1] < y {
                x.0.push(y)
            } else {
                let i = x.0.partition_point(|&t| t < y);
                x.0[i] = y;
            }
            x.1.push(x.0.len());
            x
        })
        .1
}
fn _lis<T: Ord + Copy>(nums: Vec<T>) -> Vec<T> {
    nums.iter().fold(vec![], |mut x, &y| {
        if x.is_empty() || x[x.len() - 1] < y {
            x.push(y)
        } else {
            let i = x.partition_point(|&v| v < y);
            x[i] = y;
        }
        x
    })
}
