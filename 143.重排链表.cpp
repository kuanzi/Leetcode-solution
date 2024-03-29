//这道题目非常经典
// 1. 找链表的中间节点
// 2. 翻转链表
// 3. 链表的合并

// Tip：
// Q: 判断空的时候应该怎么判断？
// A: 当要赋值指针的时候，ListNode* tmp = cur->next，一定要判断cur->next指针是否为空；cur->next = pre的时候应该判断cur是否为空，如果为空就没有next，则有member access within null pointer of type 'struct ListNode'
// 
// Q: 同样都是ListNode类型的指针，为什么一定要 new。因为如果不new，ListNode* pre是个空指针，new一下之后这个指针会指向new出来的空间的地址，也就是指针非空 。只有非空指针才有next指针，否则就是调用了 null->next，这个是不允许的，
// https://www.runoob.com/cplusplus/cpp-constructor-destructor.html，new的重点在于分配空间，类的实例化是一定要用到构造函数的

// 最终答案

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNode1{
public:
    ListNode1(int x): val(x), next(NULL){}
private:
    int val;
    ListNode1* next;
}; //class 之后有分号！

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        
        // divide the linklist
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = new ListNode(0); // 如果pre是个空节点，member access within null pointer of type 'struct ListNode'
        pre->next = slow; // 忘了赋值给pre了
		// 因为循环里面有fast->next->next的情况，所以要判断fast->next是否为空，但是fast如果为空，fast->next就不存在，因此需要先判断fast，如为空则短路
        while(fast && fast->next){
            pre = pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 1,2,3 fast=null; slow=2;
        // 1,2,3,4 fast=4; slow=2;
        if(fast) pre = pre->next, slow = slow->next;
        pre->next = NULL;
        
        // reverse the tail linklist
        ListNode* cur = slow;
        // ListNode* pre = NULL; // redeclaration
        pre = NULL;
        ListNode* next;
        while(cur){ // 停止的时候cur会在null位置，pre是最后一个节点！
            next = cur->next;
            cur->next = pre;
            pre = cur; //忘记了分号
            cur = next;
        }
        
        // merge the two lists
        ListNode* list1 = head;
        // ListNode* list2 = slow; 
        ListNode* list2 = pre; // 使用pre代表last list的第一个节点！！！！！
        ListNode* tmp1, *tmp2;
        while(list1 && list2){
            tmp1 = list1->next;
            tmp2 = list2->next;
            list1->next = list2;
            list2->next = tmp1;
            list1 = tmp1;
            list2 = tmp2;
        }
            
    }
};


// fengvyi大神的答案；
// zs 答案：https://leetcode.com/problems/reorder-list/discuss/45013/clear-c-o1-space-solution
/* Suppose we have a list [1,2,3,4,5,6,7]

Steps as follow:

Divide the list into front list: [1,2,3,4] and tail list: [5,6,7]
Reverse the tail list to [7,6,5]
Join front and tail list,
   1      ->2      ->3      ->4
     ->7       ->6      ->5
Result: [1,7,2,6,3,5,4]
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* slow = head, *fast = head;
        ListNode* pre = new ListNode(0);
        pre->next = slow;
        while(fast && fast->next){
            pre = pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next, pre = pre->next;
        pre->next = NULL;
        ListNode* cur, *next;
        pre = NULL, cur = slow;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode* h1 = head, *h2 = pre, *p1, *p2;
        while(h1 && h2){
            p1 = h1->next;
            p2 = h2->next;
            h1->next = h2;
            h2->next = p1;
            h1 = p1;
            h2 = p2;
        }
    }
};