class Solution {
public:
    void t(TreeNode *root,set<int> &a){
        if(!root) return ; 
        //pre-order traversal
        a.insert(root->val);
        t(root->left,a);
        t(root->right,a);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        set<int> a;
        t(root,a);
        if(a.size()==1) return -1;
        
        return *(++a.begin()); // returning second element from set
    }
};
