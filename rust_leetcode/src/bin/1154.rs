//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/1154.rs
//@data      2023/12/31 12:19:38

fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    println!("{}", day_of_year(String::from("2019-01-09")));
}

fn day_of_year(date: String) -> i32 {
    let mut day_count = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30];
    let date: Vec<usize> = date.split('-').map(|x| x.parse().unwrap()).collect();
    if date[0] % 400 == 0 || date[0] % 100 != 0 && date[0] % 4 == 0 {
        day_count[2] += 1
    }
    (0..date[1]).fold(0, |x, y| x + day_count[y]) + date[2] as i32
}
