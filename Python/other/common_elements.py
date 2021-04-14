def common_elements(arr1,arr2,arr3):
        
        if len(arr1) < 0 and len(arr2) < 0 and len(arr3) < 0:
            print("Common element is none because list is empty")

            
        setofarr1 = set(arr1)
        setofarr2 = set(arr2)
        setofarr3 = set(arr3)
        t = setofarr1.intersection(setofarr2)
        Total = list(t.intersection(setofarr3))
        Total.sort()
        return Total

if __name__ == "__main__":
    arr1 = list(map(int,input("Enter the list 1: ").split()))
    arr2 = list(map(int,input("Enter the list 2: ").split()))
    arr3 = list(map(int,input("Enter the list 3: ").split()))
    print(common_elements(arr1, arr2, arr3))
    
    