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
int dfsHieght(Node *root, int &diameter){
    if(!root) return 0;
    int lh = dfsHieght(root->left, diameter);
    int rh = dfsHieght(root->right, diameter);
    diameter = max(diameter, lh+rh); // you can do lh+rh+1 here if you have to include the parent node as well
    return 1+max(lh,rh);
}
int findDiameter(Node *root){
    int diameter = 0;
    dfsHieght(root, diameter);
    return diameter;
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
    root->left->right->right = new Node(5);
    root->right->left->left = new Node(9);
    cout<<findDiameter(root);
}