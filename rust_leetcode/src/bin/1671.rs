//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/1671.rs
//@data      2023/12/22 11:09:48

fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let qwq = vec![9, 8, 1, 7, 6, 5, 4, 3, 2, 1];
    println!("qwq");
    print!("{}", minimum_mountain_removals(qwq));
}

fn minimum_mountain_removals(nums: Vec<i32>) -> i32 {
    let l = f_find(&nums);
    let r = f_find(&nums.iter().rev().copied().collect::<Vec<i32>>());
    nums.len() as i32 + 1
        - l.iter()
            .zip(r.iter().rev())
            .filter(|(&p, &q)| p > 1 && q > 1)
            .fold(0, |x, (y, z)| x.max((y + z) as i32))
}
fn f_find(nums: &[i32]) -> Vec<usize> {
    nums.iter()
        .fold((vec![], vec![]), |mut x, &y| {
            if x.0.is_empty() || x.0[x.0.len() - 1] < y {
                x.0.push(y)
            } else {
                let i = x.0.partition_point(|&v| v < y);
                x.0[i] = y
            }
            x.1.push(x.0.len());
            x
        })
        .1
}
