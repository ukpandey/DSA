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
// simple hai
// bhai check kar pehle ki jo 2 nodes hai unme se koi node mili ya nhi 
// agar milgyi toh vo node return karde
// agar hume left or right dono mai nodes milgyi iska matlab uss node k left
// or right mai dono nodes hai , hence vhi node humari lca hogi
// nhi toh agar left mili to left return kardo or agar right mili to right.
Node* lowestCommonAncesstor(Node *root, Node *p, Node*q){
    if(!root || root==p || root==q){
        return root;
    }
    Node* left = lowestCommonAncesstor(root->left, p, q);
    Node* right = lowestCommonAncesstor(root->right, p, q);

    if(!left) return right;
    else if(!right) return left;
    else return root;
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

    Node *lca = lowestCommonAncesstor(root, root->left->left, root->left->right);
    cout<<lca->data;
}