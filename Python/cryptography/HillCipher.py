'''This code is an implementation of Hill Cipher. It
   is a polygraphic substitution cipher. It forms a 
   nxn matrix of key and nx1 matrix(s) of the plaintext
   and then multiplies the two matrices to obtains the
   matrix of ciphertext.'''

import sys

#This function builds key-Martix given the key
def buildKeyMatrix(key):
   
   k = 0
   for i in range(n):
     for j in range(n):
       keyMatrix[i][j] = ord(key[k])%97
       k += 1

#This function builds Message-Matrix given planetext   
def buildMessageMatrix(plaintext):
   
   for i in range(n): 
     messageMatrix[i][0] = ord(plaintext[i])%97 

'''This is the encryption function which takes planetext
   and key as input and returns us the ciphertext list.'''   
def encription(plaintext,key):
   
   buildKeyMatrix(key)
   buildMessageMatrix(plaintext)    
   
   #matrix multiplication of key and message matrices
   for i in range(n):
     for j in range(n):
       cipherMatrix[i][0] += ( keyMatrix[i][j]*messageMatrix[j][0] )
     cipherMatrix[i][0]    = cipherMatrix[i][0] %26
   
   #storing all the result as a list
   cipherText = []
   for i in range(n):
     cipherText.append( chr(cipherMatrix[i][0]+97) )

   return cipherText 
     

if __name__=='__main__':
   
   #Taking plaintext and key as input from user
   plaintext = input("Enter the plaintext here :")
   key       = input("Enter the key here :")
   
   n = len(plaintext)
   
   if len(key) != n*n :
      print("Invalid Key")
      sys.exit(0)
   
   #creating the matrices required
   keyMatrix     = [ [0]*n for i in range(n) ]
   messageMatrix = [ [0]   for i in range(n) ]
   cipherMatrix  = [ [0]   for i in range(n) ]
   
   for i in range(n):
      cipherMatrix[i][0] = 0
  
   '''calling the encryption function on the given plaintext
      and key''' 
   encrypted_message = encription(plaintext,key)
   
   #printing the ciphertext we got using the encryption method
   print("Encripted plaintext is :","".join(encrypted_message) )

'''
Sample I/O:

   Enter the plaintext here :ask 
   Enter the key here :thisiskey
   Encripted plaintext is : yma     
'''
 
