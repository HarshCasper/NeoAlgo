"""
The program helps to count the number of 
vowels and consants in a word

"""



def Count(word):
    vc, cc = 0, 0 #vc-vowels cc-consonant

    for s in word:
        if (s.isalpha()):
            if (s=='a' or s=='e' or s=='i' or s=='o' or s=='u'):
                vc = vc + 1
            else:
                cc = cc + 1
	
    return vc,cc;




TheWord= input("enter a string ").lower()

vc,cc=Count(TheWord)

print("vowel count = ", vc, " consonant count = ", cc) 


"""
Sample Input-Output:

VowelsConsants.py
enter a string Hello World
vowel count =  3  consonant count =  7


"""