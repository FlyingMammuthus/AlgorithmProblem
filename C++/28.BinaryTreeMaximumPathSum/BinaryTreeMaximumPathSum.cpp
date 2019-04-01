class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ret = root->val;
        maxRootPath(root, ret);
        return ret;
    }
    
    int maxRootPath(TreeNode *root, int &max_pre) {
        if (root == NULL) {
            return 0;
        }
        int l_max = maxRootPath(root->left, max_pre),
        r_max = maxRootPath(root->right, max_pre);
        int sum_pre = l_max + r_max + root->val;
        if (max_pre < sum_pre){
            max_pre = sum_pre;
        }
        return max(max(l_max, r_max)+root->val, 0);
    }
};
