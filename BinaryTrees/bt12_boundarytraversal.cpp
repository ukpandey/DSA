#include <iostream>
#include <queue>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isLeaf(Node*root){
    if(!root->left && !root->right) return true;
    return false;
}
void addLeftBoundary(Node *root, vector<int> &ans){
    if(!isLeaf(root))
        ans.push_back(root->data);
    Node *curr = root->left;
    while(curr){
        if(!isLeaf(curr))
         ans.push_back(curr->data);
        if(curr->left){
            curr = curr->left;
        }
        else 
            curr = curr->right;
    }
}

void addLeaves(Node *root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left)
        addLeaves(root->left, ans);
    if(root->right)
        addLeaves(root->right, ans);
     
}

void addRightBoundary(Node *root, vector<int> &ans){
    stack<int> st;
    Node *curr = root->right;
    while(curr){
        if(!isLeaf(curr)){
            st.push(curr->data);
        }
        if(curr->right)
            curr = curr->right;
        else 
            curr = curr->left;
    }
    while(!st.empty()){
        int x = st.top();
        st.pop();
        ans.push_back(x);
    }
}

vector<int> boundaryOrderTraversal(Node *root){
    vector<int> ans;
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->right->left = new Node(10);
    vector<int> ans = boundaryOrderTraversal(root);
    for(auto it: ans)
        cout<<it<<" ";
}