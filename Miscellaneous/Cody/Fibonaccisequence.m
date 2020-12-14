% Calculate the nth Fibonacci number.

function f = fib(n)
  f = [1 1];
  for i = 3:n
      f(i) = f(i-2) + f(i-1);
  end
  f=f(n);
end

% Test case
% Input  n = 7
% Output f = 13
