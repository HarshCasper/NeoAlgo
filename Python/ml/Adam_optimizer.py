'''
Description : 
       Adam is an adaptive learning rate optimization 
       algorithm that's been designed specifically for training deep neural networks.
'''


#importing the library
import numpy as np

class Adam:
    def __init__(self,alpha, b1, b2):
        self.m = 0
        self.v = 0
        self.t = 0
        self.itr = 0
        self.alpha = alpha
        self.b1 = b1
        self.b2 = b2
        self.eps = 10 ** -8
        self.converged = False

    def function(self,x):
        return x**2

    def gradient(self,x):
        return 2*x

    def run(self,x):

        while (not self.converged):
            self.itr += 1

            self.t = self.t + 1
            self.g = self.gradient(x)
            
            self.m = self.b1 * self.m + ((1 - self.b1 )*self.g)
            self.v = self.b2 * self.v + ((1 - self.b2 )*(self.g**2))
            
            m_hat = self.m/(1 - self.b1 **self.t)
            v_hat = self.v/(1 - self.b2 **self.t)

            theta = x - (self.alpha * m_hat / ((v_hat**(1/2)) + self.eps))
            
            if np.linalg.norm(theta - x) <= 0.001:
                self.converged = True
            x = theta

            print("Iteration:", self.itr ,self.converged, x)


if __name__ == "__main__":
    alpha = 0.1
    beta1 = 0.9
    beta2 = 0.999
    X = np.array([100,76,130])
    opt = Adam(alpha, beta1, beta2)
    opt.run(X)