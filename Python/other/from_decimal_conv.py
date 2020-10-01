#pgm to convert decimal to binary,octal and hexadecimal

#CONVERTING TO BINARY
binary=[]
r=0
x=int(input("Enter number in decimal:"))
bin=x
while bin>=1:
    r=int(bin%2)
    binary.append(r)
    bin/=2
binary.reverse()
print('Number in binary:',''.join(map(str,binary)))   #map() it is converting the list into a string

#CONVERTING TO OCTAL
octal=[]
r=0
oct=x
while oct>=1:
    r=int(oct%8)
    octal.append(r)
    oct/=8
octal.reverse()
print('Number in octal:',''.join(map(str,octal)))

#CONVERTING TO HEXADECIMAL
hexa=[]
hex=x
if hex<10:
    print(hex)
elif hex>=10 and hex<16:
    if hex==10:
        print('A')
    elif hex==11:
        print('B')
    elif hex==12:
        print('C')
    elif hex==13:
        print('D')
    elif hex==14:
        print('E')
    elif hex==15:
        print('F')
else:
    while hex>=1:
        r=int(hex%16)
        if r>9:
            if r==10:
                r='A'
            elif r==11:
                r='B'
            elif r==12:
                r='C'
            elif r==13:
                r='D'
            elif r==14:
                r='E'
            elif r==15:
                r='F'
        hexa.append(r)
        hex/=16
    hexa.reverse()        
    print('Number in Hexadecimal:',''.join(map(str,hexa)))

    
