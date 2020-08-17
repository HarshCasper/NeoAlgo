# python program for Euler's Totient Function 
def euler_totient(q):
    arr=[]
    for i in range(n+1):
        arr.append(i)
        
    for i in range(2,n+1):
      if arr[i]==i:                    #if this condition is satisfied then we are removing the coprimes of j
            for j in range(i,n+1,i):
                arr[j]-=(arr[j]//i)  
                
    for i in range(2,n+1):
        arr[i]+=arr[i-1]               #for calculating no of coprime between (1,n) we are using the concept of dyanmic programming 
        
    return arr[n]  
    
    
print("Enter number of elements : ")
n = int(input())                       # taking input from the user
if(n<0):                   
    print("inavlid input")
else:
    print(euler_totient(n))
#sample input
#euler_totient(4) will be 6 as no of coprime between 1 and 4 are (1,1),(1,2),(1,3),(1,4),(2,3),(3,4)
#euler_totient(5) will be 10 as no of coprime between 1 and 4 are (1,1),(1,2),(1,3),(1,4),(1,5),(2,3),(2,5),(3,4),(3,5),(4,5)
#here we are considering (2,3) and (3,2) as same pair
 
