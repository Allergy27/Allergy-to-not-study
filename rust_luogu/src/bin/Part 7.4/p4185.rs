//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p4185.rs
//@data      2024/10/22 21:03:24
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
    sz: Vec<usize>,
}
impl UFset {
    fn new(n: usize) -> Self {
        Self {
            fa: (0..=n).collect::<Vec<_>>(),
            sz: vec![1; n + 1],
        }
    }
    fn find(&mut self, x: usize) -> usize {
        if x != self.fa[x] {
            self.fa[x] = self.find(self.fa[x]);
        }
        self.fa[x]
    }
    fn merge(&mut self, x: usize, y: usize) {
        let fx = self.find(x);
        let fy = self.find(y);
        self.fa[fy] = fx;
        self.sz[fx] += self.sz[fy];
    }
}

fn solve() {
    let (n, q) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = UFset::new(n);
    let mut relevant = Vec::new();
    let mut questions = Vec::new();
    (1..n).for_each(|_| {
        relevant.push(
            cin()
                .split_whitespace()
                .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap())),
        );
    });
    (0..q).for_each(|i| {
        let (a, b) = cin()
            .split_whitespace()
            .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
        questions.push((a, b, i))
    });
    relevant.sort_unstable_by(|a, b| b.2.cmp(&a.2));
    questions.sort_unstable_by(|a, b| b.0.cmp(&a.0));
    let mut ans = vec![0; q];
    let (mut l, mut r) = (0, 0);
    while l < q {
        while r < n - 1 && relevant[r].2 >= questions[l].0 {
            qwq.merge(relevant[r].0, relevant[r].1);
            // println!("?{}", relevant[r].2);
            // println!("!{}", questions[l].0);
            r += 1;
        }
        let fa = qwq.find(questions[l].1);
        ans[questions[l].2] = qwq.sz[fa];
        l += 1;
    }
    ans.iter().for_each(|x| println!("{}", x - 1));
}
