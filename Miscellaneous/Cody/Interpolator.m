% You have a two vectors, a and b. They are monotonic and the same length. Given a value, va, where va is between a(1) and a(end) find the a(n), a(n+1) that flank it. Now interpolate the value, vb, such that it is proportionally between b(n) and b(n+1). va can land exactly on a value of a.

function vb = interpolator(va, a, b)
    for i = 1:length(a)
        if (a(i)<=va & va<=a(i+1))
            n = i;
            break;
        end
    end
    vb = (va-a(n))*(b(n+1)-b(n))/(a(n+1)-a(n)) + b(n);
end

% Test Case 
% Input va = 3, a = 1 : 1 : 10, b = 2 : 2 : 20, Output vb = 6

% Time Complexity = O(n)
% Space Complexity = O(n)
