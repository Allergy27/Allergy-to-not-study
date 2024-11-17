use std::io;
fn main() {
    let mut input1: String = String::new(); //用来读数组
    let mut input2: String = String::new(); //用来读最大高度
    let mut sum: i32 = 0;
    io::stdin().read_line(&mut input1).unwrap();
    let array: Vec<i32> = input1 //读取数组
        .split_whitespace()
        .map(|s: &str| s.parse().unwrap())
        .collect();
    io::stdin().read_line(&mut input2).unwrap();
    let capabl: i32 = input2.trim().parse::<i32>().expect("crazy!!") + 30;
    //下面是处理部分
    for _num in array.iter().filter(|x| x <= &&capabl) {
        sum += 1;
    }
    println!("{}", sum);
}
