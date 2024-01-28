#include <iostream>
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
int dfsHieght(Node *root){
    if(!root) return 0;
    int lh = dfsHieght(root->left);
    int rh = dfsHieght(root->right);
    if(lh==-1 || rh==-1) return -1;
    if(abs(lh-rh) > 1) return -1;
    return 1 + max(lh,rh); 
}
bool isBalanced(Node* root){
    return dfsHieght(root) != -1;
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
    root->left->left->left = new Node(8);
    root->left->left->left->left = new Node(9);
    cout<<isBalanced(root);
}