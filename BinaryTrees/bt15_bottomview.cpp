#include <iostream>
#include<queue>
#include<map>
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

// same as top view
vector<int> bottomView(Node* root){
    vector<int> ans;
    map<int,int> mp;
    queue<pair<Node*, int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        Node* temp = front.first;
        int line = front.second;
        // if(mp.find(line)==mp.end()) this line  is for bottom view 
            mp[line] = temp->data;
        if(temp->left){
            q.push({temp->left,line-1});
        }
        if(temp->right){
            q.push({temp->right, line+1});
        }
    }
    for(auto it:mp){
        ans.push_back(it.second);
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
    vector<int> ans = bottomView(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
}