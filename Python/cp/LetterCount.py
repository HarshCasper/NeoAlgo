word=input("enter a word ").lower()


dict={}

for c in word:
	co = dict.get(c,0)
	if co == 0:
		dict[c]=1
	else:
		dict[c]=co+1
print(dict)		