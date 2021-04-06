/*
 This project converts infix expression to prefix expression in JavaScript.

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
    if(op=='+' || op=='-' || op=='^' || op=='*' || op=='/' || op=='(' || op==')')
    {
        return true;
    }
    else
    return false;
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
    for(var i=prefix.length-1;i>=0;i--)
    {
        st+=prefix[i];
    }    
    console.log("Prefix Expression:- "+st);
 }
 InfixtoPrefix("((a+b)*c)");
 

 /*
OutPut:
*+abc

Time Complexity:O(N)
Space Complexity: O(N)

Input:
A+B*C/(E-F)

Output:
+A*B/C-EF


Input:
a+b*(c^d-e)^(f+g*h)-i

Output:
+a-*b^-^cde+f*ghi
 */