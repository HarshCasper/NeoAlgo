/*
Infix expression:-  The expression of the form a op b. 
When an operator is in-between every pair of operands.

Postfix expression:-  An expression is called the postfix expression
if the operator appears in the expression after the operands. 

This program is for evaluating infix expression.
In this first we have to convert the infix expression into postfix expression.
Then evaluate postfix expression using stack. Give an evaluated value.
*/ 

// creating stackarr 
var stackarr=[];

// Initialize topp variable with -1
var topp=-1;

// creating evalstack
var evalstack=[];

// function for evaluating postfix expression
function postfixevaluator(evalst)
{
    eval=evalst.split("$");
   for(var i=0;i<eval.length-1;i++)
   {
       if(!operator(eval[i]))
       {
           push(eval[i]);
       }
       else
       {
           var op1=parseInt(pop());
           var op2=parseInt(pop());
           
           if(eval[i]=="+")
           {
               push(op2+op1);
           }
           else if(eval[i]=="-")
           {
               push(op2-op1);
           }
           else if(eval[i]=="*")
           {
               push(op2*op1);
           }
           else
           {
               push(op2/op1);
           }
       }
   }
   console.log(pop());
}

// function for push 
function push(e)
{
   topp++;
   stackarr[topp]=e;
}

// function for pop out
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

// function for checking whether operator or not 
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

// function for converting infix expression into postfix expression
function InfixtoPostfix(infixstring)
{
    var postfix=[];
    var temp=0;
    push('@');
    var infixval=[];
    var temp2="";
    for(var i=0;i<infixstring.length;i++)
    {
        if(operator(infixstring[i]))
        {
            infixval.push(temp2);
            infixval.push(infixstring[i]);
            temp2="";
        }
        else temp2+=infixstring[i];
    }
    if(temp2!=="")
    {
        infixval.push(temp2);
    }
   
    for(var i=0;i<infixval.length;i++)
    {
        var el=infixval[i];
        if(operator(el))
        {
            if (el ==')') {
                while (stackarr[topp] != "(") {
                  postfix[temp++] = pop();
                  postfix[temp++]="$";
                }
          pop();
            }
            else if(el=='(')
            {
                push(el);
            }

            else if(precedency(el)>precedency(stackarr[topp]))
            {
                push(el);
            }
            else
            {
                while(precedency(el)<=precedency(stackarr[topp])&&topp>-1)
                {
                     postfix[temp++]=pop();
                     postfix[temp++]="$"
                }
                push(el);
            }
        }
        else{
            postfix[temp++]=el;
            postfix[temp++]="$"
        }

        
    }
    while(stackarr[topp]!='@')
    {
        postfix[temp++]=pop();
        postfix[temp++]="$"
    }
    var st="";
    
    for(var i=0;i<postfix.length;i++)
    {
        st+=postfix[i];
    }

   // Calling postfixevaluator function for evaluating evaluating postfix expression 
   postfixevaluator(st);
 }

 //In-Built readline module
const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const getLine = (function () {
  const getLineGen = (async function* () {
    for await (const line of rl) {
      yield line;
    }
  })();
  return async () => (await getLineGen.next()).value;
})();

const main = async () => {

    //Taking infix expression as input
    console.log("Enter the infix expression: ");
    var number1 = String(await getLine());

    // Caling Function InfixtoPostfix
    InfixtoPostfix(number1);

    //To close the program
    process.exit(0);
  };

  main();

/*
 Input: 
 Enter the infix expression: 2+3*4
 
 Output:
 Evaluated value: 14

 Input:
 Enter the infix expression: 4+6*3-6

 Output:
 Evaluated value: 16

 Time Complexity: O(n)
 Space Complexity: O(n)
 */
