''' Monoalphabetic substitution cipher basically replaces each letter of a plaintext by another
    letter or symbol, depending only on the letter. The same plaintext letter is always replaced
    by the same ciphertext letter and the same letter can be replaced by letter itself.
    Example if a is there we replace it with B to Z .....so on.'''

'''This is the encryption function which takes planetext
   as input and returns us the ciphertext list.''' 
def monoalphabeticcipher(plaintext,size):
   
   output = ['']*size
   #This is the cipher list we use to encrypt the message 
   cipherer = ['Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G',
   'F','E','D','C','B','A'];
   list = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o','p', 'q',
   'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
   
   space = ' '   
   
   '''We iterate through the plaintext given to us an find out
      what letter it is and then we use the list called cipherer
      to replace that letter. We keep the space as space in output'''              
   for i in range(size):   
      for j in range(26):
        if plaintext[i] == list[j] :
           output[i] = cipherer[j];
        elif plaintext[i] == space :
           output[i] = space;    
   
   #return the encrypted message
   return output
  
if __name__ == '__main__':
   
   #we take the plaintext input here
   plaintext = input("Enter the plaintext here :")
   size = len(plaintext)
  
   '''calling the monoalphabeticcipher function on the given plaintext
      to return the encrypted message'''
   encrypted_message = monoalphabeticcipher(plaintext,size)
   
   #printing the ciphertext we got using the monoalphabetic function
   print("Encripted plaintext is :","".join(encrypted_message))

'''
   Sample I/O :

   a)Case where plaintext has space :
    
   Enter the plaintext here :hello world
   Encripted plaintext is : SVOOL DLIOW 

   b)Case where plaintext dosen't have space :

   Enter the plaintext here :python
   Encripted plaintext is : KBGSLM    
'''

