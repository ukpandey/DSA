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

vector<vector<int>> bfs(Node* root){
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> row(n);
        for(int i=0; i<n; i++){
            Node *temp = q.front();
            q.pop();
            int index = leftToRight?i:n-1-i;
            row[index] = temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(row);
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
    vector<vector<int>> ans = bfs(root);
    for(auto rows:ans)
        for(auto it:rows)
            cout<<it<<" ";
}