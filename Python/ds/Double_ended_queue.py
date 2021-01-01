'''
Flexible Dequeue:
we can use both the front and rear end for insertion and deletion operations
'''


class Deque:

    # constructor function called during object creation
    def __init__(self):
        self.ir = 0
        self.il = - 1
        self.dl = 0
        self.dr = 0
        self.list = []
        self.n = 0

    # resets the queue by values entered by user at the time of creation
    def reset(self):
        self.ir = self.n
        self.il = - 1
        self.dl = 0
        self.dr = self.n-1

    # takes the length of elements to be inserted
    def entry(self):
        self.list = []
        self.n = int(input('Enter no. of elements:'))
        self.reset()
        for i in range(self.n):
            self.list.append('-')

    # insertion from left or right
    def insert(self):
        sub = self.ir-self.il
        if sub == 1:
            print('-'*10)
            print('Queue is Full')
        elif sub == 2:
            self.il += 1
            self.list[self.il] = int(input('Enter your element: '))
        else:
            ch = input('Want to insert from left or right?(L/R): ')
            if ch == 'r' or ch == 'R':
                self.ir -= 1
                self.list[self.ir] = int(input('Enter your element:'))
            elif ch == 'l' or ch == 'L':
                self.il += 1
                self.list[self.il] = int(input('Enter your element:'))
            else:
                print('-' * 10)
                print('Invalid Choice !!!!!')

    # deletion from left or right
    def delete(self):
        if self.ir == self.n and self.il == -1:
            print('Queue is Empty')
        elif self.dr == self.dl:
            print('Deleted:', self.list[self.dr])
            self.reset()
        else:
            ch = input('Want to delete from left or right?(L/R):')
            if ch == 'l' or ch == 'L':
                print('Deleted:', self.list[self.dl])
                self.dl += 1
            elif ch == 'r' or ch == 'R':
                print('Deleted:', self.list[self.dr])
                self.dr -= 1
            else:
                print('-' * 10)
                print('Invalid Choice!!!!!!')

    # print all the elements from left or right
    def display(self):
        if self.ir == self.n and self.il == -1:
            print('Queue is Empty')
        elif self.dr == self.dl:
            print('Printing the Queue: ')
            print(self.list[self.dr])
        else:
            ch = input('Want to display from left or right?(R/L):')
            if ch == 'l' or ch == 'L':
                print ('Displaying the Queue from left: ')
                for i in range(self.dl, self.dr+1, +1):
                    print(self.list[i], end='')
            elif ch == 'r' or ch == 'R':
                print('Displaying the Queue from right: ')
                for i in range(self.dr, self.dl-1, -1):
                    print(self.list[i], end=' ')
            else:
                print('Invalid Choice!!!!!!')

    # creation of the deque
    def choose(self):
        while True:
            print('''
            PRESS  :  TO
            ----------------------
            1    :  Entry
            2    :  Insert
            3    :  Delete
            4    :  Display
            5    :  Exit
            ----------------------
            ''')

            ch = int(input('Enter your choice:'))
            if ch == 1:
                self.entry()
            elif ch == 2:
                self.insert()
            elif ch == 3:
                self.delete()
            elif ch == 4:
                self.display()
            else:
                break

ob = Deque()
ob.choose()

