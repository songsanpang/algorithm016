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
    bool isValidBST(struct TreeNode* root){
        if(root==NULL) return true;
        bool flag = false;
        bool flagLeft = true;
        bool flagRight = true;

        struct TreeNode* leftNode = root->left;
        struct TreeNode* rightNode = root->right;
        if(leftNode) {
            while(leftNode->right) {  // 左子树找最右孩子，即左子树的最大值
                leftNode = leftNode->right;
            }
            flagLeft = leftNode->val < root->val;
        }
        if(rightNode) {     // 右子树找最左孩子，即右子树的最小值
            while(rightNode->left) {
                rightNode = rightNode->left;
            }    
            flagRight = rightNode->val > root->val;
        }

        if(root->left && root->right) {
            flag = (root->val > root->left->val) && (root->val < root->right->val);
        } else if(root->left) {
            flag = (root->val > root->left->val);
        } else if(root->right) {
            flag = (root->val < root->right->val);
        } else flag = true;

        return flag && flagRight && flagLeft && isValidBST(root->left) && isValidBST(root->right);        
    }
};