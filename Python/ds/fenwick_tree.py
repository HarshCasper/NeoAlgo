class FenwickTree:
    def __init__(self, SIZE):  # create fenwick tree with size SIZE
        self.Size = SIZE
        self.ft = [0 for i in range(0, SIZE)]

    def update(self, i, val):  # update data (adding) in index i in O(lg N)
        if i > n:
            print("enter valid index")
        else:
            while i < self.Size:
                self.ft[i] += val
                i += i & (-i)

    def query(self, i):  # query cumulative data from index 0 to i in O(lg N)
        if i > n:
            return "enter valid index"
        else:
            ret = 0
            while i > 0:
                ret += self.ft[i]
                i -= i & (-i)
            return ret


if __name__ == "__main__":
    n = int(input("size of fenwick tree    "))
    f = FenwickTree(n)
    for i in range(int(input("how many data you want to add   "))):
        index, value = map(int, input("enter index and value    ").split(","))
        f.update(index, value)
    print(f.query(int(input("enter index to get query cumulative data   "))))
    print(f.query(2))
    print(f.query(4))
    print(f.query(1))
    print(f.query(3))
    
    
    '''
    >>>
    size of fenwick tree    20
    how many data you want to add   2
    enter index and value    1,20
    enter index and value    3,5
    enter index to get query cumulative data   25
    enter valid index
    20
    25
    20
    25
    '''
