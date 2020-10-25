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
// // 递归法
// class Solution {
// public:
//     void order(Node* root,vector<int>& tmp) {
//         for(auto i : root->children) {
//             if(i) order(i,tmp);
//         }
//         tmp.push_back(root->val);
//     }
//     vector<int> postorder(Node* root) {
//         vector<int> res;
//         if(root) order(root,res);
//         return res;
//     }
// };



//迭代法
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if(root) st.push(root);
        while(!st.empty()) {
            Node* node = st.top();
            if(node != nullptr){
                st.pop();
                st.push(node);
                st.push(nullptr);
                if(node->children.size() != 0){
                    for(auto i =node->children.crbegin();i !=node->children.crend();++i) {
                        if(*i) st.push(*i);
                    }
                }
            }else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};






