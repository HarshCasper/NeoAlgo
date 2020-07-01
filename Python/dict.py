#DICTONARIES
my_dict = {} #empty dictionary
print(my_dict)
my_dict = {Sujal: 'Adobe', Mayank: 'Amazon'} #dictionary with elements
print(my_dict)



#CHANGING And ADDING KEY VALUE PAIRS
my_dict = {'First': 'Python', 'Second': 'Java'}
print(my_dict)
my_dict['Second'] = 'C++' #changing element
print(my_dict)
my_dict['Third'] = 'Ruby' #adding key-value pair
print(my_dict)


#DELETING KEY-VALUE PAIRS
my_dict = {'First': 'Sujal', 'Second': 'Virat', 'Third': 'Rohit'}
a = my_dict.pop('Third') #pop element
print('Value:', a)
print('Dictionary:', my_dict)
b = my_dict.popitem() #pop the key-value pair
print('Key, value pair:', b)
print('Dictionary', my_dict)
my_dict.clear() #empty dictionary
print('n', my_dict)