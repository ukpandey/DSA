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
vector<int> inorderTraversal(Node *root){
    vector<int> ans;
    stack<Node*> st;
    Node *temp = root;
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()) break;
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
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

    vector<int> inorder= inorderTraversal(root);
    for(auto it:inorder)
        cout<<it<<" ";

}