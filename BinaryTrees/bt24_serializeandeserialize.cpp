#include <iostream>
#include<queue>
#include<sstream>
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
string serialize(Node *root){
    string s = "";
    if(!root) return s;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp != NULL){
            s.append(to_string(temp->data)+",");
        }
        else
            s.append("#,");
        
        if(temp!=NULL){
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return s;
}

Node* deSerialize(string data){
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *node = q.front();
        q.pop();

        getline(s,str,',');
        if(str == "#"){
            node->left = NULL;
        }
        else{
            Node *leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s,str,',');
        if(str == "#"){
            node->right = NULL;
        }
        else{
            Node *rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void traverse(Node *root){
    if(!root) return ;
    cout<<root->data<<" ";
    traverse(root->left);
    traverse(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    string data = serialize(root);
    cout<<data<<endl;
    Node*ans = deSerialize(data);
    traverse(ans);
}