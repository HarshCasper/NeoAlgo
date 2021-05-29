"""
The worst fit strategy is a reverse of the best-fit strategy. It allocates the largest block available in the storage list.
The idea behind worst-fit is to reduce the rate of production of small blocks. The below program is an implementation of
the worst fit algorithm using array data structure.
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


# worstfit function allocates memory to processes using worstfit allocation algorithm
def worstfit(arr, sizes, n, arr2, numOfProcess):
    maxBlock = Block()
    for i in range(numOfProcess):
        max = 0
        for j in range(n):
            if arr2[i].size <= arr[j].fragment and arr[j].fragment > max:
                max = arr[j].fragment
                maxBlock = arr[j]
        maxBlock.fragment = maxBlock.fragment - arr2[i].size
        arr2[i].block = Block()
        arr2[i].block.size = maxBlock.size
        arr2[i].block.ID = maxBlock.ID
        arr2[i].block.fragment = maxBlock.fragment
    print("Worst Fit Allocation")
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
    worstfit(arr, sizes, 10, arr2, numOfProcess)

"""
Sample I/O:

Enter the number of process for memory to be allocated : 5
Enter the sizes required by the processes in the order of requirement
10 20 11 12 13
Worst Fit Allocation
Process No            Process Size          Block ID          Block Size         Block Fragment
1                     10                     5                     64                     54
2                     20                     1                     60                     40
3                     11                     5                     64                     43
4                     12                     10                    50                     38
5                     13                     5                     64                     30

Time complexity : O(n)
space complexity : O(n)
"""
