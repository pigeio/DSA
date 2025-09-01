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
    int widthOfBinaryTree(TreeNode* root) {
        

        queue<pair<TreeNode*, long long>>q;
        q.push({root , 0});
        long long length = 0;

        while(!q.empty()){
            int n = q.size();
            long long start = q.front().second;
            long long end = q.back().second;

            length = max(length , end-start+1);

            while(n--){
                TreeNode* curr = q.front().first;
                long long idx = q.front().second - start;
                q.pop();

                if(curr->left){
                    q.push({curr->left, 2*idx+1});
                }

                if(curr->right){
                    q.push({curr->right , 2*idx+2});
                }
            }
        }
        return (int)length;
    }
};