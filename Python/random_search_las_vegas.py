
'''
Random search (RS) is a family of numerical optimization methods that do not require the gradient 
of the problem to be optimized, and RS can hence be used on functions that are not continuous or 
differentiable. Such optimization methods are also known as direct-search, derivative-free, or 
black-box methods.

The name "random search" is attributed to Rastrigin[1] who made an early presentation of RS 
along with basic mathematical analysis. RS works by iteratively moving to better positions in
the search-space, which are sampled from a hypersphere surrounding the current position.

The algorithm described herein is a type of local random search, where every iteration is
dependent on the prior iteration's candidate solution. There are alternative random search 
methods which sample from the entirety of the search space (for example pure random search or 
uniform global random search).

This is the Las vegas version of the random search. a Las Vegas algorithm is a randomized algorithm 
that always gives correct results; that is, it always produces the correct result or it informs about
the failure. However, the runtime of a Las Vegas algorithm differs depending on the input. 

It take a element from the list randomly and compare it with element give input by user untill correct one found.

Improvement:
*The stopping condition if not found element in search space.

'''


import random

# manual input function from user


def get_list(size):
    l = []
    for i in range(size):
        l.append(int(input()))
    return l

# random algorithm to search the algorithm.


def random_search(ele, _list):
    collector = random.choice(_list)

    while True:
        prev = collector
        if collector == ele:
            print('element found')
            break

        collector = random.choice(new_list)


if __name__ == "__main__":
    new_list = get_list(int(input("enter the size of the list:")))
    ele = int(input("enter the element to search:"))

    random_search(ele, new_list)
