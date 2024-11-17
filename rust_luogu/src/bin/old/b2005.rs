use std::io::stdin;
fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let input = input.trim();
    println!("  {0}\n {0}{0}{0}\n{0}{0}{0}{0}{0}", input);
}
