/*
 Author : Sarthak Saxena (Sarthak-9).
 Program to evaluate PostFix Expression.Postfix is an arithmetic expression
 in which we place the operator after two operands. It has various applications.

*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
        int data;
        Node *next;
};

class Stack
{
private:
        Node *top;

public:
        Stack();
        ~Stack();
        void push(int x);
        int pop();
        int peek(int index);
        int isEmpty();
        int isFull();
        int stackTop();
};

Stack::Stack()
{
        top = nullptr;
}

Stack::~Stack()
{
        Node *p = top;
        while (top)
        {
                top = top->next;
                delete p;
                p = top;
        }
}

void Stack::push(int x)
{
        Node *t = new Node;
        if (t == nullptr)
        {
                cout << "Stack Overflow!" << endl;
        }
        else
        {
                t->data = x;
                t->next = top;
                top = t;
        }
}

int Stack::pop()
{
        Node *p;
        int x = -1;
        if (top == nullptr)
        {
                cout << "Stack Underflow!" << endl;
        }
        else
        {
                p = top;
                x = p->data;
                top = top->next;
                delete p;
        }
        return x;
}

int Stack::isFull()
{
        Node *t = new Node;
        int r = t ? 1 : 0;
        delete t;
        return r;
}

int Stack::isEmpty()
{
        return top ? 0 : 1;
}

int Stack::stackTop()
{
        if (top)
        {
                return top->data;
        }
        return -1;
}

int Stack::peek(int index)
{
        if (isEmpty())
        {
                return -1;
        }
        else
        {
                Node *p = top;

                for (int i = 0; p != nullptr && i < index - 1; i++)
                {
                        p = p->next;
                }

                if (p != nullptr)
                {
                        return p->data;
                }
                else
                {
                        return -1;
                }
        }
}

int isOperand(char x)
{
        if (x == '+' || x == '-' || x == '*' || x == '/')
        {
                return 0;
        }
        return 1;
}

int operation(char op, int x, int y)
{
        if (op == '+')
        {
                return x + y;
        }
        else if (op == '-')
        {
                return x - y;
        }
        else if (op == '*')
        {
                return x * y;
        }
        else if (op == '/')
        {
                return x / y;
        }
}

int postfixEvaluate(char *postfix)
{
        stack<int> stk;
        int x;
        int y;
        int result;
        for (int i = 0; postfix[i] != '\0'; i++)
        {
                if (isOperand(postfix[i]))
                {
                        stk.push(postfix[i] - '0');
                }
                else
                {
                        y = stk.top();
                        stk.pop();
                        x = stk.top();
                        stk.pop();
                        result = operation(postfix[i], x, y);
                        stk.push(result);
                }
        }
        result = stk.top();
        stk.pop();
        return result;
}

int Evaluate(char *postfix)
{
        Stack stk;
        int x;
        int y;
        int result;
        for (int i = 0; postfix[i] != '\0'; i++)
        {
                if (isOperand(postfix[i]))
                {
                        stk.push(postfix[i] - '0');
                }
                else
                {
                        y = stk.pop();
                        x = stk.pop();
                        result = operation(postfix[i], x, y);
                        stk.push(result);
                }
        }
        result = stk.pop();
        return result;
}

int main()
{

        char postfix[100];
        cout << "Enter the expression" << endl;
        cin >> postfix;
        cout << "The evaluated answer from Method 1 : " << Evaluate(postfix) << endl;
        cout << "The evaluated answer from Method 2 : " << postfixEvaluate(postfix) << endl;

        return 0;
}

/*
 Time Complexity: O(n)
 Space complexity: O(n)
 where n is the number of characters input in expression.
*/

/*
 Input :
 Enter the expression
 35*62/+4-

 Output :
 The evaluated answer from Method 1 : 14
 The evaluated answer from Method 2 : 14
 */

