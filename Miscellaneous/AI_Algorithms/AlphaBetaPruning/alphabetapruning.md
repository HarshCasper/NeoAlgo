- An optimization technique for minimax algorithm.
- In Minimax Algorithm, we had to explore all the nodes and on the basis of it decide the best move for us(Max Player) due to which the search time increased.
- Here we cut off the search by exploring less number of nodes.
- It is called Alpha-Beta pruning because it passes 2 extra parameters in the minimax function, namely alpha and beta.
  * Alpha is the best value that the maximizer currently can guarantee at that level or above.
  * Beta is the best value that the minimizer currently can guarantee at that level or above.
- Initial value of alpha = -infinity
- Initial value of beta = +infinity
- The rule which will be followed is: “Explore nodes if necessary otherwise prune the unnecessary nodes.”
- The above rule makes α-β Pruning much more efficient than Minimax Algorithm.
- In the average case, Time Complexity = O(b^(d/2))