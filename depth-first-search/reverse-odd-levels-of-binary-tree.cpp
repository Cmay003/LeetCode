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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool reversed=0;
        while(!q.empty()){
            int size=q.size();
            vector<TreeNode*> arr(size);
            for(int i=0; i<size; i++){
                auto node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(reversed){
                    arr[i]=node;
                    if(i>=size/2){
                        swap(arr[i]->val, arr[size-1-i]->val);
                    }
                }
            }
            reversed=!reversed;
        }
        return root;
    }
};