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
    int findleft(TreeNode* node){
        int hght=0;
        while(node){
            hght++;
            node=node->left;
        }
        return hght;
    }
    int findright(TreeNode* node){
        int hght=0;
        while(node){
            hght++;
            node=node->right;
        }
        return hght;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=findleft(root);
        int rh=findright(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};