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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        // if(root->val < p->val && root->val < q->val){
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // else if(root->val > p->val && root->val > q->val){
        //     return lowestCommonAncestor(root->left, p, q);
        // }
        // return root;

        while(root){
            if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else if(root->val > p->val && root->val > q->val){
                 root = root->left;
            }
            else{
                return root;
            }
        }
        return nullptr;
    }
};