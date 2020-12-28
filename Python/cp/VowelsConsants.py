#to count the number of vowels and consants in a word in a word

s1 = input("enter a string ").lower() #taking string and converting it to lowercase
vc, cc = 0, 0      #vc-vowels cc-consonant

for s in s1:
	if (s.isalpha()):    #to check whether letter is alpshabet or not
		if (s=='a' or s=='e' or s=='i' or s=='o' or s=='u'):
			vc = vc + 1
#you could also type s in ['a','e','i','o','u']
		else:
			cc = cc + 1
print("vowel count = ", vc, " consonant count = ", cc)  #giving the final oup