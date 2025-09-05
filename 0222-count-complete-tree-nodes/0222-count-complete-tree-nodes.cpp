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
    int getLeftHeight(TreeNode* root){
        TreeNode* temp = root;
        int left_height = 0;

        while(temp){
            temp = temp->left;
            left_height++;
        }
        return left_height;
    }

    int getRightHeight(TreeNode* root){
        TreeNode* temp = root;
        int right_height = 0;

        while(temp){
            temp = temp->right;
            right_height++;
        }
        return right_height;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int left_height = getLeftHeight(root);
        int right_height = getRightHeight(root);

        if(left_height == right_height){
            return (pow(2,left_height) - 1);
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};