#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    /*
        References: https://codeforces.com/contest/1168/submission/54903799
        https://codeforces.com/contest/1158/submission/55060881
        https://codeforces.com/blog/entry/67391 // having some excellent tutorials on for's, ownership and borrows
    */
    // let n = scan.next::<usize>(); // read a number
    // let str = scan.next::<String>(); // read a string
    // let a: Vec<i32> = (0..n).map(|_| scan.next()).collect(); // read an array
    // println!("hello world {}", n); // write a value
    /* declaration:
        let mut empty: Vec<i32> = vec![]; // create an empty vector type i32
        let mut ans = Vec::with_capacity(n + 1);
        for _ in 0..n {
            let elem = scan.next::<f64>();
            v.push(elem)
        }
    */
    /*
        let min_value = *a.iter().min().unwrap(); // get min value of an array
    */
    // let n = 42;
    // writeln!(out, "hello world").ok();
    // writeln!(out, "").ok)(); // write an empty line
    let n = scan.next::<usize>();
    let mut empty: Vec<i32> = vec![]; // create an empty vector type i32
    for _ in 0..n {
        let elem = scan.next::<i32>();
        empty.push(elem)
    }
    // for i in 0..n {
    //     write!(out, "{} ", empty[i]).ok();
    // }
    // writeln!(out, "").ok();
    // for i in 0..n {
    //     write!(out, "{} ", empty[i]).ok();
    // }
    for elem in &empty {
        write!(out, "{} ", elem).ok();
    }
    for elem in &mut empty {
        *elem = 5;
    }
    writeln!(out, "").ok();
    for i in 0..n {
        write!(out, "{} ", empty[i]).ok();
    }
}