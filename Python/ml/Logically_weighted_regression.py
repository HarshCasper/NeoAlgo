import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def kernel(point,xmat,k):
    m,n = np.shape(xmat)
    weights = np.mat(np.eye(m))
    for j in range(m):
        diff = point-xmat[j]
        weights[j,j] = np.exp((diff*diff.T)/(-2.0*k**2))
    return weights


def local_weight(point,xmat,k,ymat):
    wei = kernel(point,xmat,k)
    w = (xmat.T*(wei*xmat)).I*(xmat.T*(wei*ymat.T))
    return w

def local_weight_regression(xmat,ymat,k):
    m,n = np.shape(xmat)
    ypred = np.zeros(m)
    for i in range(m):
        ypred[i] = xmat[i]*local_weight(xmat[i],xmat,k,ymat)
        
    return ypred

data = pd.read_csv('tips.csv')
bill = data.total_bill
tip = data.tip

mbill = np.mat(bill)
mtip = np.mat(tip)

m = np.shape(mbill)[1]

one = np.mat(np.ones(m))

x = np.hstack((one.T,mbill.T))
ypred = local_weight_regression(x,mtip,10)

sortIndex = x[:,1].argsort(0)
xsort = x[sortIndex][:,0]

plt.scatter(bill,tip,color='green')
plt.plot(xsort[:,1],ypred[sortIndex],color='red',linewidth=5)
plt.show()

