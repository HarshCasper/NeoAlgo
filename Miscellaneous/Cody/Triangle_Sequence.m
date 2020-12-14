% Each triangle in the sequence is constructed so that its second longest side is the hypotenuse of the previous triangle and its shortest side is the same length as the second longest side of the previous triangle. What is the area of a square whose side is the hypotenuse of the nth triangle in the sequence?

function area = triangle_sequence(n)
  a=3; b=4; c=5;
  if n == 1
      area = c^2;
  else
     for i = 2:n
         a = b;
         b = c;
         c = sqrt (a^2 + b^2);
     end
     area = c^2;
  end
end

% Test Case
% Input n = 2, Output area = 41, Tolerance = 1e-12

% Time Complexity = O(n)
% Space Complexity = O(n)
