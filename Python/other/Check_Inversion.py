#Different Approaches to find the number of inverstion in a given list of number 
#Brute force take O(n^2) 
def BruteForce(listt):
    count=0
    for i in range(0,len(listt)-1):
        for j in range(1,len(listt)):
            if listt[i]> listt[j]:
                count+=1
    print("Number of inversion is "+count)
#Merge Sort O(n logn)
def CountInversions(arr):
    result=MergeSort(arr)
    return result[1]
def MergeSort(arr):
    if len(arr) == 1:
        return arr, 0
    else:
        a = arr[:int(len(arr)/2)]
        b = arr[int(len(arr)/2):]
        a, ai = MergeSort(a)
        b, bi = MergeSort(b)
        c = []
        i = 0
        j = 0
        inversions = 0 + ai + bi
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
            inversions += (len(a))
    c += a[i:]
    c += b[j:]
    return c, inversions
if __name__ == "__main__":
    print("Number of inversion is "+CountInversions([6,5,4,3,2,1]))
