
def encryption():

  plain_text=input("Enter the plain text : ")

  global key1  # key 1
  global key2  # key 2
  global cipher_text # to store to the cipher text or the encrypted plain_text
  cipher_text=''
  key1 ,key2=input("Enter the keys : ").split()

  list_encrypted_characters=[] # a list for storing the encrypted characters which we later merged to a string i.e cipher_text

  def gcd(number1, number2): # for checking whether two numbers are coprime or not
      while number2 != 0:
          number1, number2 = number2, number1 % number2
      return number1


  if gcd(int(key1),26)==1 and 0<int(key1)<26 and int(key2) <26  :  # checks whether key1 and 26 are coprime , key1 and key2 < 26
    
    for character in plain_text:
      if character.isalpha()==False: # if the character is not an alphabet then simply append for example if theres a white space or special characters like # , @ , ! etc.
        list_encrypted_characters.append(character)
    
      else:

        if character.isupper(): # if the alphabet is upper case

          p=ord(character)-65 # converts alphabets to numbers ranging from 0-26 for example A has a ascii value of 65 so 65-65 =0 therefore A is represented as 0 
          e_temp=(int(p)*int(key1)+int(key2))%26   # encryption formula : (p*k1 +k2)mod26
          list_encrypted_characters.append(chr(e_temp+65)) # storing the encrypted character in list

        else:  # if the alphabet is lower case

          p=ord(character)-97 # converts alphabets to numbers ranging from 0-26 for example c has a ascii value of 99 so 99-97 =2 therefore c is represented as 2
          e_temp=(int(p)*int(key1)+int(key2))%26  # encryption formula : (p*k1 +k2)mod26
          list_encrypted_characters.append(chr(e_temp+97)) # storing the encrypted character in list

    
    cipher_text=''.join(list_encrypted_characters)  
    print("The encrypted text is : ",cipher_text) 
  
  else:
    
    print("Please enter valid keys..try again")
    exit(0)

def decryption():

  if cipher_text=='':  
    print('')
    exit(0)

  else:


    def inverse(number1,number2): # function calculating inverse
        for character in range(number2):
            if (number1*character)%number2==1:
                return character

    key1_inv=inverse(int(key1),26) # calculating inverse of key1

    list_decrypted_characyers=[] # a list that stores decrypted characters that later is merged to a string i.e decrypted

    for cipher_character in cipher_text:

      if cipher_character.isalpha()==False: # if the character is not an alphabet then simply append for example if theres a white space or special characters like # , @ , ! etc.
        list_decrypted_characyers.append(cipher_character)

      else:

        if cipher_character.isupper():  # if the character is in upper case
          d=(((ord(cipher_character)-65)-int(key2))*key1_inv)%26   # decryption formula : ((p-k2)*k1_inverse)mod26
          list_decrypted_characyers.append(chr(d+65)) #converting back to alphabets

        else:  # if the character is in lower case
          d=(((ord(cipher_character)-97)-int(key2))*key1_inv)%26  # decryption formula : ((p-k2)*k1_inverse)mod26
          list_decrypted_characyers.append(chr(d+97)) #converting back to alphabets



    decrypted=''.join(list_decrypted_characyers)
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


