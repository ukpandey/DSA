#include <iostream>
#include<vector>
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
void reversePreOrder(Node *root, vector<int> &ans, int level){
    if(!root) return;
    if(level == ans.size())
        ans.push_back(root->data);
    reversePreOrder(root->right, ans, level+1);
    reversePreOrder(root->left, ans, level+1);
}
vector<int> rightView(Node* root){
    vector<int> ans;
    reversePreOrder(root,ans,0);
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
    vector<int> ans = rightView(root);
    for(auto it:ans)
        cout<<it<<" ";
}