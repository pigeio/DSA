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
    int height(TreeNode* root){
        if(root == NULL)return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);

        return max(leftH , rightH) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)return 0;

        int leftH = diameterOfBinaryTree(root->left);
        int rightH = diameterOfBinaryTree(root->right);

        int L = max(leftH , rightH);
        int R = max(leftH , rightH); 

        int curr_H = height(root->left) + height(root->right);

        return max(leftH , max(rightH , curr_H));
    }
};