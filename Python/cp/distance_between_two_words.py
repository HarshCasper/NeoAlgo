# function to calculate the minimum distance between word1 and word2 in a list of words
  
def distance(s, w1, w2): 
    if w1 == w2 :
       return 0

    # individual words in a list
    words = s.split(" ")
 
    # assuming total length of the string as minimum distance
    min_distance = len(words)+1
 
    # traverse through the entire string
    for index in range(len(words)):
 
        if words[index] == w1:
            for search in range(len(words)):
 
                if words[search] == w2: 
 
                    # distance between words is the index of the first word - the index of current word
                    current = abs(index - search) - 1;
 
                    # compare current distance with the previously assumed distance
                    if current < min_distance:
                       min_distance = current
 
    # w1 and w2 are same and adjacent
    return min_distance
     
 
# Driver code
s = input()           
w1 = input()
w2 = input()
print(distance(s, w1, w2))
