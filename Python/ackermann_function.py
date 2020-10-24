def Ackermann_func(m, n): 

	history = [[0 for i in range(n + 1)] for j in range(m + 1)] 

	for i in range(m + 1): 
		for j in range(n + 1): 

			if i == 0:	 
				history[i][j] = j + 1

			elif j == 0: 
				history[i][j] = history[i-1][1] 

			else: 
				a = i - 1
				b = history[i][j-1] 

				if a == 0:	 
					result = b + 1
				elif b <= n: 
					result = history[i-1][history[i][j-1]] 
				else: 
					result = (b-n)*(a) + history[a][n] 

				history[i][j] = result 

	return history[m][n] 

m, n = input("Enter non-negative values of m and n: ").split()
m, n = int(m), int(n)

print("A(%u,%u) = %u" % (m,n,Ackermann_func(m, n)))


#Time complexity: O( M * N )
#Space complexity: O( M * N )