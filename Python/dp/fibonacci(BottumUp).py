F = [0]*50 #array to store fibonacci terms

#this is a function that generates fibonacci number of a number n that is passed as argument
def fibonacciBottomUp(n):
  F[n] = 0
  F[1] = 1

  for i in range(2, n+1):
    F[i] = F[i-1] + F[i-2]
  return F[n]

if __name__ == '__main__':
    print('Select one option.')
    print('1. Print series of fibonacci till n terms')
    print('2. Print the fibonacci value of nth term.')
    c=int(input('Enter your choice : '))
    if c==1:
        n=int(input('Enter How many terms you want to print : '))
        for i in range(n):
            print(fibonacciBottomUp(i),end=" -> ")
    elif c==2:
        n=int(input('Enter the term for which you want to get fibonacci value  : '))
        print(fibonacciBottomUp(n))
    else:
        print('Wrong choice')

   