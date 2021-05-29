/*
POLYNOMIAL ADDITION USING LINKED LISTS
2 polynomials are accepted as input from the user
and stored in linked lists.
Both polynomials are compared using exponents.
If a greater exponent is found the term is stored in
sum polynomial as such.
If both exponents are equal sum of the coefficients
are found and corresponding term is added to sum
polynomial
*/

#include <bits/stdc++.h>
using namespace std;

//linked list to store coefficients and exponents of polynomials
typedef struct Polynomial{
    int coef;
    int exp;
    struct Polynomial* link;
}Polynomial;
Polynomial* poly1,*poly2;

//to insert into the linked list
Polynomial* insertAtBeginning(Polynomial* list,int co,int ex){
    Polynomial* temp;
    temp=new Polynomial;
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

//to add the given polynomials
Polynomial* sum(Polynomial*a,Polynomial*b){
    Polynomial *sum=new Polynomial;
    Polynomial*ptr1=a->link,*ptr2=b->link,*s=sum,*new_node;
    while(ptr1!=NULL && ptr2!=NULL){
        new_node=new Polynomial;
        if(ptr1->exp>ptr2->exp){
            new_node->exp=ptr1->exp;
            new_node->coef=ptr1->coef;
            s->link=new_node;
            ptr1=ptr1->link;
        }
        else if(ptr1->exp<ptr2->exp){
            new_node->exp=ptr2->exp;
            new_node->coef=ptr2->coef;
            s->link=new_node;
            ptr2=ptr2->link;
        }
        else{
            new_node->coef=ptr1->coef+ptr2->coef;
            new_node->exp=ptr1->exp;
            s->link=new_node;
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        s=new_node;
        s->link=NULL;
    }
    return sum;
}

//driver code
int main() {
    poly1 =new Polynomial;
    poly2 =new Polynomial;
    int n,m,i,co;
    cout<<"Enter the degree of the first polynomial: ";
    cin>>n;
    Polynomial*ptr1=poly1->link;
    printf("Enter the coefficients of first polynomial from highest to least power:\n");
    for(i=0;i<=n;i++){
      cin>>co;
      insertAtBeginning(poly1,co,i);
    }
    cout<<"Enter the degree of the second polynomial: ";
    cin>>m;
    Polynomial*ptr2=poly2;
    printf("Enter the coefficients of second polynomial from highest to least power:\n");
    for(i=0;i<=m;i++){
        cin>>co;
        insertAtBeginning(poly2,co,i);
    }
    printf("(");
    display(poly1);
    printf(")+(");
    display(poly2);
    printf(") = ");
    display(sum(poly1,poly2));
    return 0;
}




/*
SAMPLE I/O
Enter the coefficients of first polynomial from least to highest power:
3 2 1 5
Enter the degree of the second polynomial: 4
Enter the coefficients of second polynomial from least to highest power:
1 2 4 3 6
(5x^3+1x^2+2x^1+3x^0)+(6x^4+3x^3+4x^2+2x^1+1x^0) = 6x^4+8x^3+5x^2+4x^1+4x^0

Time complexity : O(n)
Space Complexity: O(n)
*/
