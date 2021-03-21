# function to find maximum subarray sum
# using Kadane's algorithm
def max_subarray_sum(arr, n):
    final_max = arr[0]
    curr_max = arr[0]

    for i in range(1, n):
        curr_max = max(arr[i], curr_max + arr[i])
        final_max = max(final_max, curr_max)

    return final_max

def main():
    arr = [-13, -3, -25, -20, -3, -16, -23, -12, -5, -22, -15, -4, -7]
    max_sum = max_subarray_sum(arr, len(arr))
    print(f"The given array: {arr}")
    print(f"The maximum subarray sum is {max_sum}")

if __name__ == '__main__':
    main()