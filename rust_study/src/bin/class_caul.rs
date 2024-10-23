//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/class_caul.rs
//@data      2024/06/26 20:24:19

use std::{fmt::Display, iter::Peekable, str::Chars};

// 自定义 Result 类型
pub type Result<T> = std::result::Result<T, CompError>;

// 自定义错误类型
#[derive(Debug)]
pub enum CompError {
    Parse(String),
}

impl std::error::Error for CompError {}

impl Display for CompError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::Parse(s) => write!(f, "{}", s),
        }
    }
}

// Token类型 表示：数字、运算符号、括号
#[derive(Debug, Clone, Copy)]
enum Token {
    Number(i32),
    Plus,       // 加
    Minus,      // 减
    Multiply,   // 乘
    Divide,     // 除
    Power,      // 幂
    LeftParen,  // 左括号
    RightParen, // 右括号
}

impl Token {
    // 获取运算符的优先级
    fn precedence(&self) -> i32 {
        match self {
            Token::Plus | Token::Minus => 1,
            Token::Multiply | Token::Divide => 2,
            Token::Power => 3,
            _ => 0,
        }
    }

    // 根据当前运算符进行计算
    fn compute(&self, l: i32, r: i32) -> Option<i32> {
        match self {
            Token::Plus => Some(l + r),
            Token::Minus => Some(l - r),
            Token::Multiply => Some(l * r),
            Token::Divide => Some(l / r),
            Token::Power => Some(l.pow(r as u32)),
            _ => None,
        }
    }
}

// 将表达式解析成连续的Token
// 并通过 Iterator 返回，也可以通过 Peekable 接口获取
struct Tokenizer<'a> {
    tokens: Peekable<Chars<'a>>,
}

impl<'a> Tokenizer<'a> {
    fn new(comput: &'a str) -> Self {
        Self {
            tokens: comput.chars().peekable(),
        }
    }

    // 消除空白字符
    fn filter_whitespace(&mut self) {
        while let Some(&c) = self.tokens.peek() {
            if c.is_whitespace() {
                self.tokens.next();
            } else {
                break;
            }
        }
    }

    // 扫描数字
    fn scan_number(&mut self) -> Option<Token> {
        let mut num = String::new();
        while let Some(&c) = self.tokens.peek() {
            if c.is_numeric() {
                num.push(c);
                self.tokens.next();
            } else {
                break;
            }
        }

        match num.parse() {
            Ok(n) => Some(Token::Number(n)),
            Err(_) => None,
        }
    }

    // 扫描运算符号
    fn scan_operator(&mut self) -> Option<Token> {
        match self.tokens.next() {
            Some('+') => Some(Token::Plus),
            Some('-') => Some(Token::Minus),
            Some('*') => Some(Token::Multiply),
            Some('/') => Some(Token::Divide),
            Some('^') => Some(Token::Power),
            Some('(') => Some(Token::LeftParen),
            Some(')') => Some(Token::RightParen),
            _ => None,
        }
    }
}

// 实现 Iterator 接口，使 Tokenizer 可以通过 for 循环遍历
impl Iterator for Tokenizer<'_> {
    type Item = Token;

    fn next(&mut self) -> Option<Self::Item> {
        // 消除前面的空格
        self.filter_whitespace();
        // 解析当前位置的 Token 类型
        match self.tokens.peek() {
            Some(c) if c.is_numeric() => self.scan_number(),
            Some(_) => self.scan_operator(),
            None => None,
        }
    }
}

struct Compute<'a> {
    iter: Peekable<Tokenizer<'a>>,
}

impl<'a> Compute<'a> {
    pub fn new(src: &'a str) -> Self {
        Self {
            iter: Tokenizer::new(src).peekable(),
        }
    }

    // 计算表达式，获取结果
    pub fn eval(&mut self) -> Result<i32> {
        let result = self.caulculate()?;
        // 如果还有 Token 没有处理，说明表达式存在错误
        if self.iter.peek().is_some() {
            return Err(CompError::Parse("Unexpected end of expr".into()));
        }
        Ok(result)
    }

    //转逆波兰表达式
    fn mid_to_poland(&mut self) -> Result<Vec<Token>> {
        let mut operator_stack: Vec<Token> = vec![];
        let mut tokens = vec![];
        for token in self.iter.by_ref() {
            //转换主要代码
            match token {
                //操作数直接入表达式
                Token::Number(_) => tokens.push(token),
                //操作符依据优先级入栈
                Token::Plus | Token::Minus | Token::Multiply | Token::Divide | Token::Power => {
                    while let Some(&pri) = operator_stack.last() {
                        if pri.precedence() >= token.precedence() {
                            tokens.push(pri);
                            operator_stack.pop();
                        } else {
                            break;
                        }
                    }
                    operator_stack.push(token)
                }
                //左括号直接入栈
                Token::LeftParen => operator_stack.push(token),
                //右括号出栈至左括号
                Token::RightParen => {
                    while let Some(pri) = operator_stack.pop() {
                        match pri {
                            Token::LeftParen => break,
                            _ => tokens.push(pri),
                        }
                    }
                }
            }
        }
        //将剩下的操作符入表达式
        while let Some(x) = operator_stack.pop() {
            match x {
                //出现括号说明表达式有问题
                Token::LeftParen | Token::RightParen => {
                    return Err(CompError::Parse("Unexpected end of expr".into()));
                }
                _ => tokens.push(x),
            }
        }
        Ok(tokens)
    }

    fn caulculate(&mut self) -> Result<i32> {
        //计算后缀表达式
        let mut stack = vec![];
        for &s in self.mid_to_poland()?.iter() {
            if let Token::Number(num) = s {
                stack.push(num)
            } else {
                if stack.len() < 2 {
                    return Err(CompError::Parse("Unexpected end of expr".into()));
                }
                let b = stack.pop().unwrap();
                let a = stack.pop().unwrap();
                stack.push(s.compute(a, b).unwrap())
            }
        }
        Ok(stack.pop().unwrap())
    }
}

fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    let src = &cin();
    let mut caul = Compute::new(src);
    let result = caul.eval();
    println!("res = {:?}", result);
}
