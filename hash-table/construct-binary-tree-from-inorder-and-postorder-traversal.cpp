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
    int index;
    map<int,int> mpp;
    TreeNode* build(vector<int> postorder, int start, int end){
        if(start>end) return NULL;
        int val=postorder[index--];
        TreeNode* node=new TreeNode(val);
        int pos=mpp[val];
        node->right=build(postorder, pos+1, end);
        node->left=build(postorder, start, pos-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index=postorder.size()-1;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]]=i;
        }
        return build(postorder, 0, inorder.size()-1);
    }
};