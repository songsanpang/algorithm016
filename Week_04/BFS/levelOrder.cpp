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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;//初始条件检查，这么多次了不能忘记
        if (!root) return result;

        deque<TreeNode*> tmp;// 初始化
        tmp.push_back(root);
        int size = tmp.size();

        while (size) {              //BFS
            vector<int> tmp_level;
            while (size) {
                tmp_level.push_back(tmp.front() -> val);
                if(tmp.front() -> left) tmp.push_back(tmp.front() -> left);
                if(tmp.front() -> right) tmp.push_back(tmp.front() -> right);
                tmp.pop_front();
                size --;
            }
            result.push_back(tmp_level);
            size = tmp.size();
        }
        
        return result;
    }
};

















