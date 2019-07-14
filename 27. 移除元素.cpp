// Remove Elemet: https://leetcode.com/problems/remove-element/
// Linked List Cycle: https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
// Reverse a LinkedList (Reverse it in-place and in one-pass): https://www.geeksforgeeks.org/reverse-a-linked-list/ 
// Rotate List: https://leetcode.com/problems/rotate-list/
// Reorder List: https://leetcode.com/problems/reorder-list/

// Valid Parentheses: https://leetcode.com/problems/valid-parentheses/
// Traversal: https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

// Heap: 
// https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/
// https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/
// https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/


// 27. 移除元素
// Remove Elemet
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, remain = 0;
        for(; i < nums.size(); ++i){
            if(nums[i] != val){
                nums[remain++] = nums[i];
            }
        }
        return remain;
    }
};


// 141. 环形链表
// 经典题解：https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
//环形链表： 链表，哈希表和双指针。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// two pointer, fast & slow
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};

// hashmap
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> node_set;
        ListNode* cur =  head;
        while(cur){
            // 'node_set.std::unordered_set<ListNode*>::find(cur)' 返回'std::unordered_set<ListNode*>::iterator'
            // std::unordered_set<std::string>::const_iterator got = myset.find (input); 
            // std::cout << *got << " is in myset";
            // if(node_set.find(cur)){
            if(node_set.find(cur) != node_set.end()){ // 找到了
                return true;
            }
            node_set.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};

// 完整代码
// C++ program to detect loop in a linked list 
#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
// 头部插入节点
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = new Node; 
  
    /* put in the data  */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  // head_ref 头结点的指针，头结点是Node*类型。(*head_ref)即头结点
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
  
// Returns true if there is a loop in linked list 
// else returns false. 
bool detectLoop(struct Node* h) 
{ 
    unordered_set<Node*> s; 
    while (h != NULL) { 
        // If this node is already present 
        // in hashmap it means there is a cycle 
        // (Because you we encountering the 
        // node for the second time). 
        if (s.find(h) != s.end()) 
            return true; 
  
        // If we are seeing the node for 
        // the first time, insert it in hash 
        s.insert(h); 
  
        h = h->next; 
    } 
  
    return false; 
} 
  
/* Drier program to test above function*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
  
    /* Create a loop for testing */
    head->next->next->next->next = head; 
  
    if (detectLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
  
    return 0; 
} 
// This code is contributed by Geetanjali 



// 206. 反转链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* pre = new ListNode(0);
        // pre->next = head;
        ListNode* cur = head;
        ListNode* pre;
        pre = NULL;
        ListNode* next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};


//61. 旋转链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return head;
        
        int cnt = 1;
        ListNode* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
            cnt++;
        }
        k = cnt - k % cnt;    
        tmp->next = head; //concate
         
        ListNode* h1 = head;
        ListNode* h2;
        for(int i = 0; h1 && h1->next && i < k - 1; i++){
            h1 = h1->next;
        }
        h2 = h1->next;
        h1->next = NULL;
        
        return h2;
    }
};

// Using C++ 取模，结环再断开
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)
            return head;
        ListNode *q=head;
        int len=1;
        while(q->next){
            len++;
            q=q->next;//q为最后一个节点
        }
        ListNode *p=q;
        q->next=head;//结环
        for(int i=0;i<len-k%len;i++)
            p=p->next;
        head=p->next;
        p->next=NULL;//断开
        return head;
    }
};

// 作者：crunch
// 链接：https://leetcode-cn.com/problems/two-sum/solution/using-c-qu-mo-jie-huan-zai-duan-kai-by-crunch/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
