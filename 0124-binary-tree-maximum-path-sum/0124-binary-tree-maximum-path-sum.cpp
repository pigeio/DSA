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
    int maxSum;
    int solve(TreeNode* root){
        if(root == NULL)return 0;

        int left_h = solve(root->left);
        int right_h = solve(root->right);

        int sumInHalfCircle = left_h + right_h + root->val;

        int half_L_R = max(left_h,  right_h) + root->val;
        int onlyRoot = root->val;

        maxSum = max({maxSum , sumInHalfCircle , half_L_R , onlyRoot});
        return max(half_L_R , onlyRoot);

    }

    int maxPathSum(TreeNode* root) {
    maxSum = INT_MIN;
    solve(root);
    return maxSum;    
    }
};