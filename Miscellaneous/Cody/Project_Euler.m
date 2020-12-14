% By considering the terms in the Fibonacci sequence whose values do not exceed the input value, find the sum of the even-valued terms.

function y = euler002(x)
a1 = 1;
a2 = 2;
y = 0

while (a2 < x)
    temp = a2;
    a2 = a1 + a2;
    a1 = temp

    if (~ mod (p1,2))
        y = y + a1
    end
end
end

% Test Case
% Input x = 597455000, Output y = 350704366

% Time Complexity = O(n)
% Space Complexity = O(n)
