#include <stdio.h>

// 单链表
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){  // head是一个链表
        // 删除头结点，链表头指针为空的即为头节点
        while(head != NULL && head->val == val){    // 链表头指针 head 不为空且头节点的值等于目标值 val。
        //head != NULL: 确保链表没有遍历完，即链表还存在节点。
        //head->val == val: 检查当前头节点的值是否等于目标值 val。
            ListNode* tmp = head;       // 创建一个临时指针 tmp，指向当前要删除的节点（头节点）。
            head = head->next;          // 将头指针 head 指向下一个节点，即将头节点从链表中移除。
            delete tmp;                 // 删除临时指针 tmp 指向的节点，即删除之前的头节点，释放内存空间。
        }

        // 删除非头结点
        ListNode* cur = head;
        while(cur != NULL && cur->next!=NULL){      // 当前链表不为空，且下一个节点也不为空
            if(cur->next->val == val){      // 判断当前节点的下一个节点的值是否等于目标值 val。
                ListNode* tmp = cur->next;  // 创建一个临时指针 tmp，指向当前节点的下一个节点（即要删除的节点）。
                cur->next = cur->next->next;    //  将当前节点的 next 指针指向下下个节点，即将当前节点的下一个节点从链表中移除。
                delete tmp;     //  将当前节点的 next 指针指向下下个节点，即将当前节点的下一个节点从链表中移除。
            }
            else{
                cur = cur->next;
            }
        }
        return head;
    }
};
/*
在上述代码中，使用 tmp 是为了暂时保存要删除的节点，然后再将其从链表中移除。
这样做的原因是，在删除节点时，我们需要确保不丢失对链表的访问，否则会导致内存泄漏或者对链表操作出现错误。

假设不使用 tmp，直接将 cur->next 赋值为 cur->next->next，
然后删除 cur->next 节点。这样会导致链表中断，丢失了对下一个节点的指针，
而且在删除节点后无法继续遍历下一个节点，因为 cur->next 已经被修改了。

使用 tmp 可以避免这种情况，它临时保存了要删除的节点，
*** 并且从内存中将原有赋值过的变量占用的内存地址清空 ***
然后再删除，不会影响链表的连续性和对链表的遍历操作。
*/

// 设置一个虚拟头结点再移除节点操作
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
            head = dummyHead->next;
            delete dummyHead;
            return head;
        }
    }
};



// 2024-2-22 手动实现
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val){
        // 新建一个虚拟头结点
        ListNode* dummyHead = new ListNode(0);
        // 将虚拟头结点接入原链表首位
        dummyHead->next = head;
        // 新建一个链表 current
        ListNode* cur = dummyHead;
        // 循环查找至链表末尾
        while(cur->next != NULL){
            // 若下一个结点的值为目标值
            if(cur->next->val == val)
            {
                // 先将下一个结点的地址取出，便于后续删除
                ListNode* tmp = cur->next;
                // 将当前结点续到下下个结点
                cur->next = cur->next->next;
                // 释放已删除结点的内存空间
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        // 删除虚拟头结点
        head = dummyHead->next;
        // 释放虚拟头结点内存空间
        delete dummyHead;
        // 返回链表
        return head;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val){
        // 新建一个虚拟头结点
        ListNode* dummyHead = new ListNode(5);
        // 将虚拟头结点接入原链表首位
        dummyHead->next = head;
        // 新建一个链表 current
        ListNode* cur = dummyHead;
        // 循环查找至链表末尾
        while(cur->next != nullptr){
            // 若下一个结点的值为目标值
            if(cur->next->val == val){
                // 先将下一个结点的地址取出，便于后续删除
                ListNode* tmp = cur->next;
                // 将当前结点续到下下个结点
                cur->next = cur->next->next;
                // 释放已删除结点的内存空间
                delete tmp;
            }
            else{
                //若下一结点不为目标值
                cur = cur->next;
            }
        }
        // 删除虚拟头结点
        head = dummyHead->next;
        // 释放虚拟头结点内存空间
        delete dummyHead;
        // 返回链表
        return head;
    }
};
