import requests

data = requests.get("https://raw.githubusercontent.com/coding-blocks-archives/ML-Noida-2019-June-Two/master/datasets/speeches/speech.txt")

data = data.text

data[0:500]

def generateTransition(data, k = 4):
  T = {}

  for i in range(len(data)- k):
    X = data[i : i+k]
    y = data[i+k]
  
    if T.get(X) is None: # If input state is not in the dictiory
      T[X] = {} # initialise empty dictionary for that corresponding input
      T[X][y] = 1 # freq => 1
    else:
      if T[X].get(y) is None:  # If you already have input in dictionary but the output is not in dictionary
        T[X][y] = 1
    
      else:
        T[X][y] += 1 # if you have both input and output in dic, just increment the frequency.

  return T

T = generateTransition(data.lower())

input = "country"

possible_chars = list(T[input[-4:]].keys())

possible_freq = list(T[input[-4:]].values())

# converting frequencies into probabilities...
probabs = []
for ele in possible_freq:
  x = ele/sum(possible_freq)
  probabs.append(x)

print(possible_chars)
print(probabs)

import numpy as np

pred = np.random.choice(possible_chars, p= probabs )

input = input+pred

input

for i in range(300):
  possible_chars = list(T[input[-4:]].keys())
  possible_freq = list(T[input[-4:]].values())
  probabs = [ele/sum(possible_freq) for ele in possible_freq] # list comprehension
  pred = np.random.choice(possible_chars, p= probabs )
  input = input+pred

print(input)
