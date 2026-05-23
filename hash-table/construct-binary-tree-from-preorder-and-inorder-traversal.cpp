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
    int index=0;
    map<int, int> mpp;
    TreeNode* build(vector<int> &preorder, int start, int end){
        if(start>end) return NULL;
        int val=preorder[index++];
        TreeNode* root=new TreeNode(val);
        int idx=mpp[val];
        root->left=build(preorder, start, idx-1);
        root->right=build(preorder, idx+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder, 0, inorder.size()-1);
    }
};