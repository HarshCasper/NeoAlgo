"""
First fit is the simplest of all the storage allocation strategies.
Here the list of storages is searched and as soon as a free storage block of size >= N is found ,
the pointer of that block is sent to the calling program after retaining the residue space.Thus, for example,
for a block of size 5k , 2k memory will be sent to the caller . The below program is a simulation of the first fit strategy
using array data structure.
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


# firstfit function allocates memory to processes using firstfit allocation algorithm
def firstfit(arr, sizes, n, arr2, numOfProcess):
    initialiseBlocks(arr, sizes, n)
    for i in range(numOfProcess):
        for j in range(n):
            if arr2[i].size <= arr[j].fragment:
                arr[j].fragment -= arr2[i].size
                arr2[i].block = Block()
                arr2[i].block.size = arr[j].size
                arr2[i].block.ID = arr[j].ID
                arr2[i].block.fragment = arr[j].fragment
                break

    print("First Fit Allocation")
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
    firstfit(arr, sizes, 10, arr2, numOfProcess)


"""
Sample I/O:

Enter the number of process for memory to be allocated : 5
Enter the sizes required by the processes in the order of requirement
15 12 13 20 11
First Fit Allocation
Process No            Process Size          Block ID          Block Size         Block Fragment
1                     15                     1                     60                     45
2                     12                     1                     60                     33
3                     13                     1                     60                     20
4                     20                     1                     60                     0
5                     11                     2                     20                     9

Time complexity : O(n)
space complexity : O(n)
"""
