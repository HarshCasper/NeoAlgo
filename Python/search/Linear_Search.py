def linearSearch(arr, x):
    pos = -1
    for i in range(len(arr)):
        if arr[i] == x:
            pos = i
            print("Found at {}".format(pos))
            
    if pos == -1:
        print("Not Found")