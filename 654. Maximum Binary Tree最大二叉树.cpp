// 我的代码：
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return NULL;
        // TreeNode* res = DFS(nums, 0, nums.size());  // vector length -> .size() func;
        TreeNode* res = DFS(nums, 0, nums.size());
        return res;
    }
    
    TreeNode* DFS(vector<int>& nums, int l, int r){
        // if(!num) return NULL; //这里不对，nums大小是不变的，只有lr标识的范围变化
        if(l==r) return NULL;
        int max_pos =l;
        for(int i = l; i < r; i++){ //因为这边i<r，已经考虑了边界问题了。
            if(nums[i] > nums[max_pos]) max_pos = i;
        }
        
        TreeNode* root = new TreeNode(nums[max_pos]);
        // if(max_pos > l) root->left = DFS(nums, l, max_pos - 1); // 这边不能-1
        if(max_pos > l) root->left = DFS(nums, l, max_pos);
        if(max_pos < r) root->right = DFS(nums, max_pos + 1, r);
        
        return root;
    }
};


// 大神代码：
// https://leetcode.com/problems/maximum-binary-tree/discuss/106158/8-lines-c-recursion
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return DFS(nums, 0, nums.size());
    }
    
    TreeNode* DFS(vector<int>& nums, int l, int r){
        if(l == r) return NULL;
        int maxPos = l;
        for(int i = l; i < r; i++) if(nums[i] > nums[maxPos]) maxPos = i;
        TreeNode* root = new TreeNode(nums[maxPos]);
        root->left = DFS(nums, l, maxPos);
        root->right = DFS(nums, maxPos + 1, r);
        return root;
    }
};