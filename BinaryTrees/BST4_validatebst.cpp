#include<iostream>
using namespace std;
  
  struct TreeNode {
      int val = INT64_MIN;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool inorder(TreeNode* root, int &store, int &c){
        if(!root) return true;
        bool left = inorder(root->left, store,c);
        if(c!=0 && store >= root->val ){
            return false;
        }
        else{
            c++;
            store = root->val;
        }
        bool right = inorder(root->right, store,c);

        if(left==false || right == false) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        int store;
        int c = 0;
        return inorder(root,store,c);
    }
};