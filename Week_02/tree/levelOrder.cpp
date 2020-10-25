/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> qe;
        if(root) qe.push(root);
        while(!qe.empty()) {
            vector<int> tmp;
            int size = qe.size();
            for(int i =0 ;i<size ;++i) {
                Node* node=qe.front();
                tmp.push_back(node->val);
                qe.pop();
                for(auto i = node->children.begin() ; i!=node->children.end() ;++i) {
                    if(*i) qe.push(*i);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};


























