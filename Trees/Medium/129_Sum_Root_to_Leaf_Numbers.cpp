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
    
    string s="";
    void t(TreeNode *root, vector<string> &st){
        if(!root) return;
        s += root->val + '0';
        
        t(root->left,st);
        t(root->right,st);
        if(!root->left && !root->right)
            st.push_back(s);
        s.pop_back();
        
    }
    int sumNumbers(TreeNode* root) {
        s="";
        vector<string> st;
        t(root,st);
        int sum = 0;
        for(auto x:st){
            int temp = stoi(x);
            sum+=temp;
        }
        return sum;
    }
};
