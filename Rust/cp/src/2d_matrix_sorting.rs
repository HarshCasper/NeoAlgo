//!
//! # 2D Matrix Sorting
//!
//! In, 2D matrix sorting each row must be sorted, and the first element of each row should be
//! greater than the last element of the previous row. That is,
//!                  M[i][j] >= M[i][j - 1] and M[i][n - 1] <= M[i + 1][0],
//! where `M` is a n x n matrix.
//!
//! ## Input
//!  First line contains the length `n` of the square matrix.
//!  Next n lines contains the rows of the matrix `M`.
//!
//! ## Output
//!  Output the 2D-sorted matrix.
//!
//! ## Examples
//! ### Example 1:
//!  **Input**:
//!  ```
//!  2 2
//!  5 2
//!  1 3
//!  ```
//!  **Ouput**:
//!  ```
//!  2 2
//!  1 2
//!  3 5
//!  ```
//!
//! ### Example 2:
//!  **Input**:
//!  ```
//!  3 3
//!  5 8 7
//!  3 2 9
//!  1 4 6
//!  ```
//!  **Ouput**:
//!  ```
//!  1 2 3
//!  4 5 6
//!  7 8 9
//!  ```
//!
//!

use std::io::{stdin, stdout, prelude::*, BufWriter};
use std_input::Scanner;


/// Sorts the 2D matrix, returning a new Matrix.
fn matrix_sorting_2d<T>(input_matrix: &Vec<Vec<T>>) -> Vec<Vec<T>>
where
    T: Ord + Copy,
{
    // we don not check is each Vec<T> in `input_matrix` has exactly same number of elements as
    // this constraint is already enforced by the way we  take input
    let rows = input_matrix.len();
    let cols = input_matrix[0].len();

    // sorting
    let mut sorted_arr = input_matrix.iter().flatten().map(|x| *x).collect::<Vec<T>>();
    sorted_arr.sort();
    let mut sorted_matrix = vec![Vec::with_capacity(cols); rows];

    for i in 0..rows {
        for j in 0..cols {
            sorted_matrix[i].push(sorted_arr[i * cols + j]);
        }
    }

    sorted_matrix
}

fn main() {
    // getting input
    let stdin = stdin();
    let stdin = stdin.lock();
    let mut scanner = Scanner::new(stdin);
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    writer.write(b"Enter the dimensions of the matrix : ").unwrap();
    writer.flush().unwrap();
    let n: usize = scanner.get().unwrap();
    let m: usize = scanner.get().unwrap();

    let mut input_matrix: Vec<Vec<i32>> = vec![];

    writer.write(b"Enter the matrix row-wise :").unwrap();
    writer.flush().unwrap();
    println!();
    for _ in 0..n {
        input_matrix.push(scanner.get_vec(m).unwrap());
    }

    let sorted_matrix = &matrix_sorting_2d(&input_matrix);

    // printing as n x n matrix
    writer.write(b"\nThe sorted matrix :\n").unwrap();
    for row in 0..n {
        for col in 0..n {
            writer.write_fmt(format_args!("{}\t", sorted_matrix[row][col])).unwrap();
        }
        writer.write(b"\n").unwrap();
    }
    writer.flush().unwrap();
}
