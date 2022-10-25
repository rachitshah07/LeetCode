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
    string s="";
    void t(TreeNode *root,set<string> &st){
        if(!root) return;
        s+= root->val + 'a';
        t(root->left,st);
        t(root->right,st);
        if(!root->left && !root->right){
            string temp = s;
            reverse(temp.begin(),temp.end());
            st.insert(temp);
        }
        s.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        s="";
        set<string>st;
        t(root,st);
        return *st.begin();
    }
};
