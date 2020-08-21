def gradingStudents(grades):
    # Write your code here
    count=[]
    for i in grades:
        if i<38:
            count.append(i)
        else:
            if i%5==0:
                count.append(i)
            else:
                k=i
                while(k%5!=0):
                    k+=1
                if k-i<3:
                    count.append(k)
                else:
                    count.append(i)                
    return count