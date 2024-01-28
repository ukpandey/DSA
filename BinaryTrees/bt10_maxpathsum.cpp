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
int useDiameterandHieght(Node *root, int &maxi){
    if(!root) return 0;
    // we will not consider negative sum 
    int leftSum = max(0,useDiameterandHieght(root->left, maxi));
    int rightSum = max(0,useDiameterandHieght(root->right, maxi));
    maxi = max(maxi, leftSum + rightSum + root->data);
    // return 1+ max(lh,rh) 
    return root->data + max(leftSum,rightSum);
}
int maxPathSum(Node *root){
    int maxi = INT32_MIN;
    useDiameterandHieght(root,maxi);
    return maxi;
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
    cout<<maxPathSum(root);
}