F = [-1]*50 #array to store fibonacci terms

def dynamicFibonacci(n):
  if (F[n] < 0):
    if (n==0):
      F[n] = 0
    elif (n == 1):
      F[n] = 1
    else:
      F[n] = dynamicFibonacci(n-1) + dynamicFibonacci(n-2)
  return F[n]

if __name__ == '__main__':
    print('Select one option.')
    print('1. Print series of fibonacci till n terms')
    print('2. Print the fibonacci value of nth term.')
    c=int(input('Enter your choice : '))
    if c==1:
        n=int(input('Enter How many terms you want to print : '))
        for i in range(n):
            print(dynamicFibonacci(i),end=" -> ")
    elif c==2:
        n=int(input('Enter the term for which you want to get fibonacci value  : '))
        print(dynamicFibonacci(n))
    else:
        print('Wrong choice')