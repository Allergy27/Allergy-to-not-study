//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1068.rs
//@data      2024/01/20 15:27:40
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
struct St {
    id: usize,
    score: usize,
}

fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (a, b) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut b = (b * 3).div_euclid(2);
    let mut qwq = Vec::new();
    for _ in 0..a {
        let (p, q) = cin()
            .split_whitespace()
            .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
        qwq.push(St { id: p, score: q })
    }
    qwq.sort_unstable_by(|y, x| {
        if x.score != y.score {
            x.score.cmp(&y.score)
        } else {
            y.id.cmp(&x.id)
        }
    });
    while qwq[b + 1].score == qwq[b].score {
        b += 1
    }
    println!("{} {}", qwq[b - 1].score, b+1);
    qwq[0..=b]
        .iter()
        .for_each(|x| println!("{} {}", x.id, x.score))
}
