/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* , TreeNode*>parent;
    void inOrder(TreeNode* root){
        if(!root)return;

        if(root->left != NULL){
            parent[root->left] = root;
            inOrder(root->left);
        }
        if(root->right != NULL){
            parent[root->right] = root;
            inOrder(root->right);
        }
    }

    void BFS(TreeNode* target , int k ,  vector<int>& result){
        queue<TreeNode*>q;
        q.push(target);

        unordered_set<int>visited;
        visited.insert(target->val);

        while(!q.empty()){
            int n = q.size();
            if(k == 0)break;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                
                //left
                if(curr->left && !visited.count(curr->left->val)){
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }

                //right
                if(curr->right && !visited.count(curr->right->val)){
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }

                //parent
                if(parent.count(curr) && !visited.count(parent[curr]->val)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
            
        }
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;
        inOrder(root);
        BFS(target, k , result);
        return result;
    }
};