if __name__ == '__main__':
	arr=[]
	for i in range(3):
		arr.append(list(map(int,input().split())))
	sides=[[0,0],[1,0],[0,1],[-1,0],[0,-1]]    #  used for side-adjacent lights
	light=[[1 for i in range(3)] for j in range(3)]    # initially all lights are on
	for i in range(3):
		for j in range(3):
			sum=0
			for s in sides:
				if 0<=i+s[0]<3 and 0<=j+s[1]<3:
					sum+=arr[i+s[0]][j+s[1]]
			if sum%2!=0:
				light[i][j]=0
	for i in range(3):
		for j in range(3):
			print(light[i][j],end="")
		print()

'''
Example 1.
input
1 0 0
0 0 0
0 0 1
------
output
001
010
100
'''
