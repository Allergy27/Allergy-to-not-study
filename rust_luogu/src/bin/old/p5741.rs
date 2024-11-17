//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p5741.rs
//@data      2024/10/28 02:27:09
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
struct Student {
    name: String,
    chinese: i32,
    math: i32,
    english: i32,
}

fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let mut qwq = Vec::with_capacity(n);
    for _ in 0..n {
        let input = cin();
        let mut cin = input.split_whitespace();
        let student = Student {
            name: cin.next().unwrap().to_string(),
            chinese: cin.next().unwrap().parse::<i32>().unwrap(),
            math: cin.next().unwrap().parse::<i32>().unwrap(),
            english: cin.next().unwrap().parse::<i32>().unwrap(),
        };
        qwq.push(student);
    }
    for i in 0..n {
        for j in i + 1..n {
            if qwq[i].math.abs_diff(qwq[j].math) <= 5
                && qwq[i].chinese.abs_diff(qwq[j].chinese) <= 5
                && qwq[i].english.abs_diff(qwq[j].english) <= 5
                && (qwq[i].math + qwq[i].chinese + qwq[i].english)
                    .abs_diff(qwq[j].english + qwq[j].chinese + qwq[j].math)
                    <= 10
            {
                println!("{} {}", qwq[i].name, qwq[j].name);
            }
        }
    }
}
