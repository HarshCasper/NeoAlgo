/******************************************************************************
Author - @Suvraneel 
        Suvraneel Bhuin
* Implementation of a Polynomial Addition & multiplication using Linked Lists in Java *
******************************************************************************/

import java.util.*;
class LinkedList
{
	// Structure containing exponent and coefficient of variable 
	static class Term { 
		int coefficient;
		int exponent;
		//Link to next Term in singly LL
		Term link; 
	}

	// Function add a new Term at the end of list 
	static Term addTerm(Term head, int coefficient, int exponent) 
	{
		// Create a new Term 
		Term nd = new Term(); 
		nd.coefficient = coefficient; 
		nd.exponent = exponent;
		//Link pointing to null because this is leaf node as of yet
		nd.link = null; 

		// If linked list is empty
		if (head == null) 
			return nd;

		// Initiate a pointer at the head to start traversal 
		Term ptr = head;
		// Traverse until leaf Term
		while (ptr.link != null) 
			ptr = ptr.link;
		//return leaf term
		ptr.link = nd; 
		return head; 
	} 

	// Function to collapse the expanded form by merging duplicates in 1 term
	static void collapse(Term head) 
	{ 
		Term polyA;
		Term polyB;
		polyA = head; 
		//outer loop => for every term in poynomial,
		while (polyA != null && polyA.link != null) { 
			polyB = polyA;
			//inner loop => iterate through the rest of the loop to find redundant elements
			while (polyB.link != null) {
				// If exponent of two elements are same
				if (polyA.exponent == polyB.link.exponent) { 
					// Collapse them onto the 1st occurance of that term (ie, term currently in outer loop)
					polyA.coefficient += polyB.link.coefficient;
					polyB.link = polyB.link.link;
				}
				// If exponent not same, check the other terms - inner loop
				else polyB = polyB.link;
			}
			//check similarly for the next term as well - outer loop
			polyA = polyA.link;
		}
	}

	// Function two Add two polynomial Numbers 
	static Term sum(Term poly1, Term poly2, Term sumPoly) 
	{ 
		// Initiate 2 pointers for the 2 polynomials
		Term polyA;
		polyA = poly1;
		Term polyB;
		polyB = poly2;
		// Copy the terms of 1st polynomial to sumpoly
		while (polyA != null) {
			sumPoly = addTerm(sumPoly, polyA.coefficient, polyA.exponent);
			polyA = polyA.link;
		}
		//Add the terms of 2nd polynomial to sumPoly
		while (polyB != null) {
			sumPoly = addTerm(sumPoly, polyB.coefficient, polyB.exponent);
			polyB = polyB.link;
		}
		//call collapse function to minimise number of similar terms
		collapse(sumPoly);
		return sumPoly;
	}

	// Function two Multiply two polynomial Numbers 
	static Term multiply(Term poly1, Term poly2, Term pdtPoly) 
	{ 
		// Initiate 2 pointers for traversing the 2 polynomials
		Term polyA;
		Term polyB;
		polyA = poly1;
		polyB = poly2;
		//for every term in 1st polynomial, multiply it with each term in 2nd polynomial
		while (polyA != null) { 
			while (polyB != null) {
				int coefficient;
				int exponent;
				// Add the exponents to get result exponent
				exponent = polyA.exponent + polyB.exponent; 
				// Call Multiply function passing the coefficients
				coefficient = polyA.coefficient * polyB.coefficient; 
				// call addTerm function passing 3 parameters
				// thus adding the resultant term as node in the resultant polynomial
				pdtPoly = addTerm(pdtPoly, coefficient, exponent); 
				// move the pointer to the next term (node)
				polyB = polyB.link; 
			} 
			// Reset the pointer for new loop
			polyB = poly2; 
			//move the pointer to the next term (node) 
			polyA = polyA.link; 
		} 
		// collapse function (since pdt is in expanded form, minimise it)
		collapse(pdtPoly); 
		return pdtPoly; 
	} 

	// Function To Display The passed polynomial's LL
	static void displayPoly(Term ptr) 
	{ 
		//traverse & keep printing as long as leaf node is not found
		while (ptr.link != null) { 
			System.out.print( ptr.coefficient + "x^" + ptr.exponent + " + ");
			ptr = ptr.link; 
		}
		// Print the leaf node (ie, coefficient of x^0 term) 
		System.out.print( ptr.coefficient +"\n"); 
	} 

	// Main Driver Code 
	public static void main(String[] args) 
	{ 
		//Initiate nodes for holding input polynomials & resultant polynomials to null
		Term poly1 = null;
		Term poly2 = null;
		Term sumPoly = null;
		Term pdtPoly = null;
		Scanner myObj = new Scanner(System.in);

		//Take input for 1st polynomial
		System.out.print("Enter number of terms in 1st Polynomial: \t");
		int noOfTerms = myObj.nextInt();
		System.out.print("Enter 1st Polynomial as <coefficient exponent> : \t"); 
		for (int i=0; i<noOfTerms; i++){
			int coff = myObj.nextInt();
			int exp = myObj.nextInt();
			// Add the term as a node into the 1st polynomial LL
			poly1 = addTerm(poly1, coff, exp);
		}

		//Take input for 2nd polynomial
		System.out.print("Enter number of terms in 2nd Polynomial: \t");
		noOfTerms = myObj.nextInt();
		System.out.print("Enter 2nd Polynomial as <coefficient exponent> : \t"); 
		for (int i=0; i<noOfTerms; i++){
			int coff = myObj.nextInt();
			int exp = myObj.nextInt();
			// Add the term as a node into the 2nd polynomial LL
			poly2 = addTerm(poly2, coff, exp);
		}
		
		// Displaying 1st polynomial 
		System.out.print("1st Polynomial = \t\t"); 
		displayPoly(poly1); 
		// Displaying 2nd polynomial 
		System.out.print("2nd Polynomial = \t\t"); 
		displayPoly(poly2); 

		//calling sum function to evaluate (poly1 + poly2)
		sumPoly = sum(poly1, poly2, sumPoly);
		System.out.print( "Resultant Sum Polynomial = \t"); 
		displayPoly(sumPoly);

		// calling multiply function to evaluate (poly1 * poly2)
		pdtPoly = multiply(poly1, poly2, pdtPoly); 
		// Displaying Resultant Polynomial 
		System.out.print( "Resultant Product Polynomial = \t"); 
		displayPoly(pdtPoly); 
	}
}

/*
Time Complexity: O(n^2)
  AddTerm = O(n)
  Collapse = O(n^2)
  Sum = O(n^2) (for collapse call)
  Multiply = O(n^2)
  Print LL = O(n)
Sample Run:
  Enter number of terms in 1st Polynomial:        5
  Enter 1st Polynomial as <coefficient exponent> :        10 6 5 4 3 3 4 1 7 0
  Enter number of terms in 2nd Polynomial:        3
  Enter 2nd Polynomial as <coefficient exponent> :        6 3 2 1 5 0
  1st Polynomial =        		10x^6 + 5x^4 + 3x^3 + 4x^1 + 7
  2nd Polynomial =        		6x^3 + 2x^1 + 5
  Resultant Sum Polynomial =      10x^6 + 5x^4 + 9x^3 + 6x^1 + 12
  Resultant Product Polynomial =  60x^9 + 50x^7 + 68x^6 + 10x^5 + 55x^4 + 57x^3 + 8x^2 + 34x^1 + 35
*/

