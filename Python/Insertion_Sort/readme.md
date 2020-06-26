Insertion Sort

# Insertion sort is a very simple iterative algorithm that works

best for data that is already mostly sorted.

# The basic idea is that we select one element at a time and then

search for the correct place in the collection to insert it.

3. It Similar to how most people would arrange a hand of mixed poker cards

# Start with one card in your hand

# Pick the next card and insert it into its proper sorted order

# Repeat previous step for all cards

Insertion Sort: Analysis

# Outer-loop executes (n−1) times

# Number of times inner-loop is executed depends onthe input

# Best-case: the array is already sorted and(a[j] > next) is always false

    # No shifting of data is necessary

# Worst-case: the array is reversely sorted and(a[j] > next) is always true

    # Insertion always occur at the front

# Therefore, the best-case time is O(n)

# And the worst-case time is O(n2)

Strengths and Weaknesses of Insertion Sort

# The insertion sort algorithm is very uncomplicated to implement. Even though insertion sort is an O(n2)

algorithm,it’s also much more efficient in practice than other quadratic implementations such as bubble sort.

# There are more powerful algorithms, including merge sort and quicksort, but these implementations

are recursive and usually fail to beat insertion sort when working on small lists.

# That said, insertion sort is not practical for large arrays, opening the door to algorithms that

can scale in more efficient ways.
