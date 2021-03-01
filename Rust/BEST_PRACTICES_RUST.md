## Introduction

Programming style is about how we organize and document our code. A program which is written following a consistent style is easier to read, debug and maintain.

A program may be written only once, but is read many times:

- During debugging
- When updating the program
- When trying to understand the code
- Anything that makes a program more readable and understandable saves lots of time.

Some of the often-used industry coding standards.

## Writing Readable Code

The Rust code in this repository follows the Rust styling guide. But you don't need to worry too much about what exact guidlines are, just always run `cargo-fmt` and `cargo-check` on your code once before submitting your code. From the root dir of the cargo project run:

```
cargo fmt && cargo check
```

and remove and warnings it shows. For example, if I want to format the `blockchain` project's code, I will run the above command from the `blockchain` directory.

Some project specific guidlines:
- Currently we do not plan to use any external library, and thus do not add any dependencies in the `Cargo.toml`.
- Avoid [`unsafe`](https://doc.rust-lang.org/book/ch19-01-unsafe-rust.html) code. If ever using unsafe code, add a comment before it explaining why it's safe/necesary marked `SAFETY` :
```rust
// SAFETY: explain why unsafe code is not unsafe and/or necesary
unsafe {
	/* some unsafe code */
}
```
- Use the latest stable compiler.



## Organising Code

The Rust code is devided into several cargo projects, each corresponding to type of algorithms it contains. Each project is further devided into seperate files, each containing a particular algorithm. To run a particular algorithm, go to it's particular project dir and run
```
cargo run --bin <algorithm>
```

For example, I want to run Kadane's Algorithm which is in `cp`, I will from the `cp` directory run
```
cargo run --bin kadane
```

When adding a new algorithm, modify the `Cargo.toml` file of the corresponding cargo project.

For example, if I want to add Kadane's Algorithm, I will add the following to [`cp/Cargo.toml`](cp/Cargo.toml) :
```toml
[[bin]]
name = "kadane"
path = "src/kadane.rs"
```

## Testing Code

Cargo has a great builtin unit testing framework, which we use. You are expected to write test cases for the algorithm you write using this, and check them using
```
cargo test
```
before submitting your code.

All the tests should be in `tests` directory, and the tests corresponding to a particular algorithm should have same name in `tests` folder.


## Further Reading

- [The Rust Book](https://doc.rust-lang.org/stable/book/) for learning Rust.
- [The Cargo Book](https://doc.rust-lang.org/cargo/) for learning about `cargo`.
- [Rust Reference](https://doc.rust-lang.org/cargo/) for in-depth documentation about Rust.
- [Rust Standard Library](https://doc.rust-lang.org/stable/std/)
