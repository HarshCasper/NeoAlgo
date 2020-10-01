const factorial = (n) => {
    let res = [];
    
		// Initialize result
		res[0] = 1;
    let resSize = 1;
    
		// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
		for (let x = 2; x <= n; x++) {
        resSize = multiply(x, res, resSize);
    }

    console.log("Factorial of given number is ");
    var s = "";
		for (let i = resSize - 1; i >= 0; i--) {
        s = s + res[i];
    }

    console.log(s);
}

// for multiplications
const multiply = (x, res, resSize) => {
    let carry = 0; // Initialize carry 
    
		// One by one multiply n with individual digits of res[]
		for (let i = 0; i < resSize; i++)
		{
			  let prod = res[i] * x + carry;
			  res[i] = prod % 10; // Store last digit of 'prod' in res[]
			  carry = Math.floor(prod / 10); // Put rest in carry
    }
    
		// Put carry in res and increase result size
		while (carry!=0)
		{
			  res[resSize] = carry % 10;
			  carry = Math.floor(carry / 10);
			  resSize++;
    }
    
		return resSize;
}

factorial(25);
factorial(50);

/**
 * Sample output for above input:
 * Factorial of given number is 
 * 15511210043330985984000000
 * Factorial of given number is 
 * 30414093201713378043612608166064768844377641568960512000000000000
 * 
 * Time complexity: O(log(N!))
 */