''' Bilinear search is searching algorithm where it is search for a element from the both end.
It is a improved version of linear search.
'''
def bilinear(x,arr):
    siz = len(arr)
    p = 0
    i = 0
    j = siz-1

    while i<j:
        if arr[i] != x and arr[j] != x:
           i+=1
           j-=1
        else:
            p = 1
            break
    if p == 1:
       return True
    else:
        return False

if __name__ == "__main__":
    print('enter the list:')
    l = list(map(int,input().split(' ')))

    ele = int(input("enter the element to check:"))

    if bilinear(ele,l):
       print('element found')
    elif bilinear(ele,l)==False:
        print("element not found")
           