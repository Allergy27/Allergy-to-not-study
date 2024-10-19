//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/left_class.rs
//@data      2024/10/19 16:23:50
fn _cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = 20;
    let mut a = vec![0; n + 1]; //教授
    let mut b = vec![0; n + 1]; //学生
    for i in 1..=n {
        //教授点名时机
        for j in 1..=n {
            //学生翘课时机
            if i == j {
                //教授点名时机与学生翘课时机相同时
                a[i] = 1;
                b[i] = -1;
            } else {
                a[i] = 0;
                b[i] = 1;
            }
        }
    }
    for i in 1..=n {
        if a[i] > b[i] {
            print!("{} ", i);
        }
    }
}
