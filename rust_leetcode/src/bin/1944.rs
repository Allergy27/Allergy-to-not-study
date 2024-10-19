//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/1994.rs
//@data      2024/01/17 13:01:22

fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let qwq = vec![10, 6, 8, 5, 11, 9];
    println!("{:?}", can_see_persons_count(qwq));
}

fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {
    let mut st = Vec::new();
    heights
        .iter()
        .rev()
        .map(|&h| {
            let mut ans = 0;
            while let Some(&x) = st.last() {
                ans += 1;
                if x > h {
                    break;
                }
                st.pop();
            }
            st.push(h);
            ans
        })
        .collect::<Vec<i32>>()
        .into_iter()
        .rev()
        .collect()
}
