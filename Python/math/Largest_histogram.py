def Largest_Rectangle(histogram):
    a=[]
    area=0
    i=0
    histogram.append(0)
    
    while i<len(histogram):
        #if stack is empty or rectangle with greater height is found then push the index into stack
        if len(a) == 0 or histogram[a[-1]] < histogram[i]:
                          a.append(i)
                          i += 1
        #if rectnagle of smaller height is found pop the top element from the stack and calculate area              
        else:
            top = a.pop()
            area = max(area,histogram[top]*(i-a[-1] - 1 if a else i))
    return area

hist = [7,3,6,5,6,2]
print('Area of Largest Rectangle in Histogram is :',Largest_Rectangle(hist))

