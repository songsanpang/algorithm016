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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;//判断极端情况
        
        queue<TreeNode*> qu; //初始化bfs
        qu.push(root);
        TreeNode * tmp;

        while(!qu.empty()) { //执行bfs
            int n = qu.size();
            int max = qu.front()->val;
            for(int i =0 ;i < n ; ++i) {
                tmp = qu.front();qu.pop();
                tmp->val > max ? max = tmp->val : max ;
                if(tmp->left) qu.push(tmp->left);
                if(tmp->right) qu.push(tmp->right);
            }
            res.push_back(max);    
        }
        return res;
    }
};