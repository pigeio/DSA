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
    bool checkTree(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);
        int sum = 0;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                sum += curr->left->val;
            }
            if(curr->right){
                sum += curr->right->val;
            }
        }

        if(root->val == sum){
            return true;
        }
        return false;


    }
};