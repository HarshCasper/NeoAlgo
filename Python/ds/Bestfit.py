"""
The best fit strategy will not allocate a block of size > N , as it is found in the first-fit method;
instead it will continue searching to find a suitable block so that the block size is closer to the block size of request.
The below program is an implementation of best fit algorithm using array data structure.
"""

# Block class is used as the fixed memory blocks for allocation
class Block:
    def __init__(self):
        self.size = 0
        self.ID = 0
        self.fragment = 0


# process class is used for allocating memory for the requesting processes
class process:
    def __init__(self):
        self.Num = 0
        self.size = 0
        self.block = None


# initialiseBlocks function initializes all the blocks with sizes and id
def initialiseBlocks(arr, sizes, n):
    for i in range(n):
        arr[i].size = sizes[i]
        arr[i].fragment = sizes[i]
        arr[i].ID = i + 1


# printResult function prints the result of the memory allocation strategy
def printResult(arr2, numOfProcess):
    print(
        "Process No            Process Size          Block ID          Block Size         Block Fragment"
    )
    for i in range(numOfProcess):
        print(
            str(arr2[i].Num)
            + "                     "
            + str(arr2[i].size)
            + "                     "
            + str(arr2[i].block.ID)
            + "                     "
            + str(arr2[i].block.size)
            + "                     "
            + str(arr2[i].block.fragment)
        )


# bestfit function allocates memory to processes using bestfit allocation algorithm
def bestfit(arr, sizes, n, arr2, numOfProcess):
    minBlock = Block()
    for i in range(numOfProcess):
        min = 100
        for j in range(n):
            if arr2[i].size <= arr[j].fragment and arr[j].fragment < min:
                min = arr[j].fragment
                minBlock = arr[j]
        minBlock.fragment = minBlock.fragment - arr2[i].size
        arr2[i].block = Block()
        arr2[i].block.size = minBlock.size
        arr2[i].block.ID = minBlock.ID
        arr2[i].block.fragment = minBlock.fragment
    print("Best Fit Allocation")
    printResult(arr2, numOfProcess)


# Driver code
if __name__ == "__main__":
    sizes = [60, 20, 12, 35, 64, 42, 31, 35, 40, 50]
    arr = []
    for i in range(10):
        arr.append(Block())
    initialiseBlocks(arr, sizes, 10)
    numOfProcess = int(
        input("Enter the number of process for memory to be allocated : ")
    )
    print("Enter the sizes required by the processes in the order of requirement")
    psize = list(map(int, input().split(" ")))
    arr2 = []
    for i in range(numOfProcess):
        arr2.append(process())
        arr2[i].size = psize[i]
        arr2[i].Num = i + 1
    bestfit(arr, sizes, 10, arr2, numOfProcess)

"""
Sample I/O:

Enter the number of process for memory to be allocated : 5
Enter the sizes required by the processes in the order of requirement
12 11 10 5 23
Best Fit Allocation
Process No            Process Size          Block ID          Block Size         Block Fragment
1                     12                     3                     12                     0
2                     11                     2                     20                     9
3                     10                     7                     31                     21
4                     5                     2                     20                     4
5                     23                     4                     35                     12

Time complexity : O(n)
space complexity : O(n)

"""
