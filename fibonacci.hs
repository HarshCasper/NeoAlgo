-- An infinite Fibonacci sequence algorithm using set comprehension and cons
fib = 1 : 1 : [a+b | (a,b) <- zip fib (tail fib)]

-- Definition for the n-th fibonacci algorithm
fibN :: Int -> Integer
-- Pattern match for the int 0
fibN 0 = 0
-- Takes the n-th Fibonacci number by taking the 0-indexed offset from the resulting list
fibN n | n < 0 = error "cannot take a negative input"
       | otherwise = fib!!(n-1)

{-
 Use case:
 input: fibN 10
 output: 55

 input: fibN 0
 output: 0
 
 input: fibN (-5)
 output: *** Exception: cannot take a negative input
-}
