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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int InStart , int InEnd , int PostStart , int PostEnd){
        if(InStart > InEnd || PostStart > PostEnd)return NULL;

        TreeNode* root = new TreeNode(postorder[PostEnd]);
        int i = InStart;

        for(;i <=InEnd; i++){
            if(inorder[i] == root->val)break;
        }

        int leftSize = i - InStart;
        int rightSize = InEnd - i;

        root->left = solve(inorder , postorder , InStart , i-1 , PostStart , PostStart+leftSize-1);
        root->right = solve(inorder , postorder , i+1 , InEnd , PostEnd-rightSize , PostEnd-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        int InStart = 0;
        int InEnd = n-1;

        int PostStart = 0;
        int PostEnd = n-1;

        return solve(inorder , postorder , InStart , InEnd , PostStart ,PostEnd);
    }
};