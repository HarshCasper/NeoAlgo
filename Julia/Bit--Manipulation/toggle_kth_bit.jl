# Julia program to toggle the k-th bit of a number.
function toggle(num, k)
    return (num ⊻ (1 << (k-1)))
end

print("Enter the number: ")
num = readline()
num = parse(Int, num)
print("Enter the value of k(where you need to toggle the k'th bit): ")
k = readline()
k = parse(Int, k)
new_num = toggle(num, k)
println("The given number, after toggling the k-th bit is $new_num.")

"""
Time Complexity: O(1)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 24
Enter the value of k(where you need to toggle the k'th bit): 3
The given number, after toggling the k-th bit is 28.

SAMPLE 2
Enter the number: 33
Enter the value of k(where you need to toggle the k'th bit): 12
The given number, after toggling the k-th bit is 2081.
"""
