#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *prev;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *cur = st.top();
        st.pop();

        if (cur->right != NULL)
        {
            st.push(cur->right);
        }
        if (cur->left != NULL)
        {
            st.push(cur->left);
        }
        if (!st.empty())
        {
            cur->right = st.top();
        }
        cur->left = NULL;
    }
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

    flatten(root);
    while(root!=NULL){
        cout<<root->data<<" ";
        root = root->right;
    }
}