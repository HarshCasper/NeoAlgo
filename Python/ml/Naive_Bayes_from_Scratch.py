# Naive Bayes Algorithm 

import numpy as np 


class NaiveBayesClassifier:

    
    def __init__(self):
        pass


    # divides the dataset into a subset of data belonging to each class
    def divide_classes(self, X, Y):
        """
        X: list of features
        Y: list consisting of target
        The function returns: A dictionary with Y as keys and assigned X as values.
        """
        divided_classes = {}
        
        for i in range(len(X)):
            values = X[i]
            target_class_name = Y[i]
            if target_class_name not in divided_classes:
                divided_classes[target_class_name] = []
            divided_classes[target_class_name].append(values)
            
        return divided_classes


    # standard deviation and mean are required for the (Gaussian) distribution function
    def info(self, X):
        """
        X: list of features
        The function returns: A dictionary with standard deviation and mean as keys and assigned features as values.
        """
        for i in zip(*X):
            yield {
                'std' : np.std(i),
                'mean' : np.mean(i)
                  }
            
            
    # fitting data that would be required to train the model
    def fit_data (self, X, Y):
        """
        X: training features
        y: target variable
        The function returns: A dictionary with the probability, mean, and standard deviation of each class.
        """

        divided_classes = self.divide_classes(X, Y)
        self.summary = {}

        for target_class_name, values in divided_classes.items():
            self.summary[target_class_name] = {
                'given_prob': len(values)/len(X),
                'summary': [i for i in self.info(values)]
                            }
        return self.class_summary


    # Gaussian distribution function
    def Gaussian_distribution(self, X, mean, std):
        """
        X: value of feature
        mean: the average value of feature
        stdev: the standard deviation of feature
        The function returns: A value of normal probability.
        """

        exponent = np.exp(-((X-mean)**2 / (2*std**2)))
        
        return exponent / (np.sqrt(2*np.pi)*std)
    

    # finally predicting the class
    def predict(self, X):
        """
        X: test dataset
        The function returns: List of predicted class for each row of dataset.
        """

        # Maximum a posteriori (MAP): In Bayesian statistics, a maximum a posteriori 
        # probability (MAP) estimate is an estimate of an unknown quantity, that equals 
        # the mode of the posterior distribution.
        
        MAPs = []

        for i in X:
            joint_prob = {}
            
            for target_class_name, values in self.summary.items():
                total_values = len(values['summary'])
                likelihood = 1

                for idx in range(total_values):
                    value = i[idx]
                    mean = value['summary'][idx]['mean']
                    stdev = value['summary'][idx]['std']
                    normal_prob = self.Gaussian_distribution(value, mean, stdev)
                    likelihood *= normal_prob
                prior_prob = values['prior_proba']
                joint_prob[target_class_name] = prior_prob * likelihood

            MAP = max(joint_prob, key= joint_prob.get)
            MAPs.append(MAP)
            
        return MAPs
    
    
    # calculating accuracy
    def model_accuracy(self, y_test, y_pred):
        """
        y_test: actual values
        y_pred: predicted values
        The function returns: A number between 0-1, representing the percentage of correct predictions.
        """

        correct_true = 0

        for y_t, y_p in zip(y_test, y_pred):
            if y_t == y_p:
                correct_true += 1 
                
        return correct_true / len(y_test)
    