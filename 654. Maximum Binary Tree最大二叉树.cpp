// 知识点：vector的基本操作
// 1 基本操作

(1)头文件#include<vector>.

(2)创建vector对象，vector<int> vec;

(3)尾部插入数字：vec.push_back(a);

(4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。

(5)使用迭代器访问元素.

    

<span style="font-size:18px;">vector<int>::iterator it;
for(it=vec.begin();it!=vec.end();it++)
    cout<<*it<<endl;</span>

(6)插入元素：    vec.insert(vec.begin()+i,a);在第i个元素后面插入a;

(7)删除元素：    vec.erase(vec.begin()+2);删除第3个元素

　　　　　　　 vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始

(8)向量大小:vec.size();

(9)清空:vec.clear()　　　//清空之后，vec.size()为０
--------------------- 
作者：L未若 
来源：CSDN 
原文：https://blog.csdn.net/msdnwolaile/article/details/52708144 
版权声明：本文为博主原创文章，转载请附上博文链接！

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