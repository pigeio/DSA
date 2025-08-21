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
    void find(TreeNode* root, vector<vector<int>>& result){
        if(root == NULL)return;

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        vector<int>level;
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL){
                result.push_back(level);
                level.clear();

                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        find(root , result);
        return result;
    }
};