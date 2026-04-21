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
    void traverse(TreeNode* root, int k, int &count, int &ans){
        if(!root) return;
        traverse(root->left,k,count,ans);
        count++;
        if(count==k){
            ans = root->val;
            return;
        }
        traverse(root->right,k,count,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        traverse(root,k,count,ans);
        return ans;
    }
};