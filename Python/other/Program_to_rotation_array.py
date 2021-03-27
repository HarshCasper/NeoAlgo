def array_rotation(): 
    save = []
    rest_arr = []
    for i in arr:
        if i == Start_element or i < Start_element:
            save.append(i)
        else:
            rest_arr.append(i)

    rest_arr.extend(save)
    print('rest arry =', rest_arr)

arr = list(input("Enter the no. elements:\n").split())
Start_element = input("Stating from which element:\n")
ending_element = input("Enter the ending element:\n")
array_rotation()

'''
>>Time & Space Complexity is O(n) 

INPUT

>>Enter the no. elements:
  1 2 3 4 5 6 7
>>Stating from which element:
  2  
>>Enter the ending element:
  7

OUTPUT 
>>rest arry = ['3', '4', '5', '6', '7', '1', '2']


'''