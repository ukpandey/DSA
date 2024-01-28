#include <iostream>
#include<queue>
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

int maxWidth(Node *root){
    if(!root) return 0;
    int ans = 0;
    queue<pair<Node*, int>> q;
    q.push({root,0});
    while(!q.empty()){
        int n = q.size();
        int first, last;
        int minIndex = q.front().second;
        for(int i=0; i<n; i++){
            Node* temp = q.front().first;
            int currid = q.front().second - minIndex;
            q.pop();
            if(i==0) first = currid;
            if(i==n-1) last = currid;

            if(temp->left)
                q.push({temp->left,currid*2+1});
            if(temp->right)
                q.push({temp->right, currid*2+2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"Max Width: "<<maxWidth(root);
}