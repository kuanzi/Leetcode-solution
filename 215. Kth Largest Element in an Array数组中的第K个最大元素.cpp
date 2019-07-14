// 我的答案
// sort and get, nlogn
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>()); // cmp函数。 greater<int>()
        return nums[k-1];
    }
};

// partition，递归写法， 用helper函数去传递范围
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = helper(nums, k, 0, nums.size() - 1);
        return res;
    }
     
	// 为什么要写helper函数呢？因为我们需要l，r变量控制范围，因此findKthLargest不符合的我们的要求
	// 递归写法，都是靠每次调用函数的时候改变的传入的变量值来实现循环的控制
    int helper(vector<int>& nums, int k, int l, int r){
        int pos = partition(nums, l,  r);
        int target = k - 1;  // k-1 not k, index begins from 0;
        if(pos == target){
            return nums[pos];
        }
        else if(pos > target){
            return helper(nums, k, l, pos - 1);
        }
        else{ // if(pos < target)
            return helper(nums, k, pos + 1, r);
        }
    }
    
    int partition(vector<int>& nums, int l, int r){
        int cmp = r;
        int large = l, cur = l;
        for(; cur <= r; ++cur){
            if(nums[cur] > nums[cmp]){
                swap(nums[cur], nums[large++]);
            }
        }
        swap(nums[large], nums[cmp]);  // 此时large的左边是所有大于cmp的元素，交换之后nums[cmp]对应第large-th大的元素
        // cout << large << endl;
        return large;
    }
};

// partition递归写法2：用vector的begin，end的迭代器
class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pos = partition(nums, 0, nums.size() - 1);  // find the pos-th largest element;
        int target = k - 1; // we want the target-th largest element;
        // cout << "target: " << target << endl;
        if(pos == target){
            return nums[pos];
        }
        else if(pos > target){
            // cout << "pos" << pos <<endl;
            vector<int> left(nums.begin(), nums.begin() + pos);   // 创建了新的迭代器，并且用一定范围的nums来初始化，迭代器的操作！
            return findKthLargest(left, k);
        }
        else{
            vector<int> right(nums.begin() + pos + 1, nums.end());
            return findKthLargest(right, target - pos); // target - pos begins from 1 not 0. 因为这个减法表示的是距离
        }
    }
    
    int partition(vector<int>& nums, int l, int r){
        int cmp = r;
        int large = l, cur = l;
        for(; cur <= r; ++cur){
            if(nums[cur] > nums[cmp]){
                swap(nums[cur], nums[large++]);
            }
        }
        swap(nums[large], nums[cmp]);
        // cout << large << endl;
        return large;
    }
};

// partition迭代写法：
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = k - 1; // we want the target-th largest element;
        int l = 0, r = nums.size() - 1;
        int pos = 0;
        while(l <= r){ // 允许l=r，剩余一个元素
            pos = partition(nums, l, r);  // find the pos-th largest element;
            cout << "pos:" << pos << endl;
            if(pos == target){
                break;
            }
            else if (pos > target){
                r = pos - 1;
            }
            else{
                l = pos + 1;
            }
        }
        return nums[pos];
    }
    
    int partition(vector<int>& nums, int l, int r){
        int cmp = r;
        int large = l, cur = l;
        for(; cur <= r; ++cur){
            if(nums[cur] > nums[cmp]){
                swap(nums[cur], nums[large++]);
            }
        }
        swap(nums[large], nums[cmp]);
        cout << large << endl;
        return large;
    }
};


// ======= 大神的答案 ==============
// Solution 1. Sort, O(nlogn).
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

// Solution 2. Partition, O(n).
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi){
            int p = partition(nums, lo, hi);
            if(p == k) break;
            if(p < k) lo = p + 1;
            else hi = p - 1;
        }
        return nums[k];
    }
    
private:
    int partition(vector<int>& nums, int lo, int hi){
        int pivot = nums[hi];    
        int i = lo;
        for(int j = lo; j < hi; j++)
            if(nums[j] <= pivot) swap(nums[i++], nums[j]);
        swap(nums[i], nums[hi]);
        return i;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        int l = 0, r = n - 1;
        while (l <= r) {
            int p = partition(nums, l, r);
            if (p == target) {
                return nums[p];
            } else if (p < target) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
    }
    
     int partition(vector<int>& nums, int l, int r) {
         int i = 0, j = 0;
         while (j != r) {
             if (nums[j] <= nums[r]) {
                 swap(nums[i], nums[j]);
                 ++i;
             }
             ++j;
         }
         swap(nums[i], nums[r]);
         return i;
     }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int pos = partition(nums, n - 1);
        int target = n - k;
        if (pos == target) {
            return nums[pos];
        } else if (pos < target) {
            vector<int>r(nums.begin() + pos + 1, nums.end());
            return findKthLargest(r, k);
        } else {
            vector<int>l(nums.begin(), nums.begin() + pos);
            return findKthLargest(l, k - (n - pos));
        }
    }
    
     int partition(vector<int>& nums, int end) {
         int i = 0, j = 0;
         while (j != end) {
             if (nums[j] < nums[end]) {
                 swap(nums[i], nums[j]);
                 ++i;
             }
             ++j;
         }
         swap(nums[i], nums[end]);
         return i;
     }
};

