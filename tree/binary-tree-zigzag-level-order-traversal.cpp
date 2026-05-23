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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool flag=false;
        queue<TreeNode*> dq;
        vector<vector<int>> ans;
        if(!root) return ans;
        dq.push(root);
        while(!dq.empty()){
            int size=dq.size();
            vector<int> level(size);
            for(int i =0; i<size; i++){
                TreeNode* node=dq.front();
                dq.pop();
                int index=(!flag)? i:size-1-i;
                level[index]=(node->val);
                if(node->left!=NULL){
                    dq.push(node->left);
                }
                if(node->right!=NULL){
                    dq.push(node->right);
                }
            }
            flag=!flag;
            ans.push_back(level);
        }
        return ans;
    }
};