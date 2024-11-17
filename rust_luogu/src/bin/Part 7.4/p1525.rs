//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1525.rs
//@data      2024/10/22 17:56:39
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    let k = (1..=4).fold(1, |ans, x| ans + (1..=x).product::<i32>());
    println!("{}", k);
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
            self.rel[x] ^= self.rel[tmp];
        }
        self.fa[x]
    }
    fn merge(&mut self, x: usize, y: usize, fx: usize, fy: usize) {
        self.fa[fy] = fx;
        self.rel[fy] = self.rel[x] ^ self.rel[y] ^ 1;
    }
}

fn solve() {
    let (n, m) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = vec![(0, 0, 0); m];
    for x in &mut qwq {
        *x = cin()
            .split_whitespace()
            .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));
    }
    qwq.sort_unstable_by(|a, b| b.2.cmp(&a.2));
    let mut uf = UFset::new(n);
    for &(a, b, w) in &qwq {
        let (fa, fb) = (uf.find(a), uf.find(b));
        if fa == fb {
            if uf.rel[a] == uf.rel[b] {
                println!("{}", w);
                return;
            }
        } else {
            uf.merge(a, b, fa, fb);
        }
    }
    println!("0")
}
