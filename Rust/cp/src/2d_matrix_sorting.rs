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
//!  2
//!  5 2
//!  1 3
//!  **Ouput**:
//!  2
//!  1 2
//!  3 5
//!
//! ### Example 2:
//!  **Input**:
//!  2
//!  5 8 7
//!  3 2 9
//!  1 4 6
//!  **Ouput**:
//!  1 2 3
//!  4 5 6
//!  7 8 9
//!
//!

use std_input::stdin_scanner;

fn main() {
    // getting input
    let mut scanner = stdin_scanner();
    let n: usize = scanner.get().unwrap();

    let mut input_matrix: Vec<Vec<i32>> = vec![];

    for _ in 0..n {
        input_matrix.push(scanner.get_vec(n).unwrap());
    }

    // sorting
    let mut sorted_arr = input_matrix.into_iter().flatten().collect::<Vec<i32>>();
    sorted_arr.sort();

    // printing as n x n matrix
    for row in 0..n {
        for col in 0..n {
            print!("{}\t", sorted_arr[row * n + col]);
        }
        println!();
    }
}
