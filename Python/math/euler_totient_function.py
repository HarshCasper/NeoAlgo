''' python program for Euler's Totient Function '''
def euler_totient(q):
    ''' Takes in a variable q and return the number of coprimes of q '''
    arr=[]
    for i in range(n + 1):
        arr.append(i)
        
    for i in range(2, n + 1):
      '''if this condition is satisfied then we are removing the coprimes of j '''
      if arr[i] == i:                    
            for j in range( i ,n + 1 ,i):
                arr[j] -= (arr[j] / i)  
                    
    return int(arr[n])  
    
    
print("Enter a number : ")
''' taking input from the user '''
n = int(input())                       
if(n < 0):                   
    print("inavlid input")
else:
    print(euler_totient(n))
    
'''sample input
euler_totient(4) will be 2 as coprime will be (1,4),(3,4)
euler_totient(6) will be 2 as coprime will be (1,6),(5,6)
euler_totient(9) will be 6 as coprime will be (1,9),(2,9),(4,9),(5,9),(7,9),(8,9)
here we are considering (2,3) and (3,2) as same pair
 '''
