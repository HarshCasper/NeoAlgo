#for row and coloumn input
R = int(input("Enter the number of rows:")) 
C = int(input("Enter the number of columns:")) 
  
# Initialize matrix 
matrix = [] 
print("Enter the entries rowwise:") 
  
# For user input 
for i in range(R):          # A for loop for row entries 
    a =[] 
    for j in range(C):      # A for loop for column entries 
         a.append(int(input())) 
    matrix.append(a)        #taking input of arrays
  
count = 0;  #Initializing count =0 to count the number of zeroes.
   
#Calculates number of rows and columns present in given matrix  
rows = len(matrix);  
cols = len(matrix[0]);  
   
#Calculates the size of the array  
  
size = rows * cols;  
   
#Count all zero element present in matrix  
for i in range(0, rows):  
    for j in range(0, cols):  
        if(matrix[i][j] == 0):  
            count = count + 1;  
#checking whether the matrix has more number of zeroes or not   
if(count > (size/2)):  
	print("Given matrix is a sparse matrix");
	size = 0;
	for i in range(R): 
		for j in range(C): 
			if (matrix[i][j] != 0): 
				size += 1;

	rows, cols = (3, size) 
	PrintMatrix = [[0 for i in range(cols)] for j in range(rows)] 

	k = 0
	for i in range(R): 
		for j in range(C): 
			if (matrix[i][j] != 0): 
				PrintMatrix[0][k] = i 
				PrintMatrix[1][k] = j 
				PrintMatrix[2][k] = matrix[i][j] 
				k += 1

	for i in PrintMatrix: 
		print(i)   

else:  
    print("Given matrix is not a sparse matrix"); 

