'''
Polygonal numbers are non-negative integers constructed and represented by geometrical
arrangements of equally spaced points that form regular polygons.
It is given by: P(s,n)=(s-2)n(n-1)/2 +n
                where s is no of sides in a polygon
                      P(s,n) is nth s-gonal number
    
This program will print the polygonal numbers upto nth term. '''

#Function to generate nth s-gonal number

def nth_sgonal(s,n):
    return((s-2)*n*(n-1)/2+n)

if __name__ == '__main__':

    s=int(input("Enter the number of sides in polygon:"))
    n=int(input("Enter number of terms to generate:"))

    #Printing polygonal numbers upto n terms
    print(str(n)+" Polygonal numbers with "+str(s) +" sides are:")
    for i in range(1,n+1):
        print(nth_sgonal(s,i),end=" ")
        
'''
Sample Input/Output:

Input:
Enter the number of sides in polygon:5
Enter number of terms to generate:7

Output:
7 Polygonal numbers with 5 sides are:
1.0 5.0 12.0 22.0 35.0 51.0 70.0

Time Complexity:O(n)  where n is total numbers in range
Time Complexity of is_pronic()=O(1) 
Space Complexity:O(1)

'''
