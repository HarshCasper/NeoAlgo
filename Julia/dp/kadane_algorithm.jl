""" Julia program to find the maximum sum of a  contigous subarray of an array

We can solve this problem using the infamous Kadane Algorithm
"""

function kadane_algo(arr, n)
    max_till_now = arr[1]
    final_max = arr[1]
    for i in 2:n
        max_till_now = max(arr[i], max_till_now+arr[i])
        final_max = max(final_max, max_till_now);
    end
    return final_max
end

print("What is the length of the array? ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("No numbers present in the array!!!")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())]
sum = kadane_algo(arr, n)
print("The maximum sum of contigous subarray is $sum")



"""
Time Complexity - O(n), where 'n' is the size of the array
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I
What is the length of the array? 9
Enter the numbers: -4 -3 32 -3 22 2 -22 2 2   
The maximum sum of contigous subarray is 53

"""
