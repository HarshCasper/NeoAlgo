/*  Ackermann function is one of the simplest examples of a total computable function,
    that is not primitive recursive.
    It’s a function with two arguments,
    each of which can be assigned any non-negative integer. */ 

const ackermann = (m, n) => {
	if (m === 0) 
	  return n+1;
	if (n === 0)
	  return ackermann((m - 1), 1);
	return ackermann((m-1), ackermann(m, (n-1)));
}

console.log(`The result is : ${ackermann(2, 4)}`);

/*  Output Screen =>

    The result is : 11

    Time complexity : O(mA(m, n))
    Space complexity : O(m) */