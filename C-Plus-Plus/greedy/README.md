# Greedy Algorithms (C++)

This folder contains implementations of popular **Greedy Algorithms** in C++.

Greedy algorithms make the locally optimal choice at each step with the hope of finding a global optimum.  
These are widely used in optimization problems.

---

## 📚 List of Implemented Problems

| No. | Problem | Description | Time Complexity |
|-----|----------|--------------|----------------|
| 1 | [Activity Selection](activity_selection.cpp) | Select maximum number of non-overlapping activities | O(n log n) |
| 2 | [Fractional Knapsack](fractional_knapsack.cpp) | Maximize total value in a knapsack allowing fractional items | O(n log n) |
| 3 | [Job Sequencing Problem](job_sequencing.cpp) | Schedule jobs to maximize profit within deadlines | O(n²) |
| 4 | [Huffman Encoding](huffman_encoding.cpp) | Generate Huffman codes for characters based on frequency | O(n log n) |

---

## 🧠 Concepts Used
- Sorting and Priority Queues
- Greedy Choice Property
- Optimal Substructure
- Min-Heap / Max-Heap usage

---

## 🛠 How to Run
```bash
g++ filename.cpp -o output
./output
