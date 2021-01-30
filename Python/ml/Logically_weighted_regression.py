
'''
Locally weighted linear regression is a non-parametric algorithm, that is, 
the model does not learn a fixed set of parameters as is done in ordinary linear regression. 
Rather parameters 'theta' are computed individually for each query point x. 
While computing 'theta', a higher “preference” is given to the points in the 
training set lying in the vicinity of x than the points lying far away from x.

Get the dataset from 'https://www.kaggle.com/aswin1871/tips-csv'
'''

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def kernel(point,xmat,k):
    '''
        This function calculates the weights kernel which is used to find the local weights.
    '''
    m,n = np.shape(xmat)

    # Stores the weight matrix consisting of 1s along the diagonals and 0s elsewhere.
    weights = np.mat(np.eye(m))

    for j in range(m):
        # Calculates the distance between each point under consideration and all other points of the dataset
        diff = point-xmat[j]

        # Perfoms the kernel weight equation
        weights[j,j] = np.exp((diff*diff.T)/(-2.0*k**2))
    return weights


def local_weight(point,xmat,k,ymat):
    '''
        This function calculates the local weight of each point in the dataset with respect to the point under consideration.
    '''

    # Retrieves the weight kernel of each point wrt the given point.
    wei = kernel(point,xmat,k)

    # Calculates the weight matrix for the particular point
    w = (xmat.T*(wei*xmat)).I*(xmat.T*(wei*ymat.T))
    return w

def local_weight_regression(xmat,ymat,k):
    '''
        Performs Local Weight Regression on each point of the dataset.
    '''
    m,n = np.shape(xmat)

    #  Defines the matrix which returns the predricted point for each input feature.
    ypred = np.zeros(m)
    for i in range(m):

        # the given point multiplied by the weight matrix values gives the predicted value.
        ypred[i] = xmat[i]*local_weight(xmat[i],xmat,k,ymat)
        
    return ypred
if __name__ == '__main__':
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

