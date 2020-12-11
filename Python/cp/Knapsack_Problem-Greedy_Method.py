def Knapsack(p, w, TW):
    l = []
    pr = []
    wt = []
    #Finding p/w ratio of each item
    for i in range(len(p)):
        l.append(p[i]/w[i])
    #Ading items to the Knapsack according to p/w ratio
    while TW!=0:
        x = max(l)
        i = l.index(max(l))
        if(w[i]<=TW):
            TW-=w[i]
            pr.append(l[i])
            wt.append(w[i])
        else:
            wt.append(TW)
            TW=0
            pr.append(l[i])
        l[i] = -1
    total_prof = 0
    #Calculating total profit
    for i in range(len(pr)):
        total_prof+=pr[i]*wt[i]
    return total_prof

#Profits
p = [10, 5, 15, 7, 6, 18, 3]
#Weights
w = [2, 3, 5, 7, 1, 4, 1]
#Total Weight the Knapsack can handle
TW = 15
x = Knapsack(p, w, TW)
print(x)
