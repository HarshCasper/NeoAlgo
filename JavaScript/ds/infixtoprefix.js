/*
 This code converts infix expression to prefix expression in JavaScript.

 Infix expression:-  The expression of the form a op b. 
 When an operator is in-between every pair of operands.

 Prefix expression:-  An expression is called the prefix expression
  if the operator appears in the expression before the operands. 
  Simply of the form (operand1 operand2 operator). 

*/

var stackarr=[];
var topp=-1;

//function for push in stack
function push(e)
{
   topp++;
   stackarr[topp]=e;
}

// function for popping out from stack
function pop()
{
    if(topp==-1)
    return 0;
    else
    {
        var popped_ele=stackarr[topp];
        topp--;
        return popped_ele;
    }
}

//function to check is operator or not
function operator(op)
{
    return ((op=='+' || op=='-' || op=='^' || op=='*' || op=='/' || op=='(' || op==')')? true:false);
 
}

// function for checking precedency
function precedency(pre)
{
    if(pre=='@' || pre=='(' || pre==')')
    {
        return 1;
    }
    else if(pre=='+' || pre=='-')
    {
        return 2;
    }
    else if (pre=='/' || pre=='*')
    {
        return 3;
    }
    else if(pre=='^')
    {
        return 4;
    }
    else
    return 0;
}

// function for infix to prefix conversion
function InfixtoPrefix(infixval)
{
    var prefix=[];
    var temp=0;
    push('@'); 

    for(var i=infixval.length-1;i>=0;i--)
    {
        var el=infixval[i];
        if(operator(el))
        {
            if (el =='(') {
                while (stackarr[topp] != ")") {
                  prefix[temp++] = pop();
                }
                pop();
            }
            else if(el==')')
            {
                push(el);
            }
            
            // function for comparing precedency

            else if(precedency(el)>precedency(stackarr[topp]))
            {
                push(el);
            }
            else
            {
                while(precedency(el)<=precedency(stackarr[topp])&&topp>-1)
                {
                     prefix[temp++]=pop();
                }
                push(el);
            }
        }
        else{
            prefix[temp++]=el;
        }       
    }
    while(stackarr[topp]!='@')
    {
        prefix[temp++]=pop();
    }
    var st="";
    for(var j=prefix.length-1;j>=0;j--)
    {
        st+=prefix[j];
    }    
    console.log("Prefix Expression:- "+st);
 }
 InfixtoPrefix("((a+b)*c)");

 /*
Input:
Enter a valid Prefix Expression:- ((a+b)*c)

OutPut:
Prefix Expression:- *+abc

Input:
Enter a valid Prefix Expression:- A+B*C/(E-F)

Output:
Prefix Expression:- +A*B/C-EF

Input:
Enter a valid Prefix Expression:- a+b*(c^d-e)^(f+g*h)-i

Output:
Prefix Expression:- +a-*b^-^cde+f*ghi

Time Complexity:O(N)
Space Complexity: O(N)

 */
