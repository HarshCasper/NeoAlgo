#include<bits/stdc++.h>
using namespace std;
class TreeNode {
    public :
    int freq;
    char symbol;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        this->freq = 0;
        this->symbol = '*';
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};
void printTree(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
            continue;
        }
        cout<<curr->symbol<<curr->freq;
        cout<<"  ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}
vector<TreeNode*> ReverseLevelOrder(TreeNode* root){
    vector<TreeNode*> reverse_level_order;
    vector<TreeNode*> current;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr==NULL){
            current.insert(current.end(),reverse_level_order.begin(), reverse_level_order.end());
            reverse_level_order = current;
            current.clear();
            if(!q.empty())
                q.push(NULL);
            continue;
        }
        current.push_back(curr);
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    return reverse_level_order;
}
void correctTree(TreeNode* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        return;
    }
    correctTree(root->left);
    correctTree(root->right);
    int freq = 0;
    if(root->left){
        freq+=root->left->freq;
    }
    if(root->right){
        freq += root->right->freq;
    }
    if(root->freq!=freq){
        root->freq = freq;
    }
}
void swapTreeNode(TreeNode* root,TreeNode* a,TreeNode* b){
    TreeNode* parentA = a->parent;
    TreeNode* parentB = b->parent;
    a->parent = parentB;
    b->parent = parentA;
    if(parentA->left == a){
        parentA->left = b;
    }
    else{
        parentA->right = b;
    }
    if(parentB->left == b){
        parentB->left = a;
    }
    else{
        parentB->right = a;
    }
    correctTree(root);
}

void getCodes(TreeNode* n,string code){
    if(n->left == NULL && n->right == NULL){
            if(n->symbol=='*'){
                return;
            }
		cout <<"'"<< n->symbol << "':" << code << " ";
		return;
	}
	getCodes(n->left, code + "0");
	getCodes(n->right, code + "1");
}

TreeNode* insertIntoTree(TreeNode* insertion,TreeNode* node){
    TreeNode* newInsertion = new TreeNode();
    insertion->freq++;
    insertion->right = node;
    node->parent = insertion;
    insertion->left = newInsertion;
    newInsertion->parent = insertion;
    while(insertion->parent!=NULL){
        insertion->parent->freq++;
        insertion = insertion->parent;
    }
    return newInsertion;
}
TreeNode* checkTree(TreeNode* root){
    vector<TreeNode*> seq = ReverseLevelOrder(root);
    for(int i=0;i<seq.size()-1;i++){
        if(seq[i]->freq>seq[i+1]->freq){
            for(int j=seq.size()-1;j>i;j--){
                if(seq[j]->freq < seq[i]->freq){
                    swapTreeNode(root,seq[i],seq[j]);
                    TreeNode* temp = seq[i];
                    seq[i] = seq[j];
                    seq[j] = temp;
                    i--;
                    break;
                }
            }
        }
    }
    return root;
}
void dynamic_huffman(string input){
    TreeNode* root = new TreeNode();
    TreeNode* insertion = root;
    unordered_map<char,int> apperance;
    unordered_map<char,TreeNode*> node;
    for(int i=0;i<input.size();i++){
        if(apperance[input[i]]==0){
            TreeNode* current = new TreeNode();
            current->freq = 1;
            current->symbol = input[i];
            insertion = insertIntoTree(insertion,current);
             node[input[i]] = current;
             apperance[input[i]]++;
        }
        else{
            TreeNode* current = node[input[i]];
            current->freq++;
            while(current->parent!=NULL){
                current->parent->freq++;
                current = current->parent;
            }
        }

        root = checkTree(root);
        printTree(root);
        cout<<"Codes:\t";
        getCodes(root,"");
        cout<<endl<<endl;
    }

}
int main(){
    string input;
    cout<<"Enter the input string:\t";
    getline(cin,input);
    dynamic_huffman(input);
    return 0;
}
