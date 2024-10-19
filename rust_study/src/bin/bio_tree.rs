//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/bio_tree.rs
//@data      2023/12/15 10:21:57

use std::{cell::RefCell, rc::Rc};

pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut qwq = TreeNode::new(0);
    let k1 = TreeNode::new(2);
    let k2 = TreeNode::new(3);
    qwq.left = Some(Rc::new(RefCell::new(k1)));
    qwq.right = Some(Rc::new(RefCell::new(k2)));
    //dfs(Some(Rc::new(RefCell::new(qwq))));
    println!("{}", 123)
}

fn _dfs(node1: &Option<Rc<RefCell<TreeNode>>>, node2: &Option<Rc<RefCell<TreeNode>>>, d_s: bool) {
    if let (Some(node1), Some(node2)) = (node1, node2) {
        let (mut node1, mut node2) = (node1.borrow_mut(), node2.borrow_mut());
        if d_s {
            std::mem::swap(&mut node1.val, &mut node2.val);
        }
        _dfs(&node1.left, &node2.right, !d_s);
        _dfs(&node1.right, &node2.left, !d_s);
    }
}
