/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int totalSum=0, maxLevel=0;
    bool isLeafNode(TreeNode* root){
        if(root->left == NULL && root->right == NULL) 
            return true; 
        return false; 
    }
    
    void dfs(TreeNode *root, int level){
         
        if(root == NULL){
            return;
        }
        if (level>maxLevel){
            maxLevel = level; 
            totalSum = root->val;
        }
        else if(level == maxLevel){
            totalSum+=root->val;
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
         return totalSum; 

    }
    
};