"""
 Function to print first n Fibonacci Numbers 
 n takes the input of first n numbers to be printed
"""
def fibonaccinumber(n):
	"""
    >>fibonaccinumber(6)
    1 1 2 3 5 8 

    >>fibonaccinumber(10)
    1 1 2 3 5 8 13 21 34 55

	"""
	a,b=0,1
    if n<1:
        return
    for x in range(0,n):
        print (b,end=' ')
        a,b=b,a+b
n=int(input())
(fibonaccinumber(n))