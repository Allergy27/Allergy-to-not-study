//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/link_list.rs
//@data      2024/01/03 12:26:05
struct ListNode<T> {
    val: T,
    next: Option<Box<ListNode<T>>>,
}

impl<T: std::fmt::Display> ListNode<T> {
    #[inline]
    fn new(val: T) -> Self {
        ListNode { next: None, val }
    }
    fn push(&mut self, val: T) {
        if let Some(x) = &mut self.next {
            x.push(val)
        } else {
            self.next = Some(Box::new(ListNode { val, next: None }))
        }
    }
    fn cout(&mut self) {
        //打印
        println!("{}", self.val);
        if let Some(x) = &mut self.next {
            x.cout()
        }
    }
    fn del(&mut self, pos: usize) {
        if let Some(x) = &mut self.next {
            if pos == 0 {
                self.next = x.next.take();
            } else {
                x.del(pos - 1)
            }
        }
    }
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}

fn solve() {
    let mut qwq = ListNode::new(1);
    let nums = [2, 3, 4, 5, 6, 7];
    nums.iter().for_each(|&x| qwq.push(x));
    let mut head = Some(Box::new(qwq));
    if let Some(x) = &mut head {
        x.del(1);
        x.cout()
    }
}
