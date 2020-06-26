def diagonalDifference(arr):
    diagsum1=diasum2=0
    for i in range (0,len(arr)):
        for j in range (0,len(arr)):
            if i==j:
                diagsum1+=arr[i][j]
            if i+j==len(arr)-1:
                diasum2+=arr[i][j]
    return(abs(diagsum1-diasum2))
