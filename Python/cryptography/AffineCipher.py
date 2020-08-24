
def encryption():

  plain_text=input("Enter the plain text : ")

  global key1  # key 1
  global key2  # key 2
  global cipher_text # to store to the cipher text or the encrypted plain_text
  cipher_text=''
  
  


  key1 ,key2=input("Enter the keys : ").split()

  li=[] # a list for storing the encrypted characters which we later merged to a string i.e cipher_text



  def gcd(a, b): # for checking coprime
      while b != 0:
          a, b = b, a % b
      return a


  if gcd(int(key1),26)==1 and 0<int(key1)<26 and int(key2) <26  :  # checks whether key1 and 26 are coprime , key1 and key2 < 26
    
    for i in plain_text:
      if i.isalpha()==False: # if the character is not an alphabet then simply append for example if theres a white space or special characters like # , @ , ! etc.
        li.append(i)
    
      else:

        if i.isupper(): # if the alphabet is upper case

          p=ord(i)-65 # converts alphabets to numbers ranging from 0-26 for example A has a ascii value of 65 so 65-65 =0 therefore A is represented as 0 
          e_temp=(int(p)*int(key1)+int(key2))%26   # encryption formula : (p*k1 +k2)mod26
          li.append(chr(e_temp+65)) # storing the encrypted character in list

        else:  # if the alphabet is lower case

          p=ord(i)-97 # converts alphabets to numbers ranging from 0-26 for example c has a ascii value of 99 so 99-97 =2 therefore c is represented as 2
          e_temp=(int(p)*int(key1)+int(key2))%26  # encryption formula : (p*k1 +k2)mod26
          li.append(chr(e_temp+97)) # storing the encrypted character in list

    
    cipher_text=''.join(li)  
    print("The encrypted text is : ",cipher_text) 
  
  else:
    
    print("Please enter valid keys..try again")
    exit(0)

def decryption():

  if cipher_text=='':  # if the keys conditions were not satisfied and the encryption didnt took place then we exit the decryption function
    print('')
    exit(0)

  else:


    def inverse(x,y): # function calculating inverse
        for i in range(y):
            if (x*i)%y==1:
                return i

    key1_inv=inverse(int(key1),26) # calculating inverse of key1

    final=[] # a list that stores decrypted characters that later is merged to a string i.e decrypted

    for m in cipher_text:

      if m.isalpha()==False: # if the character is not an alphabet then simply append for example if theres a white space or special characters like # , @ , ! etc.
        final.append(m)

      else:

        if m.isupper():  # if the character is in upper case
          d=(((ord(m)-65)-int(key2))*key1_inv)%26   # decryption formula : ((p-k2)*k1_inverse)mod26
          final.append(chr(d+65)) #converting back to alphabets

        else:  # if the character is in lower case
          d=(((ord(m)-97)-int(key2))*key1_inv)%26  # decryption formula : ((p-k2)*k1_inverse)mod26
          final.append(chr(d+97)) #converting back to alphabets



    decrypted=''.join(final)
    print("The decrypted text is : ",decrypted) 
    
encryption()
decryption()

# sample I/O


#  Enter the plain text : Hello this is Affine substitution algorithm !
#  Enter the keys : 7 2
#  The encrypted text is :  Zebbw fzgy gy Cllgpe ymjyfgfmfgwp cbswrgfzi !
#  The decryted text is :  Hello this is Affine substitution algorithm !




#  Enter the plain text : I love python programming
#  Enter the keys : 15 10
#  The encrypted text is :  A tmns bgjlmx bfmwfkiiaxw
#  The decryted text is :  I love python programming




#  Enter the plain text : Hard work is the key to success 
#  Enter the keys : 20 8
#  Please enter valid keys..try again   # becuase the key1 i.e 20 does not forms a coprime whith 26 which is oneof the required conditions to be satisfied





#  Enter the plain text : Lets solve
#  Enter the keys : 3 27
#  Please enter valid keys..try again     # since the value of keys should be smaller than 26 but here the value of key2 is 27




