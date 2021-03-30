
/*
Stack data structure is used to construct the binary tree.
Queue is used to print level order traversal of the binary tree.

this algorithm  is a 3 step process --repeat until queue is empty!!
        1. remove a node
        2. print/save the value
        3. add the children in the queue
*/


#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
  class Tree {
      public:
     int val;
    int state;
      Tree *left;
      Tree *right;
      Tree() 
      {
          val=0;
          state=0;
          left=NULL;
          right=NULL;
      } 
      
      Tree(int x,int s) 
      {
            val=x;
            state=s;
            left=NULL;
            right=NULL;
       
      }
      Tree(int val,int state,Tree *left, Tree *right) 
      { this->val=val;
        this->state=state;
        this->left=left;
        this->right=right;

      }

vector<vector<int>>Level_Order(Tree *root);
// FUNCTION TO DISPLAY THE TREE
// void display(Tree *root)     
// {
//     if(root==NULL)
//     return;

//     cout<<root->val<<" ";
//     display(root->left);
//     display(root->right);
// }
    
};



vector<vector<int>> Tree:: Level_Order(Tree* root) {
        
        vector<vector<int>>result;
        if(root==NULL)
        {
            return result;
        }
        queue<Tree*>q;
        //initially root is pushed in the queue
        q.push(root);
    
        //repeat until queue is empty
        while(q.size()>0)
        {       int count=q.size();
            vector<int>temp;
           
           for(int j=0;j<count;j++)
           {     Tree *t=q.front();
               temp.push_back(t->val);
             if(t->left)            
             {  
                 q.push(t->left);       //adding left child to queue
             }
            if(t->right)
            {
                q.push(t->right);       //adding right child to queue
            }
                q.pop();                //work done for this node..pop from the queue
           }
           
          result.push_back(temp);       //adding to the result vector
        }
       return result;
    }
int main()
{
int n=19;
int arr[]={50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};

Tree t;
stack<Tree*>st;
Tree *root=new Tree(arr[0],1);
st.push(root);
int i=1;


//USING STACK TO CONSTRUCT THE BINARY TREE

while(st.size()>0)
{
    if(st.top()->state==1)
    {   if(arr[i]!=-1)
            {
                Tree *node=new Tree(arr[i],1);
            st.top()->state++;
            st.top()->left=node;
            st.push(node);
           
            }
        else
        {   
            st.top()->left=NULL;
            st.top()->state++;
        }
         
    }
    else if(st.top()->state==2)
    {   if(arr[i]!=-1)
            {
                Tree *node=new Tree(arr[i],1);
            st.top()->state++;
            st.top()->right=node;
            if(st.top()->state==3)
        st.pop();
            st.push(node);
            
            }
        else
        {
            st.top()->right=NULL;
            st.top()->state++;
        }
        
        
    }
    if(st.top()->state==3)
    {
        st.pop();
    }

    i++;
}


//t.display(root);
cout<<endl;
    vector<vector<int>>res=t.Level_Order(root);
    //DISPLAYING LEVEL ORDER OF BINARY TREE!!
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        
        cout<<endl;
    }
}

// Output of the given binary tree.
//ith line represents nodes present in ith level


// 50
// 25 75
// 12 37 62 87
// 30 70
    









