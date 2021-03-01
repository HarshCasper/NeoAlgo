use std::io::{self, prelude::*, stdin, BufReader, Stdin};
use std::str::{FromStr, SplitWhitespace};

/// Scanner struct, used to get C++-style input. It is used to avoid writing boilerplate code again
/// and again.
pub struct Scanner<R> {
    input: BufReader<R>,
    buf_iter: SplitWhitespace<'static>,
    buf_str: String,
}

impl<R: io::Read> Scanner<R> {
    /// Create a new `Scanner` from given `reader`.
    pub fn new(reader: R) -> Self {
        Scanner {
            input: BufReader::new(reader),
            buf_iter: "".split_whitespace(),
            buf_str: String::new(),
        }
    }

    /// Get from `reader` the next input till whitespace, and parse it as type `T`.
    pub fn get<T: FromStr>(&mut self) -> Option<T> {
        self.buf_iter.next()?.parse().ok()
    }

    /// Get from `reader` the next whitespace-seperated inputs in form of `Vec<T>`.
    pub fn get_vec<T: FromStr>(&mut self, len: usize) -> Option<Vec<T>> {
        let mut input = Vec::with_capacity(len);

        for _ in 0..len {
            input.push(self.get()?);
        }

        Some(input)
    }

    /// Get from `reader` the next whitespace-seperated inputs in form of `[T; N]`.
    pub fn get_array<T: FromStr, const N: usize>(&mut self) -> Option<[T; N]> {
        // SAFETY: as we are not accessing memory before initializing it, this is safe. It will
        // immediately be initialized in the following for loop.
        let mut input: [T; N] = unsafe { std::mem::MaybeUninit::uninit().assume_init() };

        for i in 0..N {
            input[i] = self.get()?;
        }

        Some(input)
    }
}

/// Create a new `Scanner` with `reader` as stdin.
pub fn stdin_scanner() -> Scanner<Stdin> {
    Scanner::new(stdin())
}

impl<R: io::Read> Iterator for Scanner<R> {
    type Item = &'static str;

    fn next(&mut self) -> Option<Self::Item> {
        match self.buf_iter.next() {
            None => {
                self.input.read_line(&mut self.buf_str).ok()?;
                // SAFETY: `self.buf_str` lives as long as `self`, and thus `self.buf_iter` which
                // is a pointer to `self.buf_str` won't outlive to the thing it points to, that is,
                // `self.buf_str`.
                self.buf_iter = unsafe { std::mem::transmute(self.buf_str.split_whitespace()) };
                self.buf_iter.next()
            }
            token => token,
        }
    }
}
