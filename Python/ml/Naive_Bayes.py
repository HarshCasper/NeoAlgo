'''
Descritpion : Naïve Bayes is one of the fast and easy ML algorithms to predict a class of datasets.
             It can be used for Binary as well as Multi-class Classifications
'''

import numpy as np

class NaiveBayes:
    def __init__(self, X, y):
        self.num_examples, self.num_features = X.shape
        self.num_classes = len(np.unique(y))
        self.e = 1e-6
        self.mean = {}
        self.variance = {}
        self.prior_prob = {}
        

    def fit(self, X):

        for cls in range(self.num_classes):
            X_cls = X[y == cls]

            self.mean[str(cls)] = np.mean(X_cls, axis=0)
            self.variance[str(cls)] = np.var(X_cls, axis=0)
            self.prior_prob[str(cls)] = X_cls.shape[0] / X.shape[0]

    def predict(self, X):
        probs = np.zeros((self.num_examples, self.num_classes))

        for cls in range(self.num_classes):
            cls_prob = self.compute_probability( X, self.mean[str(cls)], self.variance[str(cls)])
            probs[:, cls] = cls_prob + np.log(self.prior_prob[str(cls)])

        return np.argmax(probs, 1)

    # Gaussian density function
    def compute_probability(self, x, mean, sigma):
        
        const = -self.num_features / 2 * np.log(2 * np.pi) - 0.5 * np.sum(np.log(sigma + self.e))
        probs = 0.5 * np.sum(np.power(x - mean, 2) / (sigma + self.e), 1)
        return const - probs


if __name__ == "__main__":
    X = np.loadtxt("input/data.txt", delimiter=",")
    y = np.loadtxt("input/targets.txt") - 1

    NB = NaiveBayes(X, y)
    NB.fit(X)
    y_pred = NB.predict(X)

    print(f"Accuracy: {sum(y_pred==y)/X.shape[0]}")