//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\fibo.rs
//@data      2023/12/10 10:36:58

#[derive(Clone)]
struct Int {
    len: usize,
    qwq: Vec<i32>,
}
impl Int {
    fn new() -> Self {
        let mut qaq = vec![0; 52700];
        qaq[0] = 1;
        Int { len: 1, qwq: qaq }
    }
    fn show(self) {
        (0..self.len)
            .rev()
            .skip_while(|&x| self.qwq[x] == 0)
            .for_each(|i| print!("{}", self.qwq[i]));
        println!()
    }
    fn res(self, n: usize) -> Self {
        let mut ans = self.qwq.clone();
        let mut len = self.len;
        while len > n {
            ans.pop();
            len -= 1;
        }
        Self { len: n, qwq: ans }
    }
}
impl std::ops::Add for Int {
    type Output = Int;
    fn add(self, others: Int) -> Int {
        let mut max_len = self.len.max(others.len);
        let mut res = 0;
        let ans = self
            .qwq
            .iter()
            .zip(others.qwq.iter())
            .map(|(&x, &y)| {
                let pre = res;
                res = (x + y + res) / 10;
                (x + y + pre) % 10
            })
            .collect::<Vec<_>>();
        if ans[max_len] != 0 {
            max_len += 1
        }
        Int {
            len: max_len,
            qwq: ans,
        }
    }
}

fn main() {
    //let n = cin().parse::<usize>().unwrap();
    // println!(
    //     "{}",
    //     (1..20190324)
    //         .fold((1, 1, 1), |(x, y, z), _| (
    //             y.clone(),
    //             z.clone(),
    //             (x + y + z) % 100000
    //         ))
    //         .0
    // );
    (1..5)
        .fold((Int::new(), Int::new()), |(x, y), _| {
            (y.clone(), (x + y).res(5))
        })
        .0
        .show();
}
