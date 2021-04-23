/*
POLYNOMIAL MULTIPLICATION
Two polynomials are accepted as input from the user
Each coefficient of first polynomial is multiplied
with all the terms of second polynomial and
corresponding exponents are added
The product so obtained is traversed again
to find repeating power terms .These terms are
added and repeating terms are removed to get
the final product
*/

#include <stdio.h>
#include <stdlib.h>

//linked list to store polynomial
typedef struct Polynomial{
    int coef;
    int exp;
    struct Polynomial* link;
}Polynomial;
Polynomial* poly1,*poly2;

//to insert the terms of a polynomial
Polynomial* insertAtBeginning(Polynomial* list,int co,int ex){
    Polynomial* temp;
    temp=malloc(sizeof(Polynomial));
    temp->coef=co;
    temp->exp=ex;
    temp->link=list->link;
    list->link=temp;
    return list;
}

//to print the polynomial
void display(Polynomial* list){
    while(list->link!=NULL){
       list=list->link;
       printf("%dx^%d",list->coef,list->exp);
       if(list->link!=NULL)
          printf("+");
    }
}

//to multiply 2 polynomials
Polynomial* product(Polynomial*a,Polynomial*b){
    Polynomial *pro=malloc(sizeof(Polynomial));
    Polynomial*ptr1=a->link,*ptr2=b->link,*p=pro,*new;
    //to multiply each term of first polynomial with all terms
    //of second polynomial
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            new=malloc(sizeof(Polynomial));
            new->coef=ptr1->coef * ptr2->coef;
            new->exp=ptr1->exp+ptr2->exp;
            p->link=new;
            p=new;
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
        ptr2=b->link;
    }
    ptr1=pro->link;
    //to remove repeating terms
    while(ptr1!=NULL){
        ptr2=ptr1;
        while(ptr2->link!=NULL){
            if(ptr1->exp==ptr2->link->exp){
                p=ptr2->link;
                ptr1->coef+=ptr2->link->coef;
                ptr2->link=p->link;
                free(p);
            }
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
    return pro;
}

//driver code
int main() {
    poly1 =(Polynomial*)malloc(sizeof(Polynomial));
    poly2 =(Polynomial*)malloc(sizeof(Polynomial));
    Polynomial*new;
    int n,m,i,co;
    printf("Enter the degree of first polynomial: ");
    scanf("%d",&n);
    Polynomial*ptr1=poly1->link;
    printf("Enter the coefficients of first polynomial: ");
    for(i=0;i<=n;i++){
      scanf("%d",&co);
      insertAtBeginning(poly1,co,i);
    }
    printf("Enter the degree of second polynomial: ");
    scanf("%d",&m);
    Polynomial*ptr2=poly2;
    printf("Enter the coefficients of second polynomial: ");
    for(i=0;i<m;i++){
        scanf("%d",&co);
        insertAtBeginning(poly2,co,i);
    }
    printf("(");
    display(poly1);
    printf(")*(");
    display(poly2);
    printf(") = ");
    display(product(poly1,poly2));
    return 0;
}

/*
SAMPLE I/O:
Enter the degree of first polynomial: 3
Enter the coefficients of first polynomial: 1 2 3 4
Enter the degree of second polynomial: 2
Enter the coefficients of second polynomial: 3 2 1
(4x^3+3x^2+2x^1+1x^0)*(2x^1+3x^0) = 8x^4+18x^3+13x^2+8x^1+3x^0

Time Complexity: O(n*m) where n and m are the degrees of 2 polynomials
Space complexity : O(n) where n is the highest degree

*/
