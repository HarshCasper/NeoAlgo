% For a matrix of complex numbers C, return a corresponding matrix N such that each element of N is the iteration count n for each complex number c in the matrix C, subject to the iteration count limit of lim.
% The Mandelbrot Set is built around a simple iterative equation: z(1) = c, z(n+1) = z(n)^2 + c

function N = Mandelbrot(C,lim)
for i = 1:length(C(1,:))
     for j = 1:length(C(:,1))
         c = C(j,i);
         d = c;
        for t = 1:lim
            if (abs(d) > 2)
                x = t - 1;
                if (x == 0)
                    x = 1;
                end
                break;
            else
                d = d^2 + c;
                x = t;
            end
        end
         
        N(j,i) = x;
     end
end
end


% Test Case
% Input C = 0, lim = 5, Ouput N = 5

% Time Complexity = O(n)
% Space Complexity = O(n)
