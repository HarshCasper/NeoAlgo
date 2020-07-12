import numpy as num
#Author @anushkrishnav
#Implementation of Strassen Matrix MUl algorithm.
class Strassen_Matrix(object):
    def __init__(self,a=[],b=[]):
        self.A=a
        self.B=b
        self.C=None
    def MatMul(self):
        self.StrassenMethod(self.A,self.B)
        return self.C
    def BruteForce(self):
        C=[]
        '''Brute Force T(n)=O(n^3)'''
        lent=len(self.A)
        for i in range(lent):
            C.append([0,0,0])
            for j in range(lent):
                for k in range(lent):
                    C[i][j]+=A[i][k]*B[k][j]
        self.C=C
        return self.C
    def StrassenMethod(self,x,v):
        '''T(N)=7T(N/2)+O(N^2)'''
        if len(x)==1:
            return x*v
        a,b,c,d=self.SplitMat(x)# Splitting matrix x and v into  quadrants
        e,f,g,h=self.SplitMat(v)#Splits Recursivly

        #Computing the  products Using Strassen's formula
        P1=self.StrassenMethod(a,f-h)
        P2=self.StrassenMethod(a+d,h)
        P3=self.StrassenMethod(c+d,e)
        P4=self.StrassenMethod(d,g-e)
        P5=self.StrassenMethod(a+d,e+h)
        P6=self.StrassenMethod(b-d,e+h)
        P7=self.StrassenMethod(a-c,e+f)
        ij11=P5+P4+P6-P2
        ij12=P1+P2
        ij21=P3+P4
        ij22=P1+P5-P3-P7
        self.C=num.vstack((num.hstack((ij11,ij12)),num.hstack((ij21,ij22))))
    @staticmethod
    def SplitMat(Matrix):
        ''' 
        Splits a given matrix''' 
        row_len,col_len=Matrix.shape
        row,col=row_len//2,col_len//2
        return Matrix[:row, :col], Matrix[:row, col:], Matrix[row:, :col], Matrix[row:, col:]
    


if __name__ == "__main__":
    A=num.matrix('1 2;3 4')
    B=num.matrix('1 1;1 1')
    rs=Strassen_Matrix(A,B)
    print(rs.MatMul())
