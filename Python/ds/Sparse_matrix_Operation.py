#here we are going to take or read the matrix and convert matrix into thte sparse matrix
"""
input:


enter value of row: 3
0 1 2
0 0 5
1 0 0

"""
from operator import itemgetter , attrgetter

"""
this read_mat function will read input from user 
and return matrix as list of inputs
 
"""
def read_mat():
     matrix=[]
     for i in range(int(input("enter value of row : "))):
         l=list(map(int,input().split()))
         matrix.append(l)
     return matrix

"""
make_sparse will create sparse matrix 
from given list input
"""
def make_sparse(matrix):

    sm=[] # any nonzero elements will be stored in the sparse matrix
    for i in range(len(matrix)):
        for j in range(len(matrix[i])): #considering the any seach row
            if matrix[i][j]!=0:
                sm.append([i,j,matrix[i][j]])
    sm.insert(0,[len(matrix),len(matrix[0]),len(sm)])
    return sm

"""
this function is for display sparse matrix
 
"""
def display_matrix(k):
    print("The Output matrix : ")
    for i in range(len(k)):
        for j in range(len(k[0])):
            print(k[i][j],end=" ")
        print()

"""
core addition function to perform addition of two sparse matrix
"""
def addspm(sp1,sp2):
    print("performing addition on given sparse matrices......... ")
    count=1
    sp3=[]
    i,j=1,1
    if sp1[0][0]==sp2[0][0] and sp1[0][1]==sp2[0][1]:
        while i<len(sp1) and j<len(sp2) :
            if sp1[i][0] > sp2[j][0] or (sp1[i][0]==sp2[j][0] and sp1[i][1]>sp2[j][1]):
                sp3.append([sp2[j][0],sp2[j][1],sp2[j][2]])
                j+=1

            elif sp1[i][0] < sp2[j][0] or (sp1[i][0] == sp2[j][0] and sp1[i][1] < sp2[j][1]):
                sp3.append([sp1[i][0],sp1[i][1],sp1[i][2]])
                i+=1

            else:
                if (sp1[i][2]+sp2[j][2]):
                    sp3.append([sp1[i][0],sp1[i][1],sp1[i][2]+sp2[j][2]])
                    count+=1
                    i+=1
                    j+=1
        while i<len(sp1):
            sp3.append([sp1[i][0],sp1[i][1],sp1[i][2]])
            count+=1
            i+=1
        while j<len(sp2):
            sp3.append([sp2[j][0],sp2[j][1],sp2[j][2]])
            count+=1
            j+=1
        sp3.insert(0,[sp1[0][0],len(sp3[1]),len(sp3)])
        display_matrix(sp3)
    else:
        return "addition operation is not possible."

"""
this is second addition program 
I was trying to enhance my aproach from 
above code
"""
def addspm2(k1,k2):
    i,j=1,1
    sp3=[]
    if k1[0][0]==k2[0][0] and k1[0][1]==k2[0][1]:
        while i<len(k1) and j<len(k2):
            if k1[i][0]==k2[j][0] and k1[i][1]==k2[j][1]:
                sp3.append([k1[i][0],k2[j][1],k1[i][2]+k2[j][2]])
                i+=1
                j+=1
            else:
                if k1[i][0]<k2[j][0]:
                    sp3.append([k1[i][0],k1[i][1],k1[i][2]])
                    i+=1
                else:
                    sp3.append([k2[j][0],k2[j][1],k2[j][2]])
                    j+=1
        print(sp3)
    else:
        print("not possible")


"""
supstraction of sparse matrix
program

"""
def substractspm(sp1,sp2):
    print("performing substraction on given sparse matrices : ")
    count = 1
    sp3 = []
    i, j = 1, 1
    if sp1[0][0] == sp2[0][0] and sp1[0][1] == sp2[0][1]:
        while i < len(sp1) and j < len(sp2):
            if sp1[i][0] > sp2[j][0] or (sp1[i][0] == sp2[j][0] and sp1[i][1] > sp2[j][1]):
                sp3.append([sp2[j][0], sp2[j][1], - sp2[j][2]])
                j += 1

            elif sp1[i][0] < sp2[j][0] or (sp1[i][0] == sp2[j][0] and sp1[i][1] < sp2[j][1]):
                sp3.append([sp1[i][0], sp1[i][1], sp1[i][2]])
                i += 1

            else:
                if (sp1[i][2] + sp2[j][2]):
                    sp3.append([sp1[i][0], sp1[i][1], sp1[i][2] - sp2[j][2]])
                    count += 1
                    i += 1
                    j += 1
        while i < len(sp1):
            sp3.append([sp1[i][0], sp1[i][1], sp1[i][2]])
            count += 1
            i += 1
        while j < len(sp2):
            sp3.append([sp2[j][0], sp2[j][1], - sp2[j][2]])
            count += 1
            j += 1
        sp3.insert(0, [sp1[0][0], len(sp3[1]), len(sp3)])
        display_matrix(sp3)
    else:
        return "substraction operation is not possible."




def main():
    k1=make_sparse(read_mat())
    k2=make_sparse(read_mat())
    
    addspm(k1,k2)

if __name__ == '__main__':
    main()
