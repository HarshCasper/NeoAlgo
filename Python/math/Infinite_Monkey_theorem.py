import random 
   
  
def generateOne(strlen):  
    alphabet = "abcdefghijklmnopqrstuvwxyz " 
    res ="" 
      
    for i in range(strlen): 
        res+= alphabet[random.randrange(27)] 
          
    return res 
  

def score(goal, testString):  
    numSame = 0
      
    for i in range(len(goal)): 
        if goal[i] == testString[i]: 
            numSame+= 1
              
    return numSame / len(goal) 
  

def main():  
    goalString = "a computer science portal for geeks"
    newString = generateOne(35) 
    best = 0
    newScore = score(goalString, newString) 
      
    while newScore<1: 
        if newScore>best: 
            print(newString) 
            best = newScore 
        newString = generateOne(35) 
        newScore = score(goalString, newString) 
  

main() 