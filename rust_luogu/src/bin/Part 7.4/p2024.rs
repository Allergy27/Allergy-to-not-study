//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p2024.rs
//@data      2024/10/22 21:28:33
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
struct UFset {
    fa: Vec<usize>,
    rel: Vec<usize>,
}
impl UFset {
    fn new(n: usize) -> Self {
        Self {
            fa: (0..=n).collect::<Vec<_>>(),
            rel: vec![0; n + 1],
        }
    }
    fn find(&mut self, x: usize) -> usize {
        if x != self.fa[x] {
            let tmp = self.fa[x];
            self.fa[x] = self.find(self.fa[x]);
            self.rel[x] = (self.rel[x] + self.rel[tmp]) % 3;
        }
        self.fa[x]
    }
    fn merge(&mut self, x: usize, y: usize, f: usize) {
        let (fx, fy) = (self.find(x), self.find(y));
        self.fa[fx] = fy;
        self.rel[fx] = (3 - self.rel[x] + self.rel[y] + f - 1) % 3; //f为1,同类，f为2，x吃y
    }
}

fn solve() {
    let (n, k) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = UFset::new(n);
    let ans = (0..k).fold(0, |ans, _| {
        let (f, a, b) = cin()
            .split_whitespace()
            .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));
        if a > n || b > n {
            return ans + 1;
        }
        //放进来了
        if qwq.find(a) == qwq.find(b) {
            //b吃a或同类
            if qwq.rel[a] != (qwq.rel[b] + f - 1) % 3 {
                return ans + 1;
            }
        } else {
            qwq.merge(a, b, f);
        }
        ans
    });
    println!("{}", ans);
}
