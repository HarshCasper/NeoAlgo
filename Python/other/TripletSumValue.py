'''
Given an array arr and an integer k.Find if there's a triplet in the array which sums up to the given integer k

'''

def TripletSumValue(ary,k):
    #take a final list 
    fnl_lst=[]
    #take a dictionary
    dict={}
    #check whether the numbers is present to producestatus 
    #given sum  
    for i in range(0,len(ary)):
        for j in range(i+1,len(ary)):

            sum=ary[i]+ary[j]
            diff=k-sum
            
            if diff in dict.keys():
                tup=tuple(sorted((diff,ary[i],ary[j])))
                if tup not in fnl_lst:
                    fnl_lst.append(tup)
            else:
                dict[ary[j]]=1
    #result 
    return fnl_lst

def main():
   #taking the input 
   arr = list(map(int,input("Enter the list: ").split()))
   k = int(input("Enter K: "))
   print("Array which sum ",k," is ",TripletSumValue(arr,k))
   

if __name__=='__main__':
    main()

'''
Time Complexity: O(N^2)
Space Complexity: O(1)

INPUT:

Enter the elements: 1 4 45 6 10 8 
Enter K: 13

OUTPUT:
Array which sum 13  is  [(1, 4, 8)]

'''
