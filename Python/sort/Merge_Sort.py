#Merge Sort
def merge(left, right):
    if not len(left) or not len(right):
        return left or right
 
    result = []
    value, value_2 = 0, 0
    while (len(result) < len(left) + len(right)):
        if left[value] < right[value_2]:
            result.append(left[value])
            value+= 1
        else:
            result.append(right[value_2])
            value_2+= 1
        if value == len(left) or value_2 == len(right):
            result.extend(left[value:] or right[value_2:])
            break
 
    return result
def mergesort(list):
    if len(list) < 2:
        return list
 
    middle = int(len(list)/2)
    left = mergesort(list[:middle])
    right = mergesort(list[middle:])
 
    return merge(left, right)
