"""
Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, 
awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.

>>Input 1
  5 6 7
  3 6 10
>>Output 1
  1 1
>>Input 2
  17 28 30
  99 16 8
>>Output 2
  2 1
"""
alice=list(map(int,input().split()))
bob=list(map(int,input().split()))
ac=0
bc=0
i=len(alice)
for i in range(0,i):
    if alice[i]>bob[i]:
        ac+=1
    if alice[i]==bob[i]:
        ac,bc=ac,bc
    if alice[i]<bob[i]:
        bc+=1
print(ac,bc)