var stackarr=[];
var topp=-1;

// function for push  in stack
function push(e)
{
   topp++;
   stackarr[topp]=e;
}

// function for pop from stack
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

// function operator for checking isoperator
function operator(op)
{
    if(op=='+' || op=='-' || op=='^' || op=='*' || op=='/' || op=='(' || op==')')
    {
        return true;
    }
    else
    return false;
}

// function for precedency
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

// function that convert infix to postfix
function InfixtoPostfix(infixval)
{
    var postfix=[];
    var temp=0;
    push('@');
   
    
    for(var i=0;i<infixval.length;i++)
    {
        var el=infixval[i];
        if(operator(el))
        {
            if (el ==')') {
                while (stackarr[topp] != "(") {
                  postfix[temp++] = pop();
                }
          pop();
            }
            else if(el=='(')
            {
                push(el);
            }
  // compare precedency 
            else if(precedency(el)>precedency(stackarr[topp]))
            {
                push(el);
            }
            else
            {
                while(precedency(el)<=precedency(stackarr[topp])&&topp>-1)
                {
                     postfix[temp++]=pop();
                }
                push(el);
            }
        }
        else{
            postfix[temp++]=el;
        }

        
    }
    while(stackarr[topp]!='@')
    {
        postfix[temp++]=pop();
    }
    var st="";
    for(var i=0;i<postfix.length;i++)
    {
        st+=postfix[i];
    }    

    // Print postfix expression in console
    
    console.log("Postfix Expression:- "+st);
 }
 
//  Caling Function InfixtoPostfix

 InfixtoPostfix("((a+b)*c)");




 /*
OutPut:
ab+c*

Time Complexity:O(N)
Space Complexity: O(N)

Input:
A+B*C/(E-F)

Output:
ABC*EF-/+


Input:
a+b*(c^d-e)^(f+g*h)-i

Output:
abcd^e-fgh*+^*+i-
 */
