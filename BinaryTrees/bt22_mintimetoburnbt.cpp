#include <iostream>
#include<queue>
#include<map>
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

int bfsToBurnTree(Node* startNode, map<Node*, Node*> mp){
    int time = 0;
    map<Node*, int> vis;
    vis[startNode] = 1;
    queue<Node*> q;
    q.push(startNode);
    while(!q.empty()){
        int n = q.size();
        int flag = 0;
        for(int i=0; i<n; i++){
            Node *temp = q.front();
            q.pop();
            if(temp->left && !vis[temp->left]){
                q.push(temp->left);
                vis[temp->left] = 1;
                flag = 1;
            }
            if(temp->right && !vis[temp->right]){
                q.push(temp->right);
                vis[temp->right] = 1;
                flag = 1;
            }
            if(mp[temp] && !vis[mp[temp]]){
                q.push(mp[temp]);
                vis[mp[temp]] = 1;
                flag = 1;
            }
        }
        if(flag) time++;
    }
    return time;
}

// this function will map parents and child and also return the target node if not given
Node* bfstoMapParents(Node* root, int target , map<Node*,Node*> &mp){
    Node* targetNode;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        if(temp->data == target){
            targetNode = temp;
        }
        q.pop();
        if(temp->left){
            q.push(temp->left);
            mp[temp->left] = temp;
        }
        if(temp->right){
            q.push(temp->right);
            mp[temp->right] = temp;
        }
    }
    return targetNode;
}
int minTime(Node* root, int target){
    map<Node*, Node*> mp;
    Node* targetNode = bfstoMapParents(root,target,mp);
    int ans = bfsToBurnTree(targetNode, mp);
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
    cout<<minTime(root,2);
}