
def encryption():

  plain_text=input("Enter the plain text : ")

  global k1
  global k2
  global encrypted
  encrypted=''
  
  


  k1 ,k2=input("Enter the keys : ").split()

  li=[]



  def gcd(a, b): # for checking coprime
      while b != 0:
          a, b = b, a % b
      return a


  if gcd(int(k1),26)==1 and 0<int(k1)<26 and int(k2) <26  :
    
    for i in plain_text:
      if i.isalpha()==False:
        li.append(i)
    
      else:

        if i.isupper():

          p=ord(i)-65 
          e_temp=(int(p)*int(k1)+int(k2))%26
          li.append(chr(e_temp+65))

        else:

          p=ord(i)-97 
          e_temp=(int(p)*int(k1)+int(k2))%26
          li.append(chr(e_temp+97))

    
    encrypted=''.join(li)
    print("The encrypted text is : ",encrypted) 
  
  else:
    
    print("Please enter valid keys..try again")
    print(encrypted)
    exit(0)

def decryption():

  if encrypted=='':
    print('')
    exit(0)

  else:


    def inverse(x,y):
        for i in range(y):
            if (x*i)%y==1:
                return i

    k1_inv=inverse(int(k1),26)

    final=[]

    for m in encrypted:

      if m.isalpha()==False:
        final.append(m)

      else:

        if m.isupper():
          d=(((ord(m)-65)-int(k2))*k1_inv)%26
          final.append(chr(d+65))

        else:
          d=(((ord(m)-97)-int(k2))*k1_inv)%26
          final.append(chr(d+97))


    decrypted=''.join(final)
    print("The decryted text is : ",decrypted) 
    
encryption()
decryption()
