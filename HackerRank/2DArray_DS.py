def hourglassSum(arr):
    summ=[]
    lenght=len(arr)-2
    for i in range(0,lenght):
        for j in range(0,lenght):
            print(i,j)
            summ.append(arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2])
    return max(summ)
if __name__ == '__main__':

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

