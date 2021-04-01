def negative_elements(arr):
    listofnegative = []
    listofpoistive = []
     
    for i in arr:
        if i < 0:
            listofnegative.append(i)
        else:
            listofpoistive.append(i)
        

        Total = listofnegative+listofpoistive

    print(Total) 




arr = list(map(int,input("Enter the Number:").split()))
negative_elements(arr)

'''
Time complexcity  = O(n)
space complexcity = O(n)

INPUT 
Enter the Number:-12 11 -13 -5 6 -7 5 -3 -6

OUTPUT
[-12, -13, -5, -7, -3, -6, 11, 6, 5] 

'''