#include <iostream>
#include <queue>
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

void inorderTraversal(Node *root, vector<int> &inorder){
    if(!root) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right,inorder);
}
void preorderTraversal(Node *root, vector<int> &preorder){
    if(!root) return;
    preorder.push_back(root->data);
    preorderTraversal(root->left, preorder);
    preorderTraversal(root->right, preorder);
}
void postorderTraversal(Node *root, vector<int> &postorder){
    if(!root) return;
    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);
    postorder.push_back(root->data);
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
   
    vector<int> preorder,postorder,inorder;

    preorderTraversal(root,preorder);
    inorderTraversal(root,inorder);
    postorderTraversal(root,postorder);

    cout<<"Prorder: ";
    for(auto it:preorder)
        cout<<it<<" ";
    
    cout<<"\nInorder: ";
    for(auto it:inorder)
        cout<<it<<" ";
    
    cout<<"\nPostorder: ";
    for(auto it:postorder)
        cout<<it<<" ";

}