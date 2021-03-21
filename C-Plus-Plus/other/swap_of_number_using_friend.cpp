/*
-swapping is used to change the value of data member.
-both the data members are declared in different classes.
-swap function will act as friend function of both the classes.
*/

#include <iostream>
using namespace std;

// c2 is declared first so that friend function can be easily made.
class c2;

// c1 class has a data member 'a'.
class c1
{
    int a;

public:
    void setdata(int x)
    {
        a = x;
    }
    void display()
    {
        cout << "The value of a is " << a << endl;
    }
    friend void swap(c1 &, c2 &);
};


// c2 class has a data member 'b' .
class c2
{
    int b;

public:
    void setdata(int y)
    {
        b = y;
    }
    void display()
    {
        cout << "The value of b is " << b << endl;
    }
    friend void swap(c1 &, c2 &);
};


// swap is a friend function which will swap the values using call by reference.
void swap(c1 &o1, c2 &o2)
{
    int temp;
    temp = o1.a;
    o1.a = o2.b;
    o2.b = temp;
}


int main()
{

    int a, b;
    cout << "Enter value of a: ";
    cin >> a;
    cout << "Enter value of b: ";
    cin >> b;

    c1 x; // object created
    c2 y;

    cout << "Before:-" << endl;
    x.setdata(a);
    x.display();

    y.setdata(b);
    y.display();

    swap(x, y);

    cout << "After:-" << endl;
    x.display();
    y.display();

    return 0;
}

/*
Sample I/O:-

       1.  Enter value of a: 5
           Enter value of b: 3
           Before:-
           The value of a is 5
           The value of b is 3
           After:-
           The value of a is 3
           The value of b is 5

       2. Enter value of a: 8
          Enter value of b: 9
          Before:-
          The value of a is 8
          The value of b is 9
          After:-
          The value of a is 9
          The value of b is 8

*/