/*A linked list is a dynamic data structure which has two parts:- data and reference(pointer), which points to the
next node.Linkedlist is acollection of nodes where each node is connected to anext node using pointer.

Polynomial addition and multiplication can beimplemented using linked list.*/


#include<stdio.h>
#include<stdlib.h>

//node structure contains coefficient and exponent.
struct node
{
  int data;
  int expo;
  struct node *link;
} *p1, *p2, *p3, *head1, *head2, *res;
void create ();
void add ();
void multiply ();
void display ();
void main ()
{
  int opt;
  char ch;
  do
  {
      printf ("****MENU****\t\n1. ADD\t\n2. MULTIPLY\nEnter your choice : ");
      scanf ("%d", &opt);
      switch (opt)
	  {
	    case 1:
	    {
	        create ();
	        add ();
	        display ();
	        break;
	    }
	    case 2:
	    {
	        create ();
	        multiply ();
	        display ();
	        break;
	    }
        default:
	        printf ("Wrong choice : ");

	  }
      printf ("\nDo you want to continue  : ");
      scanf (" %c", &ch);
    }
  while (ch == 'y' || ch == 'Y');
}

//function to create polynmials.
void create ()
{
  int i, n;
  struct node *q1, *q2;
  head1 = (struct node *) malloc (sizeof (struct node));
  head1->data = -1;
  head1->expo = -1;
  head1->link = NULL;

  head2 = (struct node *) malloc (sizeof (struct node));
  head2->data = -1;
  head2->expo = -1;
  head2->link = NULL;

  res = (struct node *) malloc (sizeof (struct node));
  res->data = -1;
  res->expo = -1;
  res->link = NULL;

  q1 = head1;
  q2 = head2;
  printf ("Enter the number of terms for the first polynomial : ");
  scanf ("%d", &n);
  printf ("Enter the first polynomial(enter coefficients with their exponents) : ");
  for (i = 0; i < n; i++)
    {
      p1 = (struct node *) malloc (sizeof (struct node));
      scanf ("%d", &p1->data);
      scanf ("%d", &p1->expo);
      p1->link = NULL;
      q1->link = p1;
      q1 = p1;
    }

  printf ("Enter the number of terms for the second polynomial : ");
  scanf ("%d", &n);
  printf ("Enter the second polynomial(enter coefficients with their exponents) : ");
  for (i = 0; i < n; i++)
    {
      p2 = (struct node *) malloc (sizeof (struct node));
      scanf ("%d", &p2->data);
      scanf ("%d", &p2->expo);
      p2->link = NULL;
      q2->link = p2;
      q2 = p2;
    }
}

//function to add polynomials.
void add ()
{
  struct node *q;
  p1 = head1->link;
  p2 = head2->link;
  q = res;
  while (p1 != NULL && p2 != NULL)
  {
      //if the power of second polynomial is greater than the first polynomial,
      //store the values(coefficient and power) of 2nd polynomial in the resultant(p3).
      if (p1->expo < p2->expo)
	  {
	    p3 = (struct node *) malloc (sizeof (struct node));
	    p3->data = p2->data;
	    p3->expo = p2->expo;
	    p3->link = NULL;
	    p2 = p2->link;
	    q->link = p3;
	    q = p3;
	  }
	  
	  //if the power of first polynomial is greater than the second polynomial,
      //store the values(coefficient and power) of 1st polynomial in the resultant(p3).
      else if (p1->expo > p2->expo)
	  {
	    p3 = (struct node *) malloc (sizeof (struct node));
	    p3->data = p1->data;
	    p3->expo = p1->expo;
	    p3->link = NULL;
	    p1 = p1->link;
	    q->link = p3;
	    q = p3;
      }
      
      //if powers of the polynomials are same,
      //add the coefficients, copy the exponent and store it in the resultant.
      else
	  {
	    p3 = (struct node *) malloc (sizeof (struct node));
	    p3->data = p2->data + p1->data;
	    p3->expo = p2->expo;
	    p3->link = NULL;
	    p2 = p2->link;
	    p1 = p1->link;
	    q->link = p3;
	    q = p3;
	  }
  }
  while (p1 != NULL)
  {
    p3 = (struct node *) malloc (sizeof (struct node));
    p3->data = p1->data;
    p3->expo = p1->expo;
    p3->link = NULL;
    p1 = p1->link;
    q->link = p3;
    q = p3;
  }
  while (p2 != NULL)
  {
    p3 = (struct node *) malloc (sizeof (struct node));
    p3->data = p2->data;
    p3->expo = p2->expo;
    p3->link = NULL;
    p2 = p2->link;
    q->link = p3;
    q = p3;
  }
}

//function to multiply polynomials
void multiply()
{
  int ex, coeff, flag;
  struct node *q, *t;
  p1 = head1->link;
  q = res->link;
  while (p1 != NULL)
  {
    p2 = head2->link;
    while (p2 != NULL)
	{
	  flag = 0;
	  ex = p1->expo + p2->expo;
	  coeff = p1->data * p2->data;
	  q = res;
	  while (q != NULL)
	  {
	     
	    if (q->expo == ex)
		{
		  q->data = q->data + coeff;
		  flag++;
		}
	      t = q;
	      q = q->link;
	  }
	  if (flag == 0)
	  {
	      p3 = (struct node *) malloc (sizeof (struct node));
	      p3->data = coeff;
	      p3->expo = ex;
	      p3->link = NULL;
	      t->link = p3;
	  }
	  p2 = p2->link;
	}
    p1 = p1->link;
 }
}
//function to display the resultant polynomial.
void display()
{
  struct node *q;
  q = res->link;
  printf ("The resultant polynomial : ");
  while (q != NULL)
  {
    printf ("%dx^%d + ", q->data, q->expo);
    q = q->link;
  }
}


/*OUTPUT

****MENU****                                                                                                                     
1. ADD                                                                                                                           
2. MULTIPLY                                                                                                                      
Enter your choice : 1                                                                                                            
Enter the number of terms for the first polynomial : 3                                                                           
Enter the first polynomial : 3 2 6 1 8 0                                                                                         
Enter the number of terms for the second polynomial : 2                                                                          
Enter the second polynomial : 5 1 5 0                                                                                            
The resultant polynomial : 3x^2 + 11x^1 + 13x^0 +                                                                                
Do you want to continue  : y                                                                                                     
****MENU****                                                                                                                     
1. ADD                                                                                                                           
2. MULTIPLY                                                                                                                      
Enter your choice : 2                                                                                                            
Enter the number of terms for the first polynomial : 3                                                                           
Enter the first polynomial : 4 2 6 1 7 0                                                                                         
Enter the number of terms for the second polynomial : 1                                                                          
Enter the second polynomial : 1 1                                                                                                
The resultant polynomial : 4x^3 + 6x^2 + 7x^1 +                                                                                  
Do you want to continue  : n*?
