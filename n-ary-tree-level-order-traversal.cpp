// question link - https://leetcode.com/problems/n-ary-tree-level-order-traversal/submissions/
// used dfs
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
    int index = 0;
    map<int, vector<int>> omap;
    void travserse(Node* root) {
        if(root == NULL) {
            return ;
        }
        omap[index].push_back(root->val);
        index++;
        for(int i=0; i<root->children.size(); i++) {
            travserse(root->children[i]);
            index--;
        }
    }
    
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        travserse(root);
        
        for(auto it=omap.begin(); it!=omap.end(); it++) {
            // cout<<it->first<<"  = ";
            
//             for(int i=0; i<it->second.size(); i++) {
//                 cout<<it->second[i]<<" ";
//             }cout<<endl;
            res.push_back(it->second);
        }
        return res;
    }
};