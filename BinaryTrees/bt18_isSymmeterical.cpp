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
bool isSymmetericHelp(Node *left, Node* right){
    if(!left || !right) return left==right;
    if(left->data != right->data) return false;
    return isSymmetericHelp(left->left, right->right)
            &&
           isSymmetericHelp(left->right, right->left);
}
bool isSymmeterical(Node *root){
    return root==NULL || isSymmetericHelp(root->left, root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    cout<<isSymmeterical(root);
}