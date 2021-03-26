def array_rotation(): 
    save = []
    rest_arr = []
    for i in arr:
        if i == d or i < d:
            save.append(i)
        else:
            rest_arr.append(i)

    rest_arr.extend(save)
    print('rest arry =', rest_arr)

arr = list(input().split())
d = input()
n = input()
array_rotation()