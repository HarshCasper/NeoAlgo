def plusMinus(arr,n):
    a=b=c=0
    for i in arr:
        if i>0:
            a+=1
        if i<0:
            b+=1
        if i==0:
            c+=1
    print('%.6f'%(a/n))
    print('%.6f'%(b/n))
    print('%.6f'%(c/n))
