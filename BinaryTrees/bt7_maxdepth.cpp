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

int maxDepth(Node *root){
    if(!root) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh,rh);
}

int maxDepthBFS(Node* root) {
        int depth = 0;
        
        if (root == NULL) return depth;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                if (temp -> left != NULL) q.push(temp -> left);
                if (temp -> right != NULL) q.push(temp -> right);
            }
        }
        
        return depth;
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
    root->left->left->left->right = new Node(9);
    cout<<"Max Depth: "<<maxDepth(root);
    cout<<"\nMax Depth DFS: "<<maxDepthBFS(root);

}