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
vector<int> preorderTraversal(Node *root){
    vector<int> ans;
    if(!root) return ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node *temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right)
            st.push(temp->right);
        if(temp->left)
            st.push(temp->left);
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

    vector<int> preorder = preorderTraversal(root);
    for(auto it:preorder)
        cout<<it<<" ";

}