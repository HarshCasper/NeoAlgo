"""
Crossword Puzzle Problem
Steps:
1. Check the cell to be '-' of first character of the word
2. Check if that particular word can be filled in That place horizontally or vertically
3. If the word can be filled , fill it!
4. If the word cannot be filled, Backtrack and remove the previous word filled and fill it in some other position
5. Repeat the process until and unless all the words are filled that is index == words.length.
"""
def solveCrossword(crossword, words, index, wordfill):
    if(index==len(words)):
        printCrossword(crossword)
        return

    for i in range(10):
        for j in range(10):
            if(crossword[i][j]=='-' or crossword[i][j]==words[index][0]):
                #try to insert it vertically
                inserted=insertVerticalIfPossible(i,j,crossword,words,index,wordfill)
                if(inserted):
                    solveCrossword(crossword, words, index+1, wordfill)
                if(inserted):
                    removeVertically(i,j,crossword,words,index,wordfill)

                # try to insert it horizontally
                inserted = insertHorizontalIfPossible(i, j, crossword, words, index, wordfill)
                if (inserted):
                    solveCrossword(crossword, words, index + 1, wordfill)
                if (inserted):
                    removeHorizontally(i, j, crossword, words, index, wordfill)

def removeHorizontally(i, j, crossword, words, index, wordfill):
    for x in range(len(words[index])):
        if(wordfill[index][x]):
            crossword[i][j]='-'
        wordfill[index][x]=False
        j+=1

def insertHorizontalIfPossible(i, j, crossword, words, index, wordfill):
    word=words[index]

    wordIndex=0
    initial_j=j
    while(j<10):
        if(crossword[i][j]=='+'):
            return False
        elif(crossword[i][j]=='-'):
            wordIndex+=1
        elif(crossword[i][j]==word[wordIndex]):
            wordIndex+=1
        else:
            return False


        if(wordIndex==len(word)):
            for x in range(len(word)):
                if(crossword[i][initial_j]==word[x]):
                    wordIndex+=1
                else:
                    crossword[i][initial_j]=word[x]
                    wordfill[index][x]=True
                initial_j+=1
            return True
        j+=1
    return False



def insertVerticalIfPossible(i, j, crossword, words, index, wordfill):
    word=words[index]

    wordIndex=0
    initial_i=i
    while(i<10):
        if(crossword[i][j]=='+'):
            return False
        elif(crossword[i][j]=='-'):
            wordIndex+=1
        elif(crossword[i][j]==word[wordIndex]):
            wordIndex+=1
        else:
            return False


        if(wordIndex==len(word)):
            for x in range(len(word)):
                if(crossword[initial_i][j]==word[x]):
                    wordIndex+=1
                else:
                    crossword[initial_i][j]=word[x]
                    wordfill[index][x]=True
                initial_i+=1
            return True
        i+=1
    return False

def removeVertically(i, j, crossword, words, index, wordfill):
    for x in range(len(words[index])):
        if(wordfill[index][x]):
            crossword[i][j]='-'
        wordfill[index][x]=False
        i+=1


def printCrossword(crossword):
    for i in range(10):
        for j in range(10):
            print(crossword[i][j],end='')
        print()


crossword_temp=[]
for i in range(10):
    #Inputting the 10 lines of crossword
    crossword_temp.append(input())

#converting strings to character Array beacuse strings in python are immutable
crossword=[[0 for i in range(10)] for j in range(10)]
for i in range(10):
    for j in range(10):
        crossword[i][j]=crossword_temp[i][j]
#Take input words separated by ';'
words=list(map(str,input().split(';')))

wordfill=[False for i in range(len(words))]
for i in range(len(words)):
    wordfill[i]=[False]*len(words[i])

solveCrossword(crossword, words, 0, wordfill)

"""
Testcase:-
Input:
+-++++++++
+-++++++++
+-++++++++
+-----++++
+-+++-++++
+-+++-++++
+++++-++++
++------++
+++++-++++
+++++-++++
LONDON;DELHI;ICELAND;ANKARA
Output:
+L++++++++
+O++++++++
+N++++++++
+DELHI++++
+O+++C++++
+N+++E++++
+++++L++++
++ANKARA++
+++++N++++
+++++D++++
"""