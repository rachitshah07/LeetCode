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
    vector<int> c;
    void t(TreeNode *root,vector<vector<int>> &a){
        if(!root) return;
        c.push_back(root->val);
        t(root->left,a);
        t(root->right,a);
        if(!root->right && !root->left)
        a.push_back(c);
        c.pop_back();
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> s;
       vector<vector<int>>a;
        t(root,a);
        
        for(auto x:a){
            string st;
            int n=x.size();
            n--;
            for(auto j:x){
                st += to_string(j);
                if(n) st+="->";
                n--;
            }
            s.push_back(st);
            // cout<<endl;
        }
        return s;
        
    }
};
