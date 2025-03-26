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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    void solve(TreeNode* root){
        if(root == NULL){
            return ;
        }
        solve(root->left);
        
        if(prev != NULL && prev->val > root->val){
            if(first == NULL){
                first = prev;
            }
            
            second = root;
        }
        prev = root;

        solve(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        if(first != NULL && second != NULL){
            swap(first->val, second->val);
        }
    }
};