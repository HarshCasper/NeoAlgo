// C++ program for Sparse Matrix Representation
// using Array
//A matrix is a two-dimensional data object made of m rows and n columns,
//therefore having total m x n values. If most of the elements
//of the matrix have 0 value, then it is called a sparse matrix.
#include <iostream>
using namespace std;
class Element
{
public:
    int row;
    int colmn;
    int entry;
};
class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele;
public:
    Sparse(int m,int n,int num)
    {
    this->m=m;
    this->n=n;
    this->num=num;
    ele=new Element[this->num];
        }
    ~Sparse()
    {
    delete [] ele;
    }
    Sparse operator+(Sparse &s);
    friend istream & operator>>(istream &is,Sparse &s);
    friend ostream & operator<<(ostream &os,Sparse &s);
};
Sparse Sparse::operator+(Sparse &s)
{
    int row,colmn,new_index;
    if(m!=s.m || n!=s.n)
        return Sparse(0,0,0);
    Sparse *sum=new Sparse(m,n,num+s.num);
    row=colmn=new_index=0;
    while(row<num && colmn<s.num)
    {
        if(ele[row].row<s.ele[colmn].row)
            sum->ele[new_index++]=ele[row++];
        else if(ele[row].row > s.ele[colmn].row)
            sum->ele[new_index++]=s.ele[colmn++];
        else
        {
        if(ele[row].colmn<s.ele[row].colmn)
            sum->ele[new_index++]=ele[row++];
        else if(ele[row].colmn > s.ele[colmn].colmn)
            sum->ele[new_index++]=s.ele[colmn++];
        else
        {
            sum->ele[new_index]=ele[row];
            sum->ele[new_index++].entry=ele[row++].entry+s.ele[colmn++].entry;
        }
        }
    }
    for(;row<num;row++)sum->ele[new_index++]=ele[row];
    for(;colmn<s.num;colmn++)sum->ele[new_index++]=s.ele[colmn];
    sum->num=new_index;
    return *sum;
}
    istream & operator>>(istream &is,Sparse &s)
    {
        cout<<"Enter non-zero elements";
        for(int row=0;row<s.num;row++)
            cin>>s.ele[row].row>>s.ele[row].colmn>>s.ele[row].entry;
        return is;
    }
    ostream & operator<<(ostream &os,Sparse &s)
    {
    int new_index=0;
    for(int row=0;row<s.m;row++)
    {
        for(int colmn=0;colmn<s.n;colmn++)
        {
        if(s.ele[new_index].row==row && s.ele[new_index].colmn==colmn)
            cout<<s.ele[new_index++].entry<<" ";
        else
            cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}
int main()
{
    int m;
    int n ;
    int num;
    cout<<"Enter No of Row " <<endl;
    cin>>m;
    cout<<"Enter No of Column " <<endl;
    cin>>n;
    cout<<"Enter No of Non-zero Entry " <<endl;
    cin>>num;
    Sparse s1(m,n,num);
    Sparse s2(m,n,num);

    cin>>s1;
    cin>>s2;
    Sparse sum=s1+s2;
    cout<<"First Matrix"<<endl<<s1;
    cout<<"Second Matrix"<<endl<<s2;
    cout<<"Sum Matrix"<<endl<<sum;
    return 0;

/*
Enter No of Row
5
Enter No of Column
5
Enter No of Non-zero Entry
5
Enter non-zero elements
0 0 1
1 1 1
2 2 1
3 3 1
4 4 1
Enter non-zero elements
0 0 2
1 0 2
2 0 2
3 0 2
4 0 2
First Matrix
1 0 0 0 0
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
Second Matrix
2 0 0 0 0
2 0 0 0 0
2 0 0 0 0
2 0 0 0 0
2 0 0 0 0
Sum Matrix
3 0 0 0 0
2 1 0 0 0
2 0 1 0 0
2 0 0 1 0
2 0 0 0 1

*/
}
