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
    void solve(TreeNode* root , string path , vector<string>& ans){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
        }

        if(root->left){
            solve(root->left , path + "->" + to_string(root->left->val) , ans);
        }

        if(root->right){
            solve(root->right , path + "->" + to_string(root->right->val) , ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path = to_string(root->val);

        solve(root , path , ans);
        return ans;
    }
};