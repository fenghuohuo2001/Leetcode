/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 定义链表结点
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

// 采用双指针法，一个cur指针指向头结点，一个pre初始化为NULL
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

// 递归法
class Solution {
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == nullptr) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);   // 移动到下一个结点
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(nullptr, head);
    }

};

// 递归法 当cur为空时，循环结束
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 边缘条件判断
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        // 递归调用，翻转第二个结点开始往后的链表。注意这里有很多层递归调用
        ListNode* last = reverseList(head->next);   
        // 递归函数返回时，当链表结点数量大于等于2时，退出最后一层递归调用时返回的是链表最后一个结点
        
        // 翻转头结点和第二个结点的指向
        head->next->next = head;
        // 此时head结点为尾结点，next需要指向nullptr
        head->next = nullptr;
        return last;
    }
};


class Solution{
public:
    ListNode* reverse(ListNode* pre, ListNode* cur){
        // 检索到末尾
        if(cur == nullptr) return pre;
        // 暂存下一个结点数据
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
    ListNode* resverseList(ListNode* head){
        return reverse(nullptr, head);
    }
};