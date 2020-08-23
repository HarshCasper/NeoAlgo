key=input("Enter the key : ")
key=key.replace(" ", "")
key=key.upper()
def matrix(x,y,initial):
    ''' generating key matrix '''
    return [[initial for i in range(x)] for j in range(y)]
    
result=list()
for element in key: 
    if element not in result:
        if element=='J':
            result.append('I')
        else:
            result.append(element)
flag=0
for i in range(65,91): 
    if chr(i) not in result:
        if i==73 and chr(74) not in result:
            result.append("I")
            flag=1
        elif flag==0 and i==73 or i==74:
            pass    
        else:
            result.append(chr(i))
k=0
my_matrix=matrix(5,5,0) 
for i in range(0,5): 
    for j in range(0,5):
        my_matrix[i][j]=result[k]
        k+=1

def locindex(element): 
    loc=list()
    if element=='J':
        element='I'
    for i ,j in enumerate(my_matrix):
        for k,l in enumerate(j):
            if element==l:
                loc.append(i)
                loc.append(k)
                return loc
                
            
  

def encrypt(): 
    ''' returns encrypted cipher text using the key matrix and the following rules-
    -If both the letters are in the same column: Take the letter below each one (going back to the top if at the bottom).
    -If both the letters are in the same row: Take the letter to the right of each one (going back to the leftmost if at the rightmost position).
    -If neither of the above rules is true: Form a rectangle with the two letters and take the letters on the horizontal opposite corner of the rectangle.
    
    '''
    msg=str(input("ENTER MSG : "))
    msg=msg.upper()
    msg=msg.replace(" ", "")             
    i=0
    for s in range(0,len(msg)+1,2):
        if s<len(msg)-1:
            if msg[s]==msg[s+1]:
                msg=msg[:s+1]+'X'+msg[s+1:]
    if len(msg)%2!=0:
        msg=msg[:]+'X'
    print("CIPHER TEXT:",end=' ')
    while i<len(msg):
        loc=list()
        loc=locindex(msg[i])
        loc1=list()
        loc1=locindex(msg[i+1])
        if loc[1]==loc1[1]:
            print("{}{}".format(my_matrix[(loc[0]+1)%5][loc[1]],my_matrix[(loc1[0]+1)%5][loc1[1]]),end=' ')
        elif loc[0]==loc1[0]:
            print("{}{}".format(my_matrix[loc[0]][(loc[1]+1)%5],my_matrix[loc1[0]][(loc1[1]+1)%5]),end=' ')  
        else:
            print("{}{}".format(my_matrix[loc[0]][loc1[1]],my_matrix[loc1[0]][loc[1]]),end=' ')    
        i=i+2  
        


def decrypt(): 
    ''' returns decrypted plain text using the key matrix and the following rules-
    -If both the letters are in the same column: Take the letter above each one (going back to the bottom if at the top).
    -If both the letters are in the same row: Take the letter to the left of each one (going back to the rightmost if at the leftmost position).
    -If neither of the above rules is true: Form a rectangle with the two letters and take the letters on the horizontal opposite corner of the rectangle.
    '''
    msg=str(input("ENTER CIPHER TEXT:"))
    msg=msg.upper()
    msg=msg.replace(" ", "")
    print("PLAIN TEXT:",end=' ')
    i=0
    while i<len(msg):
        loc=list()
        loc=locindex(msg[i])
        loc1=list()
        loc1=locindex(msg[i+1])
        if loc[1]==loc1[1]:
            print("{}{}".format(my_matrix[(loc[0]-1)%5][loc[1]],my_matrix[(loc1[0]-1)%5][loc1[1]]),end=' ')
        elif loc[0]==loc1[0]:
            print("{}{}".format(my_matrix[loc[0]][(loc[1]-1)%5],my_matrix[loc1[0]][(loc1[1]-1)%5]),end=' ')  
        else:
            print("{}{}".format(my_matrix[loc[0]][loc1[1]],my_matrix[loc1[0]][loc[1]]),end=' ')    
        i=i+2        

while(1):
    ch=int(input("\n 1.Encryption \n 2.Decryption: \n 3.Exit \n Enter Your Choice: "))
    
    if ch==1:
        encrypt()
    elif ch==2:
        decrypt()
    elif ch==3:
        break;
    else:
        print("Choose correct choice")
