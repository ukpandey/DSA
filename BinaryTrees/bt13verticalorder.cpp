#include <iostream>
#include<vector>
#include<set>
#include<map>
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
vector<vector<int>> verticalOrderTraversal(Node* root){
    map<int,map<int, multiset<int>>> mp;
    int x=0, y=0;
    queue<pair<Node*, pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
       auto front = q.front();
       q.pop();
       Node* temp = front.first;
       int x = front.second.first;
       int y = front.second.second;
       mp[x][y].insert(temp->data);
       if(temp->left){
        q.push({temp->left,{x-1, y+1}});
       }
       if(temp->right){
        q.push({temp->right,{x+1, y+1}});
       }
    }

    vector<vector<int>> ans;
    for(auto it:mp){
        for(auto it2:it.second){
            vector<int> col;
            for(auto it3:it2.second){
                // cout<<it3<<" ";
                col.push_back(it3);
            }
            // cout<<endl;
            ans.push_back(col);
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
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    vector<vector<int>> ans = verticalOrderTraversal(root);
    for(auto col:ans){
        for(auto it:col)
            cout<<it<<" ";
        cout<<endl;
    }
}