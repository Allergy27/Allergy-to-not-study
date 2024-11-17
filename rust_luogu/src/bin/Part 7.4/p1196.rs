//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1196.rs
//@data      2024/10/23 17:56:54
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    solve()
}

struct UFset {
    fa: Vec<usize>,
    hd: Vec<usize>,
    sz: Vec<usize>,
}
impl UFset {
    fn new(n: usize) -> Self {
        Self {
            fa: (0..=n).collect(),
            hd: vec![0; n + 1],
            sz: vec![1; n + 1],
        }
    }
    fn find(&mut self, x: usize) -> usize {
        if x != self.fa[x] {
            let tmp = self.fa[x];
            self.fa[x] = self.find(self.fa[x]);
            self.hd[x] += self.hd[tmp];
        }
        self.fa[x]
    }
    fn merge(&mut self, x: usize, y: usize) {
        let (fx, fy) = (self.find(x), self.find(y));
        // println!("fx:{},fy:{}", self.ed[fx], self.ed[fy]);
        self.fa[fx] = fy;
        self.hd[fx] += self.sz[fy];
        self.sz[fy] += self.sz[fx];
        self.sz[fx] = 0;
    }
}

fn solve() {
    let mut qwq = UFset::new(30000);
    let n = cin().parse::<usize>().unwrap();
    for _ in 0..n {
        let (s, b, c) = cin()
            .split_whitespace()
            .fold((String::new(), String::new(), String::new()), |x, y| {
                (x.1, x.2, y.to_string())
            });
        let x = b.parse::<usize>().unwrap();
        let y = c.parse::<usize>().unwrap();
        if s == "M" {
            qwq.merge(x, y);
        } else {
            let (fx, fy) = (qwq.find(x), qwq.find(y));
            if fx == fy {
                println!("{}", qwq.hd[x].abs_diff(qwq.hd[y]) - 1);
            } else {
                println!("-1");
            }
        }
    }
}
