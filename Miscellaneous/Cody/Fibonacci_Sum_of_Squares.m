% Given the Fibonacci sequence defined by the following recursive relation, F(n) = F(n-1) + F(n-2), determine the sum of squares for the first "n" terms.

function S = FSumSquares(n)

f = [0 1];
S = 1;

  for i = 2:n
      f = [f(2) sum(f)];
      S = S + (f(2)^2);
  end
end

% Test Case
% Input n = 5, Output S = 40;

% Time Complexity = O(n)
% Space Complexity = O(n)
