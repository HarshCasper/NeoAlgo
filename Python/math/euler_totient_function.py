''' python program for Euler's Totient Function '''
def euler_totient(num):
    ''' Takes in a variable num and return the number of coprimes of n '''
    arr=[]
    for count in range(num + 1):
        arr.append(count)
        
    for count in range(2, num + 1):
      '''if this condition is satisfied then we are removing the coprimes of j '''
      if arr[count] == count:                    
            for j in range( count ,num + 1 ,count):
                arr[j] -= (arr[j] / count)  
                    
    return int(arr[num])  
    
    
print("Enter a number : ")
''' taking input from the user '''
num = int(input())                       
if(num < 0):                   
    print("inavlid input")
else:
    print(euler_totient(num))
    
'''sample input
euler_totient(4) will be 2 as coprime will be (1,4),(3,4)
euler_totient(6) will be 2 as coprime will be (1,6),(5,6)
euler_totient(9) will be 6 as coprime will be (1,9),(2,9),(4,9),(5,9),(7,9),(8,9)
here we are considering (2,3) and (3,2) as same pair
 '''
