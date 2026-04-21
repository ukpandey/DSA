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
private: 
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRighttoLeft = lastRight(root->left);
        lastRighttoLeft->right = rightChild;
        return root->left;
    }
    TreeNode* lastRight(TreeNode* root){
        if(root->right == NULL) return root;
        return(root->right);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root!=NULL){

            if(root->val > key){
                if(root->left!=NULL && root->left->val==key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }

            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }

        }
        return dummy;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* current = root;
        while(true){

            if(current->val < val){
                if(current -> right != NULL) current = current->right;
                else{
                    current -> right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(current -> left != NULL) current = current->left;
                else{
                    current -> left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};