//!
//! # Bead Sort
//!
//! Bead Sort (also called Gravity Sort) is a sorting algorithm which is inspired from natural
//! phenomenons that occur due to gravity, like falling of beads.
//!

fn bead_sort<T>(arr: Vec<T>)
where
    T: Ord
{
    let max = arr.iter().max().unwrap();
    let mut beads = Vec::with_capacity(max * arr.len());
}

fn main() {

}
